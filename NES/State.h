#ifndef	__STATE_INCLUDED__
#define	__STATE_INCLUDED__

#pragma pack( push, 1 )

typedef	struct	tagFILEHDR {	//  0123456789AB
	BYTE	ID[12];		// "VirtuaNES ST"
	WORD	Reserved;
	WORD	BlockVersion;
} FILEHDR, *LPFILEHDR;

// VirtuaNES version0.30以降用
typedef	struct	tagFILEHDR2 {	//  0123456789AB
	BYTE	ID[12];		// "VirtuaNES ST"
	WORD	Reserved;
	WORD	BlockVersion;	// 0x0200

	DWORD	Ext0;		// ROM:プログラムCRC	FDS:プログラムID
	WORD	Ext1;		// ROM:なし		FDS:メーカーID
	WORD	Ext2;		// ROM:なし		FDS:ディスク枚数
	LONG	MovieStep;	// 追記(取り直し)ムービー時のフレーム数
	LONG	MovieOffset;	// 追記(取り直し)ムービー時のファイルオフセット
} FILEHDR2, *LPFILEHDR2;

typedef	struct	tagBLOCKHDR {
	BYTE	ID[8];
	WORD	Reserved;
	WORD	BlockVersion;
	DWORD	BlockSize;
} BLOCKHDR, *LPBLOCKHDR;

// CPU レジスタ
typedef	struct	tagCPUSTAT {
	WORD	PC;
	BYTE	A;
	BYTE	X;
	BYTE	Y;
	BYTE	S;
	BYTE	P;
	BYTE	I;	// Interrupt pending flag

	BYTE	FrameIRQ;
	BYTE	reserved[3];

	LONG	mod_cycles;	// ムービー等でクロック数の微妙なずれを防ぐ為
} CPUSTAT, *LPCPUSTAT;

// PPU レジスタ
typedef	struct	tagPPUSTAT {
	BYTE	reg0;
	BYTE	reg1;
	BYTE	reg2;
	BYTE	reg3;
	BYTE	reg7;
	BYTE	toggle56;

	WORD	loopy_t;
	WORD	loopy_v;
	WORD	loopy_x;
} PPUSTAT, *LPPPUSTAT;

// APU レジスタ(拡張サウンド含む)
typedef	struct	tagAPUSTAT {
	BYTE	reg[0x0018];
	BYTE	ext[0x0100];
} APUSTAT, *LPAPUSTAT;

//
// レジスタデータ
// ID "REG DATA"
typedef	struct	tagREGSTAT {
	union	CPUREG {
		BYTE	cpudata[32];
		CPUSTAT	cpu;
	} cpureg;
	union	PPUREG {
		BYTE	ppudata[32];
		PPUSTAT	ppu;
	} ppureg;
	APUSTAT	apu;
} REGSTAT, *LPREGSTAT;

//
// 内臓RAMデータ
// ID "RAM DATA"
typedef	struct	tagRAMSTAT {
	BYTE	RAM[2*1024];	// Internal NES RAM
	BYTE	BGPAL[16];	// BG Palette
	BYTE	SPPAL[16];	// SP Palette
	BYTE	SPRAM[256];	// Sprite RAM
} RAMSTAT, *LPRAMSTAT;

//
// MMUデータ
// ID "MMU DATA"
typedef	struct	tagMMUSTAT {
	BYTE	CPU_MEM_TYPE[8];
	WORD	CPU_MEM_PAGE[8];
	BYTE	PPU_MEM_TYPE[12];
	WORD	PPU_MEM_PAGE[12];
	BYTE	CRAM_USED[8];
} MMUSTAT, *LPMMUSTAT;

//
// マッパーデータ
// ID "MMC DATA"
typedef	struct	tagMMCSTAT {
	BYTE	mmcdata[256];
} MMCSTAT, *LPMMCSTAT;

//
// コントローラデータ
// ID "CONTDATA"
typedef	struct	tagCONTSTAT {
	BYTE	type1;
	BYTE	type2;
	BYTE	shift1;
	BYTE	shift2;
	DWORD	data1;
	DWORD	data2;
} CONTSTAT, *LPCONTSTAT;

//
// ディスクイメージ
// Ver0.24まで
// ID "DSIDE 0A","DSIDE 0B","DSIDE 1A","DSIDE 1B"
typedef	struct	tagDISKSTAT {
	BYTE	DiskTouch[16];
} DISKSTAT, *LPDISKSTAT;

// Ver0.30以降
// ID "DISKDATA"
typedef	struct	tagDISKDATA {
	LONG	DifferentSize;
} DISKDATA, *LPDISKDATA;

// 以下はディスクセーブイメージファイルで使用する
// Ver0.24まで
typedef	struct	tagDISKIMGFILEHDR {	//  0123456789AB
	BYTE	ID[12];		// "VirtuaNES DI"
	WORD	BlockVersion;
	WORD	DiskNumber;
} DISKIMGFILEHDR, *LPDISKIMGFILEHDR;

typedef	struct	tagDISKIMGHDR {
	BYTE	ID[6];		// ID "SIDE0A","SIDE0B","SIDE1A","SIDE1B"
	BYTE	DiskTouch[16];
} DISKIMGHDR, *LPDISKIMGHDR;

// VirtuaNES version0.30以降用
typedef	struct	tagDISKFILEHDR {	//  0123456789AB
	BYTE	ID[12];		// "VirtuaNES DI"
	WORD	BlockVersion;	// 0x0200:0.30	0x0210:0.31
	WORD	Reserved;
	DWORD	ProgID;		// プログラムID
	WORD	MakerID;	// メーカーID
	WORD	DiskNo;		// ディスク数
	DWORD	DifferentSize;	// 相違数
} DISKFILEHDR, *LPDISKFILEHDR;


//
// ムービーファイル
//
typedef	struct	tagMOVIEIMGFILEHDR {
	BYTE	ID[12];			// "VirtuaNES MV"
	WORD	BlockVersion;
	WORD	reserved;
	LONG	StateStOffset;		// Movie start state offset
	LONG	StateEdOffset;		// Movie end state offset
	LONG	MovieOffset;		// Movie data offset
	LONG	MovieStep;		// Movie steps
} MOVIEIMGFILEHDR, *LPMOVIEIMGFILEHDR;

// VirtuaNES version0.30以降用
typedef	struct	tagMOVIEFILEHDR {
	BYTE	ID[12];			// "VirtuaNES MV"
	WORD	BlockVersion;		// 0x0200
	WORD	reserved;
	DWORD	Control;		// コントロールバイト
					// 76543210(Bit)
					// E---4321
					// |   |||+-- 1Pデータ
					// |   ||+--- 2Pデータ
					// |   |+---- 3Pデータ
					// |   +----- 4Pデータ
					// +--------- 追記禁止
					// その他コントロールは1P～4P(どれでも良い)の方向キーが
					// 全てONの時，次の４バイトがコントロール用データになる
	DWORD	Ext0;			// ROM:プログラムCRC	FDS:プログラムID
	WORD	Ext1;			// ROM:なし		FDS:メーカーID
	WORD	Ext2;			// ROM:なし		FDS:ディスク枚数
	DWORD	RecordTimes;		// 記録回数(取り直し回数)

	LONG	StateStOffset;		// Movie start state offset
	LONG	StateEdOffset;		// Movie end state offset
	LONG	MovieOffset;		// Movie data offset
	LONG	MovieStep;		// Movie steps(Frame数)

	DWORD	CRC;			// このデータを除くCRC(インチキ防止)
} MOVIEFILEHDR, *LPMOVIEFILEHDR;

// Famtasia Movie....
typedef	struct	tagFMVHDR {
	BYTE	ID[4];			// "FMV^Z"
	BYTE	Control1;		// R???????	0:リセット後から記録？ 1:途中から記録
	BYTE	Control2;		// OT??????	O:1P情報 T:2P情報
	DWORD	Unknown1;
	WORD	RecordTimes;		// 記録回数-1
	DWORD	Unknown2;
	BYTE	szEmulators[0x40];	// 記録したエミュレータ
	BYTE	szTitle    [0x40];	// タイトル
} FMVHDR, *LPFMVHDR;

// Nesticle Movie....
typedef	struct	tagNMVHDR {
	BYTE	ExRAM[0x2000];
	BYTE	S_RAM[0x0800];
	WORD	PC;
	BYTE	A;
	BYTE	P;
	BYTE	X;
	BYTE	Y;
	BYTE	SP;
	BYTE	OAM[0x0100];
	BYTE	VRAM[0x4000];
	BYTE	Other[0xC9];
	DWORD	ScanlineCycles;
	DWORD	VblankScanlines;
	DWORD	FrameScanlines;
	DWORD	VirtualFPS;
} NMVHDR, *LPNMVHDR;

#pragma pack( pop )

#endif	// !__STATE_INCLUDED__
