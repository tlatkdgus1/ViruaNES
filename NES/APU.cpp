//////////////////////////////////////////////////////////////////////////
//                                                                      //
//      NES APU core                                                    //
//                                                           Norix      //
//                                               written     2001/02/22 //
//                                               last modify ----/--/-- //
//////////////////////////////////////////////////////////////////////////
#include "DebugOut.h"
#include "App.h"
#include "Config.h"

#include "nes.h"
#include "mmu.h"
#include "cpu.h"
#include "apu.h"

// Volume adjust
// Internal sounds
#define	RECTANGLE_VOL	(0x0F0)
#define	TRIANGLE_VOL	(0x130)
#define	NOISE_VOL	(0x0C0)
#define	DPCM_VOL	(0x0F0)
// Extra sounds
// https://en.wikipedia.org/wiki/Memory_management_controller
#define	VRC6_VOL	(0x0F0)
#define	VRC7_VOL	(0x130)
#define	FDS_VOL		(0x0F0)
#define	MMC5_VOL	(0x0F0) 
#define	N106_VOL	(0x088)
#define	FME7_VOL	(0x130)

APU::QUEUE	APU::queue;
APU::QUEUE	APU::exqueue;

// 생성자 여러 변수들을 초기화 시킴
APU::APU( NES* parent )
{
	exsound_select = 0; // 어떤 mmc를 설정 할 것인가에 대해 영향을 미치는 변수

	nes = parent;
	internal.SetParent( parent );

	last_data = last_diff = 0;

	::ZeroMemory( lowpass_filter, sizeof(lowpass_filter) );

	::ZeroMemory( &queue, sizeof(queue) );
	::ZeroMemory( &exqueue, sizeof(exqueue) );

	for( INT i = 0; i < 16; i++ ) {
		m_bMute[i] = TRUE;
	}
}

APU::~APU()
{
}

// apu.h에 있는 QUEUE queue에 맴버들 값을 인자로 설정함
// wrptr &= 4095 (QUEUE_LENGTH = 4096)
// wrptr, rdptr이 같으면 오버플로우 경고메시지
void	APU::SetQueue( INT writetime, WORD addr, BYTE data )
{
	queue.data[queue.wrptr].time = writetime;
	queue.data[queue.wrptr].addr = addr;
	queue.data[queue.wrptr].data = data;
	queue.wrptr++;
	queue.wrptr&=QUEUE_LENGTH-1;
	if( queue.wrptr == queue.rdptr ) {
		DEBUGOUT( "queue overflow.\n" );
	}
}

// wrptr과 rdptr이 같지 않고
// 1번째 인자가 queue의 time 맴버의 값보다 크면
// 2번째 인자에 queue의 data에 rdptr의 값을 넘긴다
// rdptr++ 후 rdptr &= 4095 후 return TRUE
BOOL	APU::GetQueue( INT writetime, QUEUEDATA& ret )
{
	if( queue.wrptr == queue.rdptr ) {
		return	FALSE;
	}
	if( queue.data[queue.rdptr].time <= writetime ) {
		ret = queue.data[queue.rdptr];
		queue.rdptr++;
		queue.rdptr&=QUEUE_LENGTH-1;
		return	TRUE;
	}
	return	FALSE;
}

// SetQueue랑 ExQueue인것 외에 동일
void	APU::SetExQueue( INT writetime, WORD addr, BYTE data )
{
	exqueue.data[exqueue.wrptr].time = writetime;
	exqueue.data[exqueue.wrptr].addr = addr;
	exqueue.data[exqueue.wrptr].data = data;
	exqueue.wrptr++;
	exqueue.wrptr&=QUEUE_LENGTH-1;
	if( exqueue.wrptr == exqueue.rdptr ) {
		DEBUGOUT( "exqueue overflow.\n" );
	}
}

// 위와 동일
BOOL	APU::GetExQueue( INT writetime, QUEUEDATA& ret )
{
	if( exqueue.wrptr == exqueue.rdptr ) {
		return	FALSE;
	}
	if( exqueue.data[exqueue.rdptr].time <= writetime ) {
		ret = exqueue.data[exqueue.rdptr];
		exqueue.rdptr++;
		exqueue.rdptr&=QUEUE_LENGTH-1;
		return	TRUE;
	}
	return	FALSE;
}

// 아래의 WriteProcess 참조
void	APU::QueueFlush()
{
	while( queue.wrptr != queue.rdptr ) {
		WriteProcess( queue.data[queue.rdptr].addr, queue.data[queue.rdptr].data );
		queue.rdptr++;
		queue.rdptr&=QUEUE_LENGTH-1;
	}

	while( exqueue.wrptr != exqueue.rdptr ) {
		WriteExProcess( exqueue.data[queue.rdptr].addr, exqueue.data[queue.rdptr].data );
		exqueue.rdptr++;
		exqueue.rdptr&=QUEUE_LENGTH-1;
	}
}

// Detault Config.sound.nRate = 22050
// Setup 함수는 각각의 mmc의 cpp파일에 있다.
void	APU::SoundSetup()
{
	INT	nRate = (INT)Config.sound.nRate;
	internal.Setup( nRate );
	vrc6.Setup( nRate );
	vrc7.Setup( nRate );
	mmc5.Setup( nRate );
	fds.Setup( nRate );
	n106.Setup( nRate );
	fme7.Setup( nRate );
}

// queue, exqueue 초기화, mmc.Reset함수 호출
// 마지막 SoundSetup()은 default 값 설정을 의미
void	APU::Reset()
{
	::ZeroMemory( &queue, sizeof(queue) );
	::ZeroMemory( &exqueue, sizeof(exqueue) );

	elapsed_time = 0;

	INT	nRate = (INT)Config.sound.nRate;
	internal.Reset( nRate );
	vrc6.Reset( nRate );
	vrc7.Reset( nRate );
	mmc5.Reset( nRate );
	fds.Reset( nRate );
	n106.Reset( nRate );
	fme7.Reset( nRate );

	SoundSetup();
}

// exsound_select를 1번째 인자의 값으로 설정
void	APU::SelectExSound( BYTE data )
{
	exsound_select = data;
}

// addr에 따라서 다른 값의 리턴 값을 internal.ReadSync(addr)을 통해 넘겨받음
// APU_INTERNAL.cpp에 동작이 나옴
BYTE	APU::Read( WORD addr )
{
	return	internal.ReadSync( addr );
}

// APU_INTERNAL.cpp WriteSync 참조
void	APU::Write( WORD addr, BYTE data )
{
	if( addr >= 0x4000 && addr <= 0x4017 ) {
		internal.WriteSync( addr, data );
		SetQueue( nes->cpu->GetTotalCycles(), addr, data );
	}
}

BYTE	APU::ExRead( WORD addr )
{
BYTE	data = 0;

	if( exsound_select & 0x10 ) {
		if( addr == 0x4800 ) {
			SetExQueue( nes->cpu->GetTotalCycles(), 0, 0 );
		}
	}
	if( exsound_select & 0x04 ) {
		if( addr >= 0x4040 && addr < 0x4100 ) {
			data = fds.ReadSync( addr );
		}
	}

	return	data;
}

void	APU::ExWrite( WORD addr, BYTE data )
{
	SetExQueue( nes->cpu->GetTotalCycles(), addr, data );

	if( exsound_select & 0x04 ) {
		if( addr >= 0x4040 && addr < 0x4100 ) {
			fds.WriteSync( addr, data );
		}
	}
}

void	APU::Sync()
{
	internal.VSync();
}

void	APU::SyncDPCM( INT cycles )
{
	if( internal.Sync( cycles ) ) {
		nes->cpu->IRQ_NotPending();
	}
	if( exsound_select & 0x04 ) {
		fds.Sync( cycles*256 );
	}
}

// APU_INTERNAL.cpp에 internal.Write의 동작이 나옴.
// 0x4000 ~ 0x4017의 동작이 나와있음
void	APU::WriteProcess( WORD addr, BYTE data )
{
	if( addr >= 0x4000 && addr <= 0x4017 ) {
		internal.Write( addr, data );
	}
}

void	APU::WriteExProcess( WORD addr, BYTE data )
{
	if( exsound_select & 0x01 ) {
		vrc6.Write( addr, data );
	}
	if( exsound_select & 0x02 ) {
		vrc7.Write( addr, data );
	}
	if( exsound_select & 0x04 ) {
		fds.Write( addr, data );
	}
	if( exsound_select & 0x08 ) {
		mmc5.Write( addr, data );
	}
	if( exsound_select & 0x10 ) {
		if( addr == 0x0000 ) {
			BYTE	dummy = n106.Read( addr );
		} else {
			n106.Write( addr, data );
		}
	}
	if( exsound_select & 0x20 ) {
		fme7.Write( addr, data );
	}
}

void	APU::Process( LPBYTE lpBuffer, DWORD dwSize )
{
INT	nBits = Config.sound.nBits;
DWORD	dwLength = dwSize / (nBits/8);
INT	output;
QUEUEDATA q;
DWORD	writetime;

LPSHORT	pSoundBuf = m_SoundBuffer;
INT	nCcount = 0;

INT	nFilterType = Config.sound.nFilterType;

	if( !Config.sound.bEnable ) {
		::FillMemory( lpBuffer, dwSize, (BYTE)(Config.sound.nRate==8?128:0) );
		return;
	}

	// Volume setup
	//  0:Master
	//  1:Rectangle 1
	//  2:Rectangle 2
	//  3:Triangle
	//  4:Noise
	//  5:DPCM
	//  6:VRC6
	//  7:VRC7
	//  8:FDS
	//  9:MMC5
	// 10:N106
	// 11:FME7
	INT	vol[24];
	BOOL*	bMute = m_bMute;
	SHORT*	nVolume = Config.sound.nVolume;

	INT	nMasterVolume = bMute[0]?nVolume[0]:0;

	// Internal
	vol[ 0] = bMute[1]?(RECTANGLE_VOL*nVolume[1]*nMasterVolume)/(100*100):0;
	vol[ 1] = bMute[2]?(RECTANGLE_VOL*nVolume[2]*nMasterVolume)/(100*100):0;
	vol[ 2] = bMute[3]?(TRIANGLE_VOL *nVolume[3]*nMasterVolume)/(100*100):0;
	vol[ 3] = bMute[4]?(NOISE_VOL    *nVolume[4]*nMasterVolume)/(100*100):0;
	vol[ 4] = bMute[5]?(DPCM_VOL     *nVolume[5]*nMasterVolume)/(100*100):0;

	// VRC6
	vol[ 5] = bMute[6]?(VRC6_VOL*nVolume[6]*nMasterVolume)/(100*100):0;
	vol[ 6] = bMute[7]?(VRC6_VOL*nVolume[6]*nMasterVolume)/(100*100):0;
	vol[ 7] = bMute[8]?(VRC6_VOL*nVolume[6]*nMasterVolume)/(100*100):0;

	// VRC7
	vol[ 8] = bMute[6]?(VRC7_VOL*nVolume[7]*nMasterVolume)/(100*100):0;

	// FDS
	vol[ 9] = bMute[6]?(FDS_VOL*nVolume[8]*nMasterVolume)/(100*100):0;

	// MMC5
	vol[10] = bMute[6]?(MMC5_VOL*nVolume[9]*nMasterVolume)/(100*100):0;
	vol[11] = bMute[7]?(MMC5_VOL*nVolume[9]*nMasterVolume)/(100*100):0;
	vol[12] = bMute[8]?(MMC5_VOL*nVolume[9]*nMasterVolume)/(100*100):0;

	// N106
	vol[13] = bMute[ 6]?(N106_VOL*nVolume[10]*nMasterVolume)/(100*100):0;
	vol[14] = bMute[ 7]?(N106_VOL*nVolume[10]*nMasterVolume)/(100*100):0;
	vol[15] = bMute[ 8]?(N106_VOL*nVolume[10]*nMasterVolume)/(100*100):0;
	vol[16] = bMute[ 9]?(N106_VOL*nVolume[10]*nMasterVolume)/(100*100):0;
	vol[17] = bMute[10]?(N106_VOL*nVolume[10]*nMasterVolume)/(100*100):0;
	vol[18] = bMute[11]?(N106_VOL*nVolume[10]*nMasterVolume)/(100*100):0;
	vol[19] = bMute[12]?(N106_VOL*nVolume[10]*nMasterVolume)/(100*100):0;
	vol[20] = bMute[13]?(N106_VOL*nVolume[10]*nMasterVolume)/(100*100):0;

	// FME7
	vol[21] = bMute[6]?(FME7_VOL*nVolume[11]*nMasterVolume)/(100*100):0;
	vol[22] = bMute[7]?(FME7_VOL*nVolume[11]*nMasterVolume)/(100*100):0;
	vol[23] = bMute[8]?(FME7_VOL*nVolume[11]*nMasterVolume)/(100*100):0;

//	INT	cycle_rate = (INT)(CPU_CLOCK*65536.0f/(float)Config.sound.nRate);
//	INT	cycle_rate = (INT)((FRAME_CYCLES*60.0f/12.0f)*65536.0f/(float)Config.sound.nRate);

//	double	elapsedtime = (double)elapsed_time;
	double	cycle_rate = ((double)FRAME_CYCLES*60.0/12.0)/(double)Config.sound.nRate;
//	double	cycle_rate = (double)CPU_CLOCK/(double)Config.sound.nRate;

	// CPU긖귽긏깑릶궕깑?긵궢궲궢귏궯궫렄궻뫮랉룉뿚
	if( elapsed_time > nes->cpu->GetTotalCycles() ) {
		QueueFlush();
	}

	while( dwLength-- ) {
//		writetime = (DWORD)(elapsedtime>>16);
		writetime = (DWORD)elapsed_time;

		while( GetQueue( writetime, q ) ) {
			WriteProcess( q.addr, q.data );
		}

		while( GetExQueue( writetime, q ) ) {
			WriteExProcess( q.addr, q.data );
		}

		// 0-4:internal 5-7:VRC6 8:VRC7 9:FDS 10-12:MMC5 13-20:N106 21-23:FME7
		output = 0;
		output += internal.Process( 0 )*vol[0];
		output += internal.Process( 1 )*vol[1];
		output += internal.Process( 2 )*vol[2];
		output += internal.Process( 3 )*vol[3];
		output += internal.Process( 4 )*vol[4];

		if( exsound_select & 0x01 ) {
			output += vrc6.Process( 0 )*vol[5];
			output += vrc6.Process( 1 )*vol[6];
			output += vrc6.Process( 2 )*vol[7];
		}
		if( exsound_select & 0x02 ) {
			output += vrc7.Process( 0 )*vol[8];
		}
		if( exsound_select & 0x04 ) {
			output += fds.Process( 0 )*vol[9];
		}
		if( exsound_select & 0x08 ) {
			output += mmc5.Process( 0 )*vol[10];
			output += mmc5.Process( 1 )*vol[11];
			output += mmc5.Process( 2 )*vol[12];
		}
		if( exsound_select & 0x10 ) {
			output += n106.Process( 0 )*vol[13];
			output += n106.Process( 1 )*vol[14];
			output += n106.Process( 2 )*vol[15];
			output += n106.Process( 3 )*vol[16];
			output += n106.Process( 4 )*vol[17];
			output += n106.Process( 5 )*vol[18];
			output += n106.Process( 6 )*vol[19];
			output += n106.Process( 7 )*vol[20];
		}
		if( exsound_select & 0x20 ) {
			fme7.Process( 3 );	// Envelope & Noise
			output += fme7.Process( 0 )*vol[21];
			output += fme7.Process( 1 )*vol[22];
			output += fme7.Process( 2 )*vol[23];
		}

		output >>= 8;

		if( nFilterType == 1 ) {
			//깓?긬긚긲귻깑??TYPE A(Simple)
			output = (lowpass_filter[0]+output)/2;
			lowpass_filter[0] = output;
		} else if( nFilterType == 2 ) {
			//깓?긬긚긲귻깑??TYPE B(Weighted)
			output = (lowpass_filter[1]+lowpass_filter[0]*2+output)/4;
			lowpass_filter[1] = lowpass_filter[0];
			lowpass_filter[0] = output;
		}

#if	1
		// DC맟빁궻긇긞긣
		{
		static double ave = 0.0, max=0.0, min=0.0;
		double delta;
		delta = (max-min)/32768.0;
		max -= delta;
		min += delta;
		if( output > max ) max = output;
		if( output < min ) min = output;
		ave -= ave/1024.0;
		ave += (max+min)/2048.0;
		output -= (INT)ave;
		}
#endif
#if	0
		// DC맟빁궻긇긞긣(HPF TEST)
		{
		static	double	cutoff = (2.0*3.141592653579*5.0/44100.0);
		static	double	tmp = 0.0;
		double	in, out;

		in = (double)output;
		out = (in - tmp);
		tmp = tmp + cutoff * out;

		output = (INT)out;
		}
#endif
#if	0
		// 긚긬귽긏긩귽긛궻룣땸(AGC TEST)
		{
		INT	diff = abs(output-last_data);
		if( diff > 0x4000 ) {
			output /= 4;
		} else 
		if( diff > 0x3000 ) {
			output /= 3;
		} else
		if( diff > 0x2000 ) {
			output /= 2;
		}
		last_data = output;
		}
#endif
		// Limit
		if( output > 0x7FFF ) {
			output = 0x7FFF;
		} else if( output < -0x8000 ) {
			output = -0x8000;
		}

		if( nBits != 8 ) {
			*(SHORT*)lpBuffer = (SHORT)output;
			lpBuffer += sizeof(SHORT);
		} else {
			*lpBuffer++ = (output>>8)^0x80;
		}

		if( nCcount < 0x0100 )
			pSoundBuf[nCcount++] = (SHORT)output;

//		elapsedtime += cycle_rate;
		elapsed_time += cycle_rate;
	}

#if	1
	if( elapsed_time > ((FRAME_CYCLES/24)+nes->cpu->GetTotalCycles()) ) {
//DEBUGOUT( "A Elapsed:%08X CPU Elapsed:%08X\n", (INT)elapsed_time, nes->cpu->GetTotalCycles() );
		elapsed_time = nes->cpu->GetTotalCycles();
	}
	if( (elapsed_time+(FRAME_CYCLES/6)) < nes->cpu->GetTotalCycles() ) {
//DEBUGOUT( "B Elapsed:%08X CPU Elapsed:%08X\n", (INT)elapsed_time, nes->cpu->GetTotalCycles() );
		elapsed_time = nes->cpu->GetTotalCycles();
	}
#else
	elapsed_time = nes->cpu->GetTotalCycles();
#endif
}

// ?긿깛긨깑궻뢂봥릶롦벦긖긳깑??깛(NSF뾭)
INT	APU::GetChannelFrequency( INT no )
{
	// Internal
	if( no < 5 )
		return	internal.GetFreq( no );
	// VRC6
	if( (exsound_select & 0x01) && no >= 0x0100 && no < 0x0103 )
		return	vrc6.GetFreq( no & 0x03 );
	// FDS
	if( (exsound_select & 0x04) && no == 0x300 )
		return	fds.GetFreq( 0 );
	// MMC5
	if( (exsound_select & 0x08) && no >= 0x0400 && no < 0x0402 )
		return	mmc5.GetFreq( no & 0x03 );
	// N106
	if( (exsound_select & 0x10) && no >= 0x0500 && no < 0x0508 )
		return	n106.GetFreq( no & 0x07 );
	// FME7
	if( (exsound_select & 0x20) && no >= 0x0600 && no < 0x0603 )
		return	fme7.GetFreq( no & 0x03 );
	return	0;
}

