//////////////////////////////////////////////////////////////////////////
//                                                                      //
//      NES Emulation core                                              //
//                                                           Norix      //
//                                               written     2001/02/22 //
//                                               last modify ----/--/-- //
//////////////////////////////////////////////////////////////////////////
#ifndef	__NES_INCLUDED__
#define	__NES_INCLUDED__

#define	WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "typedef.h"
#include "macro.h"

#include "state.h"
#include "cheat.h"

#include <vector>
using namespace std;

// 供給ベースクロック/CPUクロック
#define	BASE_CLOCK		21477270
#define	CPU_CLOCK		1789772.5f

#define	PPU_TO_CPU_MULTI	12

#define	SCANLINE_NUM		262

#define	SCANLINE_CYCLES		1364
#define	SCANLINE_END_CYCLES	4

#define	FETCH_CYCLES		8
#define	HDRAW_CYCLES		1024
#define	HBLANK_CYCLES		340

#define	FRAME_CYCLES		(SCANLINE_CYCLES*SCANLINE_NUM)
#define	FRAME_END_CYCLES	4

#define	FRAMEIRQ_CYCLES		29828

#define	FRAMESYNC_CYCLES	(FRAME_CYCLES/48)

// フレームレート/１フレームの実時間(ms)
#define	FRAME_RATE		60
#define	FRAME_PERIOD		(1000.0f/(FLOAT)FRAME_RATE)

// class prototypes
class	CPU;
class	PPU;
class	APU;
class	ROM;
class	PAD;
class	Mapper;

//
// NES クラス
//
class NES
{
public:
	NES( const char* fname );
	virtual	~NES();

// メンバ関数
	// エミュレーション
	void	Reset();
	void	SoftReset();

	void	Clock( INT cycles );

	BYTE	Read ( WORD addr );
	void	Write( WORD addr, BYTE data );

	void	EmulationCPU( INT basecycles );

	void	EmulateFrame( BOOL bDraw );

	// Frame-IRQ control (for Paris-Dakar Rally Special)
	void	SetFrameIRQmode( BOOL bMode ) { bFrameIRQ = bMode; }

	//
	INT	GetDiskNo();
	void	SoundSetup();

	INT	GetScanline()	{ return NES_scanline; }
	BOOL	GetZapperHit()	{ return bZapper; }
	void	GetZapperPos( LONG&x, LONG&y )	{ x = ZapperX; y = ZapperY; }
	void	SetZapperPos( LONG x, LONG y )	{ ZapperX = x; ZapperY = y; }

	// ステートファイル
	static	BOOL	IsStateFile( const char* fname );
	BOOL	LoadState( const char* fname );
	BOOL	SaveState( const char* fname );

	INT	GetSAVERAM_SIZE()		{ return SAVERAM_SIZE; }
	void	SetSAVERAM_SIZE( INT size )	{ SAVERAM_SIZE = size; }

	// スナップショット
	BOOL	Snapshot();

	// For Movie
	static	BOOL	IsMovieFile( const char* fname );

	BOOL	IsMoviePlay() { return m_bMoviePlay; }
	BOOL	IsMovieRec() { return m_bMovieRec; }
	BOOL	MoviePlay( const char* fname );
	BOOL	MovieRec( const char* fname );
	BOOL	MovieRecAppend( const char* fname );
	BOOL	MovieStop();

	// その他コントロール
	BOOL	IsDiskThrottle() { return m_bDiskThrottle; }
//	BOOL	IsBraking() { return m_bBrake; }	// Debugger

	// 描画方式
	enum RENDERMETHOD { 
		POST_ALL_RENDER = 0, // スキャンライン分の命令実行後，レンダリング
		PRE_ALL_RENDER  = 1, // レンダリングの実行後，スキャンライン分の命令実行
		POST_RENDER     = 2, // 表示期間分の命令実行後，レンダリング
		PRE_RENDER      = 3, // レンダリング実行後，表示期間分の命令実行
		TILE_RENDER     = 4  // タイルベースレンダリング
	};
	void		SetRenderMethod( RENDERMETHOD type )	{ RenderMethod = type; }
	RENDERMETHOD	GetRenderMethod()			{ return RenderMethod; }

	// コマンド
	enum NESCOMMAND {
		NESCMD_NONE = 0,
		NESCMD_HWRESET,
		NESCMD_SWRESET,
		NESCMD_EXCONTROLLER,	// Commandparam
		NESCMD_DISK_THROTTLE_ON,
		NESCMD_DISK_THROTTLE_OFF,
		NESCMD_DISK_EJECT,
		NESCMD_DISK_0A,
		NESCMD_DISK_0B,
		NESCMD_DISK_1A,
		NESCMD_DISK_1B,

		NESCMD_SOUND_MUTE,	// CommandParam
	};

	void	Command( NESCOMMAND cmd );
	BOOL	CommandParam( NESCOMMAND cmd, INT param );

	// For Movie
	void	Movie();
	void	GetMovieInfo( WORD& wVersion, DWORD& dwRecordFrames, DWORD& dwRecordTimes );

	// For Cheat
	void	CheatInitial();

	BOOL	IsCheatCodeAdd();

	INT	GetCheatCodeNum();
	BOOL	GetCheatCode( INT no, CHEATCODE& code );
	void	SetCheatCodeFlag( INT no, BOOL bEnable );
	void	SetCheatCodeAllFlag( BOOL bEnable, BOOL bKey );

	void	ReplaceCheatCode( INT no, CHEATCODE code );
	void	AddCheatCode( CHEATCODE code );
	void	DelCheatCode( INT no );

	DWORD	CheatRead( INT length, WORD addr );
	void	CheatWrite( INT length, WORD addr, DWORD data );
	void	CheatCodeProcess();

	// For Genie
	void	GenieInitial();
	void	GenieLoad( char* fname );
	void	GenieCodeProcess();

public:
// メンバ変数
	CPU*	cpu;
	PPU*	ppu;
	APU*	apu;
	ROM*	rom;
	PAD*	pad;
	Mapper*	mapper;

protected:
// メンバ関数
	// エミュレーション
	BYTE	ReadReg ( WORD addr );
	void	WriteReg( WORD addr, BYTE data );

	// ステートサブ
	BOOL	ReadState( FILE* fp );
	void	WriteState( FILE* fp );

	void	LoadSRAM();
	void	SaveSRAM();

	void	LoadDISK();
	void	SaveDISK();

protected:
// メンバ変数
	BOOL	bZapper;
	LONG	ZapperX, ZapperY;

	BOOL	bFrameIRQ;
	BOOL	bFrameIRQ_occur;
	INT	FrameIRQ_cycles;

	BOOL	m_bPadStrobe;

	RENDERMETHOD	RenderMethod;

	BOOL	m_bDiskThrottle;

	SQWORD	base_cycles;
	SQWORD	emul_cycles;

	INT	NES_scanline;

	INT	SAVERAM_SIZE;

	// Snapshot number
	INT	m_nSnapNo;

	// For Movie
	BOOL	m_bMoviePlay;
	BOOL	m_bMovieRec;
	WORD	m_MovieVersion;

	FILE*	m_fpMovie;

	MOVIEFILEHDR	m_hedMovie;
	MOVIEIMGFILEHDR	m_hedMovieOld;

	DWORD	m_MovieControl;
	LONG	m_MovieStepTotal;
	LONG	m_MovieStep;
	INT	m_CommandRequest;

	// For Cheat
	BOOL	m_bCheatCodeAdd;
	vector<CHEATCODE>	m_CheatCode;

	// For Genie
	vector<GENIECODE>	m_GenieCode;
private:
};

#endif	// !__NES_INCLUDED__

