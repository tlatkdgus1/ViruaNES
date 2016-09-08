//
// エミュレータスレッドクラス
//
#include "DebugOut.h"

#include "VirtuaNESres.h"
#include "EmuThread.h"

#include "NetPlay.h"

#include "DirectDraw.h"
#include "DirectSound.h"
#include "DirectInput.h"

// 自分自身
CEmuThread	Emu;

// Thisポインタ
CEmuThread*	CEmuThread::g_pThis = NULL;
// ウインドウハンドル
HWND	CEmuThread::g_hWnd = NULL;
// エミュレータオブジェクトポインタ
NES*	CEmuThread::g_nes = NULL;
// WAVEレコーダ
CWaveRec CEmuThread::g_WaveRec;

// ステータス
INT	CEmuThread::g_Status = CEmuThread::STATUS_NONE;
// スレッドイベントとイベントハンドル
INT	CEmuThread::g_Event = CEmuThread::EV_NONE;
LONG	CEmuThread::g_EventParam = 0;
LONG	CEmuThread::g_EventParam2 = 0;
HANDLE	CEmuThread::g_hEvent = NULL;
HANDLE	CEmuThread::g_hEventAccept = NULL;

// エラーメッセージ
CHAR	CEmuThread::g_szErrorMessage[512];

// ストリングテーブル
LPCSTR	CEmuThread::g_lpSoundMuteStringTable[] = {
	"Master ",
	"Rectangle 1",
	"Rectangle 2",
	"Triangle ",
	"Noise ",
	"DPCM ",
	"Ex CH1 ",
	"Ex CH2 ",
	"Ex CH3 ",
	"Ex CH4 ",
	"Ex CH5 ",
	"Ex CH6 ",
	"Ex CH7 ",
	"Ex CH8 ",
	NULL,
	NULL,
};

// スレッドプライオリティテーブル
INT	CEmuThread::g_PriorityTable[] = {
	THREAD_PRIORITY_IDLE,
	THREAD_PRIORITY_LOWEST,
	THREAD_PRIORITY_BELOW_NORMAL,
	THREAD_PRIORITY_NORMAL,
	THREAD_PRIORITY_ABOVE_NORMAL,
	THREAD_PRIORITY_HIGHEST,
	THREAD_PRIORITY_TIME_CRITICAL
};

CEmuThread::CEmuThread()
{
	g_pThis = this;

	m_hThread = NULL;
	g_Status = STATUS_NONE;
	m_nPriority = 3;	// Normal
	g_nes = NULL;
	m_nPauseCount = 0;
}

CEmuThread::~CEmuThread()
{
	Stop();
}

void	CEmuThread::SetPriority( INT nPriority )
{
	m_nPriority = nPriority;
	if( IsRunning() ) {
		::SetThreadPriority( m_hThread, g_PriorityTable[m_nPriority] );
	}
}

BOOL	CEmuThread::Start( HWND hWnd, NES* nes )
{
	Stop();

	if( !g_hEvent ) {
		if( !(g_hEvent = ::CreateEvent( NULL, FALSE, FALSE, NULL )) ) {
			DEBUGOUT( "CreateEvent failed.\n" );
			goto	_Start_Failed;
		}
	}
	if( !g_hEventAccept ) {
		if( !(g_hEventAccept = ::CreateEvent( NULL, FALSE, FALSE, NULL )) ) {
			DEBUGOUT( "CreateEvent failed.\n" );
			goto	_Start_Failed;
		}
	}

	::ResetEvent( g_hEvent );
	::ResetEvent( g_hEventAccept );

	g_hWnd = hWnd;
	g_nes = nes;
	g_Event = EV_INITIAL;
	g_Status = STATUS_NONE;
	::SetEvent( g_hEvent );
	m_nPauseCount = 0;

	if( !(m_hThread = ::CreateThread( NULL, 0, ThreadProc, 0, 0, &m_dwThreadID )) ) {
		DEBUGOUT( "CreateThread failed.\n" );
		goto	_Start_Failed;
	}

	// スレッドプライオリティの設定
	::SetThreadPriority( m_hThread, g_PriorityTable[m_nPriority] );

	// ちゃんと起動できたか確認の為イベントを待つ
	::WaitForSingleObject( g_hEventAccept, INFINITE );
	g_Status = STATUS_RUN;

//	DEBUGOUT( "CEmuThread:Start() Thread started.\n" );
	return	TRUE;

_Start_Failed:
	CLOSEHANDLE( g_hEvent );
	CLOSEHANDLE( g_hEventAccept );

	DEBUGOUT( "CEmuThread:Start() Thread startup failed!!." );
	return	FALSE;
}

void	CEmuThread::Stop()
{
	if( IsRunning() ) {
		::ResetEvent( g_hEventAccept );

		g_Event = EV_EXIT;
		::SetEvent( g_hEvent );

		::WaitForSingleObject( m_hThread, INFINITE );
		CLOSEHANDLE( m_hThread );
		m_hThread = NULL;
		g_Status = STATUS_NONE;

		CLOSEHANDLE( g_hEvent );
		CLOSEHANDLE( g_hEventAccept );

		// ネットプレイ時の切断処理
		NetPlay.Disconnect();

//		DEBUGOUT( "CEmuThread::Stop() Thread stoped.\n" );
	}
}

void	CEmuThread::Pause()
{
	if( IsRunning() ) {
		if( !IsPausing() ) {
			::ResetEvent( g_hEventAccept );
			g_Event = EV_PAUSE;
			::SetEvent( g_hEvent );
			::WaitForSingleObject( g_hEventAccept, INFINITE );
			g_Status = STATUS_PAUSE;
			m_nPauseCount++;
		} else {
			m_nPauseCount++;
		}
//		DEBUGOUT( "CEmuThread::Pause() Thread paused. Count=%d\n", m_nPauseCount );
	}
}

void	CEmuThread::Resume()
{
	if( IsRunning() ) {
		if( IsPausing() ) {
			if( --m_nPauseCount <= 0 ) {
				m_nPauseCount = 0;
				::ResetEvent( g_hEventAccept );
				g_Event = EV_RESUME;
				::SetEvent( g_hEvent );
				::WaitForSingleObject( g_hEventAccept, INFINITE );
				g_Status = STATUS_RUN;
			}
		}
//		DEBUGOUT( "CEmuThread::Resume() Thread resumed. Count=%d\n", m_nPauseCount );
	}
}

void	CEmuThread::Event( EMUEVENT ev )
{
	if( IsRunning() ) {
		::ResetEvent( g_hEventAccept );
		g_Event = ev;
		g_EventParam = 0;
		g_EventParam2 = -1;
		::SetEvent( g_hEvent );
		::WaitForSingleObject( g_hEventAccept, INFINITE );
	}
}

void	CEmuThread::EventParam( EMUEVENT ev, LONG param )
{
	if( IsRunning() ) {
		::ResetEvent( g_hEventAccept );
		g_Event = ev;
		g_EventParam = param;
		g_EventParam2 = -1;
		::SetEvent( g_hEvent );
		::WaitForSingleObject( g_hEventAccept, INFINITE );
	}
}

void	CEmuThread::EventParam2( EMUEVENT ev, LONG param, LONG param2 )
{
	if( IsRunning() ) {
		::ResetEvent( g_hEventAccept );
		g_Event = ev;
		g_EventParam = param;
		g_EventParam2 = param2;
		::SetEvent( g_hEvent );
		::WaitForSingleObject( g_hEventAccept, INFINITE );
	}
}

void	CEmuThread::NetPlayDiskCommand( BYTE cmd )
{
	switch( cmd ) {
		case	0xF8: // Eject
			if( g_nes->rom->GetDiskNo() > 0 ) {
				g_nes->Command( NES::NESCMD_DISK_EJECT );
				DirectDraw.SetMessageString( "Disk Eject." );
			}
			break;
		case	0xF9: // Disk0 SideA
			if( g_nes->rom->GetDiskNo() > 0 ) {
				g_nes->Command( NES::NESCMD_DISK_0A );
				DirectDraw.SetMessageString( "Change Disk1 SideA." );
			}
			break;
		case	0xFA: // Disk0 SideB
			if( g_nes->rom->GetDiskNo() > 1 ) {
				g_nes->Command( NES::NESCMD_DISK_0B );
				DirectDraw.SetMessageString( "Change Disk1 SideB." );
			}
			break;
		case	0xFB: // Disk1 SideA
			if( g_nes->rom->GetDiskNo() > 2 ) {
				g_nes->Command( NES::NESCMD_DISK_1A );
				DirectDraw.SetMessageString( "Change Disk2 SideA." );
			}
			break;
		case	0xFC: // Disk1 SideB
			if( g_nes->rom->GetDiskNo() > 3 ) {
				g_nes->Command( NES::NESCMD_DISK_1B );
				DirectDraw.SetMessageString( "Change Disk2 SideB." );
			}
			break;
	}
}

DWORD WINAPI CEmuThread::ThreadProc( LPVOID lpParam )
{
INT	i;
INT	Ev;
LONG	Param, Param2;
BOOL	bLoop = TRUE;
BOOL	bPause = FALSE;		// Thread pause
BOOL	bEmuPause = FALSE;	// Emulation pause
BOOL	bThrottle = FALSE;	// Emulation throttle
INT	nFrameSkip = 0;		// Emulation frameskip
BOOL	bOneStep = FALSE;	// Emulation one step

INT	NetPlay_Ev = EV_NONE;
LONG	NetPlay_Param = 0;

LONG	fliptime;
INT	frameskipno;
INT	now_time;
INT	dropframe = 0;
FLOAT	frame_period;
DWORD	old_time = 0;
FLOAT	last_frame_time = 0.0f;

// NetPlay
INT	nNetSyncStep = 0;
DWORD	dwNetSyncData = 0;

// FPS
INT	nFrameCount = 0;
DWORD	dwFrameTime[32];

CHAR	szStr[256];

	while( bLoop ) {
		try {
			bOneStep = FALSE;

			Ev = EV_NONE;
			if( WAIT_OBJECT_0 == ::WaitForSingleObject(g_hEvent,0) ) {
				Ev = g_Event;
				Param = g_EventParam;
				Param2 = g_EventParam2;
			}

			switch( Ev ) {
				case	EV_NONE:
					break;
				case	EV_INITIAL:
					DirectDraw.SetMessageString( "Emulation start." );
					DirectSound.StreamPlay();
					last_frame_time = 0.0f;
					old_time = ::timeGetTime();
					::SetEvent( g_hEventAccept );
					break;
				case	EV_EXIT:
					DirectSound.StreamStop();
					bLoop = FALSE;
					return	0;
				case	EV_PAUSE:
					DirectSound.StreamPause();
					bPause = TRUE;
					::SetEvent( g_hEventAccept );
					break;
				case	EV_RESUME:
					if( !bEmuPause )
						DirectSound.StreamResume();
					last_frame_time = 0.0f;
					old_time = ::timeGetTime();
					bPause = FALSE;
					::SetEvent( g_hEventAccept );
					break;
				case	EV_FULLSCREEN_GDI:
					DirectDraw.SetFullScreenGDI( (BOOL)Param );
					::SetEvent( g_hEventAccept );
					break;

				case	EV_HWRESET:
					if( g_nes ) {
						if( !NetPlay.IsConnect() ) {
							if( !g_nes->IsMoviePlay() ) {
								g_nes->Command( NES::NESCMD_HWRESET );
								DirectDraw.SetMessageString( "Hardware reset." );
							}
						} else {
							NetPlay_Ev = Ev;
						}
					}
					::SetEvent( g_hEventAccept );
					break;
				case	EV_SWRESET:
					if( g_nes ) {
						if( !NetPlay.IsConnect() ) {
							if( !g_nes->IsMoviePlay() ) {
								g_nes->Command( NES::NESCMD_SWRESET );
								DirectDraw.SetMessageString( "Software reset." );
							}
						} else {
							NetPlay_Ev = Ev;
						}
					}
					::SetEvent( g_hEventAccept );
					break;

				case	EV_NETPLAY_START:
					if( g_nes ) {
						// 一応
						g_nes->MovieStop();

						g_nes->Command( NES::NESCMD_HWRESET );
						DirectDraw.SetMessageString( "Netplay start!" );
					}
					bThrottle = FALSE;
					nFrameSkip = 0;
					nNetSyncStep = 0;
					dropframe = 0;
					::SetEvent( g_hEventAccept );
					break;

				case	EV_EMUPAUSE:
					bEmuPause = !bEmuPause;
					if( bEmuPause ) {
						DirectSound.StreamPause();
					} else if( !bPause ) {
						DirectSound.StreamResume();
					}
					DirectDraw.SetMessageString( "Pause." );
					::SetEvent( g_hEventAccept );
					break;

				case	EV_ONEFRAME:
					bEmuPause = TRUE;
					DirectSound.StreamPause();
					bOneStep = TRUE;
					DirectDraw.SetMessageString( "One Frame." );
					::SetEvent( g_hEventAccept );
					break;

				case	EV_THROTTLE:
					if( !NetPlay.IsConnect() ) {
						bThrottle = !bThrottle;
						DirectDraw.SetMessageString( "Throttle." );
					}
					::SetEvent( g_hEventAccept );
					break;

				case	EV_FRAMESKIP_AUTO:
					if( !NetPlay.IsConnect() ) {
						DirectDraw.SetMessageString( "FrameSkip Auto." );
						nFrameSkip = 0;
					}
					::SetEvent( g_hEventAccept );
					break;
				case	EV_FRAMESKIP_UP:
					if( !NetPlay.IsConnect() ) {
						if( nFrameSkip < 20 )
							nFrameSkip++;
						::wsprintf( szStr, "FrameSkip %d", nFrameSkip );
						DirectDraw.SetMessageString( szStr );
					}
					::SetEvent( g_hEventAccept );
					break;
				case	EV_FRAMESKIP_DOWN:
					if( !NetPlay.IsConnect() ) {
						if( nFrameSkip )
							nFrameSkip--;
						if( nFrameSkip ) {
							::wsprintf( szStr, "FrameSkip %d", nFrameSkip );
							DirectDraw.SetMessageString( szStr );
						} else {
							DirectDraw.SetMessageString( "FrameSkip Auto." );
						}
					}
					::SetEvent( g_hEventAccept );
					break;

				case	EV_STATE_LOAD:
					if( g_nes ) {
						if( !NetPlay.IsConnect() ) {
							if( g_nes->LoadState( (const char*)Param ) ) {
								if( Param2 < 0 )
									::wsprintf( szStr, "State Load." );
								else
									::wsprintf( szStr, "State Load #%d", Param2 );
								DirectDraw.SetMessageString( szStr );
							}
						}
					}
					::SetEvent( g_hEventAccept );
					break;
				case	EV_STATE_SAVE:
					if( g_nes ) {
						if( !NetPlay.IsConnect() ) {
							if( g_nes->SaveState( (const char*)Param ) ) {
								if( Param2 < 0 )
									::wsprintf( szStr, "State Save." );
								else
									::wsprintf( szStr, "State Save #%d", Param2 );
								DirectDraw.SetMessageString( szStr );
							}
						}
					}
					::SetEvent( g_hEventAccept );
					break;

				case	EV_DISK_COMMAND:
					if( g_nes ) {
						if( !NetPlay.IsConnect() ) {
							switch( Param ) {
								case	0: // Eject
									if( g_nes->rom->GetDiskNo() > 0 ) {
										g_nes->Command( NES::NESCMD_DISK_EJECT );
										DirectDraw.SetMessageString( "Disk Eject." );
									}
									break;
								case	1: // Disk0 SideA
									if( g_nes->rom->GetDiskNo() > 0 ) {
										g_nes->Command( NES::NESCMD_DISK_0A );
										DirectDraw.SetMessageString( "Change Disk1 SideA." );
									}
									break;
								case	2: // Disk0 SideB
									if( g_nes->rom->GetDiskNo() > 1 ) {
										g_nes->Command( NES::NESCMD_DISK_0B );
										DirectDraw.SetMessageString( "Change Disk1 SideB." );
									}
									break;
								case	3: // Disk1 SideA
									if( g_nes->rom->GetDiskNo() > 2 ) {
										g_nes->Command( NES::NESCMD_DISK_1A );
										DirectDraw.SetMessageString( "Change Disk2 SideA." );
									}
									break;
								case	4: // Disk1 SideB
									if( g_nes->rom->GetDiskNo() > 3 ) {
										g_nes->Command( NES::NESCMD_DISK_1B );
										DirectDraw.SetMessageString( "Change Disk2 SideB." );
									}
									break;
							}
						} else {
							NetPlay_Ev = Ev;
							NetPlay_Param = Param;
						}
					}
					::SetEvent( g_hEventAccept );
					break;

				case	EV_EXCONTROLLER:
					if( g_nes )
						g_nes->CommandParam( NES::NESCMD_EXCONTROLLER, Param );
					::SetEvent( g_hEventAccept );
					break;

				case	EV_SOUND_MUTE:
					{
					if( g_nes )
						if( g_nes->CommandParam( NES::NESCMD_SOUND_MUTE, Param ) ) {
							::wsprintf( szStr, "%s Enable.", g_lpSoundMuteStringTable[Param] );
						} else {
							::wsprintf( szStr, "%s Mute.", g_lpSoundMuteStringTable[Param] );
						}
						DirectDraw.SetMessageString( szStr );
					}
					::SetEvent( g_hEventAccept );
					break;

				case	EV_MOVIE_PLAY:
					if( g_nes ) {
						if( !NetPlay.IsConnect() ) {
							if( g_nes->MoviePlay( (const char*)Param ) ) {
								DirectDraw.SetMessageString( "Movie replay." );
							}
						}
					}
					::SetEvent( g_hEventAccept );
					break;

				case	EV_MOVIE_REC:
					if( g_nes ) {
						if( !NetPlay.IsConnect() ) {
							if( g_nes->MovieRec( (const char*)Param ) ) {
								DirectDraw.SetMessageString( "Movie record." );
							}
						}
					}
					::SetEvent( g_hEventAccept );
					break;

				case	EV_MOVIE_RECAPPEND:
					if( g_nes ) {
						if( !NetPlay.IsConnect() ) {
							if( g_nes->MovieRecAppend( (const char*)Param ) ) {
								DirectDraw.SetMessageString( "Movie append record." );
							}
						}
					}
					::SetEvent( g_hEventAccept );
					break;

				case	EV_MOVIE_STOP:
					if( g_nes ) {
						if( !NetPlay.IsConnect() ) {
							g_nes->MovieStop();
						}
					}
					::SetEvent( g_hEventAccept );
					break;

				case	EV_SNAPSHOT:
					if( g_nes ) {
						if( g_nes->Snapshot() ) {
							DirectDraw.SetMessageString( "Snap shot." );
						}
					}
					::SetEvent( g_hEventAccept );
					break;

				case	EV_WAVEREC_START:
					if( g_nes ) {
						DWORD	nRate, nBits;
						DirectSound.GetSamplingRate( nRate, nBits );
						g_WaveRec.Start( (LPSTR)Param, nRate, nBits, FALSE );
					}
					DirectDraw.SetMessageString( "Wave recording start." );
					::SetEvent( g_hEventAccept );
					break;

				case	EV_WAVEREC_STOP:
					if( g_nes ) {
						g_WaveRec.Stop();
						DirectDraw.SetMessageString( "Wave recording stop." );
					}
					::SetEvent( g_hEventAccept );
					break;

				case	EV_MESSAGE_OUT:
					DirectDraw.SetMessageString( (LPSTR)Param );
					::SetEvent( g_hEventAccept );
					break;

				default:
					DEBUGOUT( "ThreadProc:Unknown event.\n" );
					::SetEvent( g_hEventAccept );
					break;
			}
		} catch( CHAR* str ) {
			bPause = TRUE;
			::strcpy( g_szErrorMessage, str );
			::PostMessage( g_hWnd, WM_VNS_ERRORMSG, 0, (LPARAM)g_szErrorMessage );
			::SetEvent( g_hEventAccept );
#ifndef	_DEBUG
		} catch(...) {
			bPause = TRUE;
			::PostMessage( g_hWnd, WM_VNS_ERRORMSG, 0, (LPARAM)CApp::GetErrorString( IDS_ERROR_UNKNOWN ) );
			::SetEvent( g_hEventAccept );
#endif
		}

		if( !bPause ) {
			try {
				// フレームレート
				if( g_nes ) {
					BOOL	bKeyThrottle = FALSE;
					// キーチェック
					{
						BYTE*	pKey = (BYTE*)DirectInput.m_Sw;
						WORD*	pShortCutKey = Config.shortcut.nShortCut;
						INT*	pShortCutKeyID = Config.ShortcutKeyID;
						for( INT i = 0; pShortCutKeyID[i*3+0]; i++ ) {
							if( pShortCutKeyID[i*3+0] == ID_KEYTHROTTLE ) {
								if( (pKey[pShortCutKey[pShortCutKeyID[i*3+2]    ]] & 0x80)
								 || (pKey[pShortCutKey[pShortCutKeyID[i*3+2]+128]] & 0x80) ) {
									bKeyThrottle = TRUE;
								}
								break;
							}
						}
					}

					if( g_nes->IsDiskThrottle() ) {
						frame_period = 1000.0f/((float)60.0f*10);
					} else if( Config.emulator.bThrottle || bKeyThrottle ) {
						if( !nFrameSkip ) {
							INT	fps = (bThrottle||bKeyThrottle)?Config.emulator.nThrottleFPS:FRAME_RATE;
							if( fps <= 0 )  fps = 60;
							if( fps > 600 ) fps = 600;
							frame_period = 1000.0f/(float)fps;
						} else {
							frame_period = 1000.0f/((float)60.0f*(nFrameSkip+1));
						}
					} else {
						frame_period = 1000.0f/(float)FRAME_RATE;
					}
				} else {
					frame_period = 1000.0f/60.0f;
				}

				// フレームスキップ数の計算
				now_time = (INT)(::timeGetTime() - old_time);
				if( !NetPlay.IsConnect() ) {
					if( Config.emulator.bAutoFrameSkip ) {
						if( !nFrameSkip && !g_nes->IsDiskThrottle() ) {
							frameskipno = (INT)(((double)now_time-last_frame_time)/frame_period);
							if( frameskipno < 0 || frameskipno > 20 ) {
								frameskipno = 1;
								last_frame_time = 0.0f;
								frame_period = 1000.0f/(float)FRAME_RATE;
								old_time = ::timeGetTime();
							}
						} else if( g_nes->IsDiskThrottle() ) {
							frameskipno = 10;
						} else {
							frameskipno = nFrameSkip+1;
						}
					} else {
						// オートを外してVSYNC同期の時にもフレームスキップをする為の措置
						frameskipno = nFrameSkip+1;
//						frameskipno = 1;
					}
				} else {
				// NetPlay中は絶対オートフレームスキップ
					frameskipno = (INT)(((double)now_time-last_frame_time)/frame_period);
					if( frameskipno < 0 || frameskipno > 60 ) {
						frameskipno = 1;
						last_frame_time = 0.0f;
						frame_period = 1000.0f/(float)FRAME_RATE;
						old_time = ::timeGetTime();
					}
					// ドロップフレームが多くなってしまった時に一旦リセットする！！
					if( frameskipno > 1 ) {
						dropframe += frameskipno;
						if( dropframe > 60 ) {
							dropframe = 0;
							frameskipno = 1;
							last_frame_time = 0.0f;
							frame_period = 1000.0f/(float)FRAME_RATE;
							old_time = ::timeGetTime();
						}
					}
				}

				// エミュレーション本体
				if( (!bEmuPause || bOneStep)  && g_nes ) {
					g_nes->ppu->SetScreenPtr( DirectDraw.GetRenderScreen() );

					if( frameskipno > 1 && !bOneStep ) {
						for( i = 1; i < frameskipno; i++ ) {
							last_frame_time += frame_period;
							DirectInput.Poll();
							if( DirectDraw.GetZapperMode() ) {
								LONG	x, y;
								DirectDraw.GetZapperPos( x, y );
								g_nes->SetZapperPos( x, y );
							}

							if( NetPlay.IsConnect() ) {
								g_nes->pad->Sync();

								if( (nNetSyncStep%NetPlay.GetLatency())==0 ) {
									DWORD	paddata = g_nes->pad->GetSyncData();
									BYTE	padbuf[2];
									BYTE	databuf;

									if( NetPlay_Ev == EV_HWRESET ) {
										databuf = 0xFE;	// HW reset
										g_nes->Command( NES::NESCMD_HWRESET );
										DirectDraw.SetMessageString( "Hardware reset." );

										if( NetPlay.Send( (unsigned char*)&databuf, sizeof(BYTE) ) ) {
											NetPlay.Disconnect();
											bPause = TRUE;
										}
									} else if( NetPlay_Ev == EV_SWRESET ) {
										databuf = 0xFF;	// SW reset
										g_nes->Command( NES::NESCMD_SWRESET );
										DirectDraw.SetMessageString( "Software reset." );

										if( NetPlay.Send( (unsigned char*)&databuf, sizeof(BYTE) ) ) {
											NetPlay.Disconnect();
											bPause = TRUE;
										}
									} else if( NetPlay_Ev == EV_DISK_COMMAND ) {
										BYTE	exdata = 0;

										switch( NetPlay_Param ) {
											case	0: // Eject
												if( g_nes->rom->GetDiskNo() > 0 ) {
													g_nes->Command( NES::NESCMD_DISK_EJECT );
													exdata = 0xF8;
													DirectDraw.SetMessageString( "Disk Eject." );
												}
												break;
											case	1: // Disk0 SideA
												if( g_nes->rom->GetDiskNo() > 0 ) {
													g_nes->Command( NES::NESCMD_DISK_0A );
													exdata = 0xF9;
													DirectDraw.SetMessageString( "Change Disk1 SideA." );
												}
												break;
											case	2: // Disk0 SideB
												if( g_nes->rom->GetDiskNo() > 1 ) {
													g_nes->Command( NES::NESCMD_DISK_0B );
													exdata = 0xFA;
													DirectDraw.SetMessageString( "Change Disk1 SideB." );
												}
												break;
											case	3: // Disk1 SideA
												if( g_nes->rom->GetDiskNo() > 2 ) {
													g_nes->Command( NES::NESCMD_DISK_1A );
													exdata = 0xFB;
													DirectDraw.SetMessageString( "Change Disk2 SideA." );
												}
												break;
											case	4: // Disk1 SideB
												if( g_nes->rom->GetDiskNo() > 3 ) {
													g_nes->Command( NES::NESCMD_DISK_1B );
													exdata = 0xFC;
													DirectDraw.SetMessageString( "Change Disk2 SideB." );
												}
												break;
										}
										// Disk commands
										if( NetPlay.Send( (unsigned char*)&exdata, sizeof(BYTE) ) ) {
											NetPlay.Disconnect();
											bPause = TRUE;
										}
									}
									NetPlay_Ev = EV_NONE;
									NetPlay_Param = 0;

									if( NetPlay.IsServer() ) {
										padbuf[0] = (BYTE)paddata;

										if( NetPlay.Send( (unsigned char*)&padbuf[0], sizeof(BYTE) ) ) {
											NetPlay.Disconnect();
											bPause = TRUE;
										}

										// 10秒でタイムアウト
										if( NetPlay.RecvTime( (unsigned char*)&databuf, sizeof(BYTE), 10*1000 ) < 0 ) {
											NetPlay.Disconnect();
											bPause = TRUE;
										}

										if( (databuf & 0xF0) == 0xF0 ) {
											if( databuf == 0xFE ) {
												g_nes->Command( NES::NESCMD_HWRESET );
												DirectDraw.SetMessageString( "Hardware reset." );
											} else if( databuf == 0xFF ) {
												g_nes->Command( NES::NESCMD_SWRESET );
												DirectDraw.SetMessageString( "Software reset." );
											} else {
												NetPlayDiskCommand( databuf );
											}

											if( NetPlay.RecvTime( (unsigned char*)&padbuf[1], sizeof(BYTE), 10*1000 ) < 0 ) {
												NetPlay.Disconnect();
												bPause = TRUE;
											}
										} else {
											padbuf[1] = databuf;
										}
									} else {
										padbuf[1] = (BYTE)paddata;

										if( NetPlay.Send( (unsigned char*)&padbuf[1], sizeof(BYTE) ) ) {
											NetPlay.Disconnect();
											bPause = TRUE;
										}

										// 10秒でタイムアウト
										if( NetPlay.RecvTime( (unsigned char*)&databuf, sizeof(BYTE), 10*1000 ) < 0 ) {
											NetPlay.Disconnect();
											bPause = TRUE;
										}

										if( (databuf & 0xF0) == 0xF0 ) {
											if( databuf == 0xFE ) {
												g_nes->Command( NES::NESCMD_HWRESET );
												DirectDraw.SetMessageString( "Hardware reset." );
											} else if( databuf == 0xFF ) {
												g_nes->Command( NES::NESCMD_SWRESET );
												DirectDraw.SetMessageString( "Software reset." );
											} else {
												NetPlayDiskCommand( databuf );
											}
											if( NetPlay.RecvTime( (unsigned char*)&padbuf[0], sizeof(BYTE), 10*1000 ) < 0 ) {
												NetPlay.Disconnect();
												bPause = TRUE;
											}
										} else {
											padbuf[0] = databuf;
										}
									}
									dwNetSyncData = (DWORD)padbuf[0]|((DWORD)padbuf[1]<<8);
								}
								g_nes->pad->SetSyncData( dwNetSyncData );
								nNetSyncStep++;
							} else {
								// For Movie!!
								g_nes->pad->Sync();
								g_nes->Movie();
							}
							g_nes->EmulateFrame( FALSE );
							// Sound streaming
							StreamProcess( bEmuPause );
						}
					}

					DirectInput.Poll();
					if( DirectDraw.GetZapperMode() ) {
						LONG	x, y;
						DirectDraw.GetZapperPos( x, y );
						g_nes->SetZapperPos( x, y );
					}

					if( NetPlay.IsConnect() ) {
						g_nes->pad->Sync();

						INT	nLatency = NetPlay.GetLatency();
						if( (nNetSyncStep%NetPlay.GetLatency())==0 ) {
							DWORD	paddata = g_nes->pad->GetSyncData();
							BYTE	padbuf[2];
							BYTE	databuf;

							if( NetPlay_Ev == EV_HWRESET ) {
								databuf = 0xFE;	// HW reset
								g_nes->Command( NES::NESCMD_HWRESET );
								DirectDraw.SetMessageString( "Hardware reset." );

								if( NetPlay.Send( (unsigned char*)&databuf, sizeof(BYTE) ) ) {
									NetPlay.Disconnect();
									bPause = TRUE;
								}
							} else if( NetPlay_Ev == EV_SWRESET ) {
								databuf = 0xFF;	// SW reset
								g_nes->Command( NES::NESCMD_SWRESET );
								DirectDraw.SetMessageString( "Software reset." );

								if( NetPlay.Send( (unsigned char*)&databuf, sizeof(BYTE) ) ) {
									NetPlay.Disconnect();
									bPause = TRUE;
								}
							} else if( NetPlay_Ev == EV_DISK_COMMAND ) {
								BYTE	exdata = 0;

								switch( NetPlay_Param ) {
									case	0: // Eject
										if( g_nes->rom->GetDiskNo() > 0 ) {
											g_nes->Command( NES::NESCMD_DISK_EJECT );
											exdata = 0xF8;
											DirectDraw.SetMessageString( "Disk Eject." );
										}
										break;
									case	1: // Disk0 SideA
										if( g_nes->rom->GetDiskNo() > 0 ) {
											g_nes->Command( NES::NESCMD_DISK_0A );
											exdata = 0xF9;
											DirectDraw.SetMessageString( "Change Disk1 SideA." );
										}
										break;
									case	2: // Disk0 SideB
										if( g_nes->rom->GetDiskNo() > 1 ) {
											g_nes->Command( NES::NESCMD_DISK_0B );
											exdata = 0xFA;
											DirectDraw.SetMessageString( "Change Disk1 SideB." );
										}
										break;
									case	3: // Disk1 SideA
										if( g_nes->rom->GetDiskNo() > 2 ) {
											g_nes->Command( NES::NESCMD_DISK_1A );
											exdata = 0xFB;
											DirectDraw.SetMessageString( "Change Disk2 SideA." );
										}
										break;
									case	4: // Disk1 SideB
										if( g_nes->rom->GetDiskNo() > 3 ) {
											g_nes->Command( NES::NESCMD_DISK_1B );
											exdata = 0xFC;
											DirectDraw.SetMessageString( "Change Disk2 SideB." );
										}
										break;
								}

								// Disk commands
								if( NetPlay.Send( (unsigned char*)&exdata, sizeof(BYTE) ) ) {
									NetPlay.Disconnect();
									bPause = TRUE;
								}
							}
							NetPlay_Ev = EV_NONE;
							NetPlay_Param = 0;

							if( NetPlay.IsServer() ) {
								padbuf[0] = (BYTE)paddata;

								if( NetPlay.Send( (unsigned char*)&padbuf[0], sizeof(BYTE) ) ) {
									NetPlay.Disconnect();
									bPause = TRUE;
								}

								// 10秒でタイムアウト
								if( NetPlay.RecvTime( (unsigned char*)&databuf, sizeof(BYTE), 10*1000 ) < 0 ) {
									NetPlay.Disconnect();
									bPause = TRUE;
								}

								if( (databuf & 0xF0) == 0xF0 ) {
									if( databuf == 0xFE ) {
										g_nes->Command( NES::NESCMD_HWRESET );
										DirectDraw.SetMessageString( "Hardware reset." );
									} else if( databuf == 0xFF ) {
										g_nes->Command( NES::NESCMD_SWRESET );
										DirectDraw.SetMessageString( "Software reset." );
									} else {
										NetPlayDiskCommand( databuf );
									}

									if( NetPlay.RecvTime( (unsigned char*)&padbuf[1], sizeof(BYTE), 10*1000 ) < 0 ) {
										NetPlay.Disconnect();
										bPause = TRUE;
									}
								} else {
									padbuf[1] = databuf;
								}
							} else {
								padbuf[1] = (BYTE)paddata;

								if( NetPlay.Send( (unsigned char*)&padbuf[1], sizeof(BYTE) ) ) {
									NetPlay.Disconnect();
									bPause = TRUE;
								}

								// 10秒でタイムアウト
								if( NetPlay.RecvTime( (unsigned char*)&databuf, sizeof(BYTE), 10*1000 ) < 0 ) {
									NetPlay.Disconnect();
									bPause = TRUE;
								}

								if( (databuf & 0xF0) == 0xF0 ) {
									if( databuf == 0xFE ) {
										g_nes->Command( NES::NESCMD_HWRESET );
										DirectDraw.SetMessageString( "Hardware reset." );
									} else if( databuf == 0xFF ) {
										g_nes->Command( NES::NESCMD_SWRESET );
										DirectDraw.SetMessageString( "Software reset." );
									} else {
										NetPlayDiskCommand( databuf );
									}
									if( NetPlay.RecvTime( (unsigned char*)&padbuf[0], sizeof(BYTE), 10*1000 ) < 0 ) {
										NetPlay.Disconnect();
										bPause = TRUE;
									}
								} else {
									padbuf[0] = databuf;
								}
							}
							dwNetSyncData = (DWORD)padbuf[0]|((DWORD)padbuf[1]<<8);
						}
						g_nes->pad->SetSyncData( dwNetSyncData );
						nNetSyncStep++;
					} else {
						// For Movie!!
						g_nes->pad->Sync();
						g_nes->Movie();
					}

					g_nes->EmulateFrame( TRUE );

					// Sound streaming
					StreamProcess( bEmuPause );
				} else {
					// イベント発生の為
					DirectInput.Poll();
				}

				// 描画
				if( g_nes->ppu->GetExtMonoMode() ) {
					DirectDraw.SetPaletteMode( (PPUREG[1]&PPU_BGCOLOR_BIT)>>5, 0 );
				} else {
					DirectDraw.SetPaletteMode( (PPUREG[1]&PPU_BGCOLOR_BIT)>>5, PPUREG[1]&PPU_COLORMODE_BIT );
				}

				DirectDraw.Blt();

				// Sound streaming
				StreamProcess( bEmuPause );

				// 時間待ち
				if( Config.emulator.bAutoFrameSkip ) {
					fliptime = (LONG)(last_frame_time+frame_period);
					LONG timeleft = fliptime-(LONG)(::timeGetTime()-old_time);
					if( !Config.general.bScreenMode || !Config.graphics.bSyncDraw ) {
						if( timeleft > 1 ) {
							::Sleep( timeleft );
							// Sound streaming
//							StreamProcess( bEmuPause );
						} else {
							// とりあえず入れておく(Windows重くなる対策)
							::Sleep( 0 );
						}
					} else {
						if( timeleft > 4 ) {
							::Sleep( timeleft-4 );
							// Sound streaming
//							StreamProcess( bEmuPause );
						} else {
							// とりあえず入れておく(Windows重くなる対策)
							::Sleep( 0 );
						}
					}
				} else {
					// とりあえず入れておく(Windows重くなる対策)
					::Sleep( 0 );
				}

#if	0
				// フリップまでの時間待ち
				if( Config.emulator.bAutoFrameSkip ) {
					fliptime = (LONG)(last_frame_time+frame_period);
					if( !Config.general.bScreenMode || !Config.graphics.bSyncDraw ) {
						while( TRUE ) {
							if( fliptime-(LONG)(::timeGetTime()-old_time) <= 0 )
								break;
						}
					} else {
						while( TRUE ) {
							if( fliptime-(LONG)(::timeGetTime()-old_time) <= 8 )
								break;
						}
					}
				}
#endif
				last_frame_time += frame_period;

				DirectDraw.Flip();

				// 平均フレームレートの算出
				dwFrameTime[nFrameCount] = ::timeGetTime();
				if( ++nFrameCount > 32-1 ) {
					nFrameCount = 0;
					if( Config.graphics.bFPSDisp ) {
						DWORD	FPS;
						if( dwFrameTime[64-1]-dwFrameTime[0] > 0 ) {
							FPS = 1000*10*(32-1)/(dwFrameTime[32-1]-dwFrameTime[0]);
						} else {
							FPS = 0;
						}
						sprintf( szStr, "FPS:%d.%01d", FPS/10, FPS%10 );
						DirectDraw.SetInfoString( szStr );
					} else {
						DirectDraw.SetInfoString( NULL );
					}
				}
			} catch( CHAR* str ) {
				bPause = TRUE;
				::strcpy( g_szErrorMessage, str );
				::PostMessage( g_hWnd, WM_VNS_ERRORMSG, 0, (LPARAM)g_szErrorMessage );
#ifndef	_DEBUG
			} catch(...) {
				bPause = TRUE;
				::PostMessage( g_hWnd, WM_VNS_ERRORMSG, 0, (LPARAM)CApp::GetErrorString( IDS_ERROR_UNKNOWN ) );
#endif
			}
		} else {
			// イベント発生の為
			DirectInput.Poll();
			// 呼ばないとWindowsが重くなるので(NT系以外は特に)
			::Sleep( 20 );
		}
	}

	g_WaveRec.Stop();

	return	0;
}

void	CEmuThread::StreamProcess( BOOL bPause )
{
	if( g_pThis && g_nes && !bPause && !DirectSound.IsStreamPause() ) {
		DWORD	dwWrite, dwSize;
		LPVOID	lpLockPtr;
		DWORD	dwLockSize;
		if( DirectSound.GetStreamLockPosition( &dwWrite, &dwSize ) ) {
			if( DirectSound.StreamLock( dwWrite, dwSize, &lpLockPtr, &dwLockSize, NULL, NULL, 0 ) ) {
				g_nes->apu->Process( (LPBYTE)lpLockPtr, dwLockSize );
				g_WaveRec.Out( lpLockPtr, dwLockSize );
				DirectSound.StreamUnlock( lpLockPtr, dwLockSize, NULL, NULL );
			}
		}
	}
}

