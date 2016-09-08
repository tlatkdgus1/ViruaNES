//////////////////////////////////////////////////////////////////////////
//                                                                      //
//      NES ROM Cartridge class                                         //
//                                                           Norix      //
//                                               written     2001/02/20 //
//                                               last modify ----/--/-- //
//////////////////////////////////////////////////////////////////////////
#ifndef	__ROM_INCLUDED__
#define	__ROM_INCLUDED__

#include <list>
#include <string>
using namespace std;

#include "typedef.h"
#include "macro.h"

#pragma pack( push, 1 )

typedef	struct	tagNESHEADER {
	BYTE	ID[4];
	BYTE	PRG_PAGE_SIZE;
	BYTE	CHR_PAGE_SIZE;
	BYTE	control1;
	BYTE	control2;
	BYTE	reserved[8];
} NESHEADER;

typedef	struct	tagNSFHEADER {
	BYTE	ID[5];
	BYTE	Version;
	BYTE	TotalSong;
	BYTE	StartSong;
	WORD	LoadAddress;
	WORD	InitAddress;
	WORD	PlayAddress;
	BYTE	SongName[32];
	BYTE	ArtistName[32];
	BYTE	CopyrightName[32];
	WORD	SpeedNTSC;
	BYTE	BankSwitch[8];
	WORD	SpeedPAL;
	BYTE	NTSC_PALbits;
	BYTE	ExtraChipSelect;
	BYTE	Expansion[4];		// must be 0
} NSFHEADER;

#pragma pack( pop )

class	ROM
{
public:
	ROM( const char* fname );
	virtual	~ROM();

	// ROM control byte #1
	enum {	ROM_VMIRROR = 0x01, ROM_SAVERAM = 0x02,
		ROM_TRAINER = 0x04, ROM_4SCREEN = 0x08 };

	// Get NESHEADER
	NESHEADER* GetNesHeader() { return &header; }
	// Get NSFHEADER
	NSFHEADER* GetNsfHeader() { return &nsfheader; }

	// Get ROM buffer pointer
	LPBYTE	GetPROM()	{ return lpPRG; }
	LPBYTE	GetVROM()	{ return lpCHR; }
	LPBYTE	GetTRAINER()	{ return lpTrainer; }
	LPBYTE	GetDISKBIOS()	{ return lpDiskBios; }
	LPBYTE	GetDISK()	{ return lpDisk; }

	// Get ROM size
	BYTE	GetPROM_SIZE()	{ return header.PRG_PAGE_SIZE; }
	BYTE	GetVROM_SIZE()	{ return header.CHR_PAGE_SIZE; }

	// Get PROM
	DWORD	GetPROM_CRC()	{ return crc; }
	DWORD	GetROM_CRC()	{ return crcall; }

	// Get FDS ID
	DWORD	GetMakerID()	{ return fdsmakerID; }
	DWORD	GetGameID()	{ return fdsgameID; }

	// ROM control
	BOOL	IsVMIRROR() { return header.control1 & ROM_VMIRROR; }
	BOOL	Is4SCREEN() { return header.control1 & ROM_4SCREEN; }
	BOOL	IsSAVERAM() { return header.control1 & ROM_SAVERAM; }
	BOOL	IsTRAINER() { return header.control1 & ROM_TRAINER; }

	// Mapper
	INT	GetMapperNo() { return mapper; }

	// Disks
	INT	GetDiskNo() { return diskno; }

	// NSF
	BOOL	IsNSF() { return bNSF; }
	BYTE	GetNSF_SIZE()	{ return NSF_PAGE_SIZE; }

	// ROM Paths
	const char*	GetRomPath() { return path; }
	const char*	GetRomName() { return name; }

	// File check
	static	BOOL	IsRomFile( const char* fname );

protected:
	NESHEADER	header;
	NSFHEADER	nsfheader;
	LPBYTE		lpPRG;
	LPBYTE		lpCHR;
	LPBYTE		lpTrainer;
	LPBYTE		lpDiskBios;
	LPBYTE		lpDisk;

	// PROM CRC
	DWORD		crc;
	DWORD		crcall;

	DWORD		fdsmakerID, fdsgameID;

	INT		mapper;
	INT		diskno;

	// For NSF
	BOOL		bNSF;
	INT		NSF_PAGE_SIZE;

	CHAR		path[_MAX_PATH];
	CHAR		name[_MAX_FNAME];

private:
};

//
// ROM DATABASE (NESToy&NNNesterJ database)
//
class	ROMDB
{
public:
	DWORD	crcall;		// ALL CRC
	DWORD	crc;		// PRG CRC

	BYTE	control1;
	BYTE	control2;
	BYTE	prg_size;
	BYTE	chr_size;

	string	title;
	string	country;
	string	manufacturer;
	string	saledate;
	string	price;
	string	genre;

	BOOL	bNTSC;		// NTSC:TRUE  PAL:FALSE
};

class	ROMDATABASE
{
public:
	INT	HeaderCheck  ( NESHEADER& hdr, DWORD crcall, DWORD crc, ROMDB& data );
	BOOL	HeaderCorrect( NESHEADER& hdr, DWORD crcall, DWORD crc );

protected:
	void	LoadDatabase();

	list<ROMDB>	m_DataBaseList;

private:
};

extern	ROMDATABASE	romdatabase;

/*
  A. iNES Format (.NES)
  ---------------------
    +--------+------+------------------------------------------+
    | Offset | Size | Content(s)                               |
    +--------+------+------------------------------------------+
    |   0    |  3   | 'NES'                                    |
    |   3    |  1   | $1A                                      |
    |   4    |  1   | 16K PRG-ROM page count                   |
    |   5    |  1   |  8K CHR-ROM page count                   |
    |   6    |  1   | ROM Control Byte #1                      |
    |        |      |   %####vTsM                              |
    |        |      |    |  ||||+- 0=Horizontal mirroring      |
    |        |      |    |  ||||   1=Vertical mirroring        |
    |        |      |    |  |||+-- 1=SRAM enabled              |
    |        |      |    |  ||+--- 1=512-byte trainer present  |
    |        |      |    |  |+---- 1=Four-screen mirroring     |
    |        |      |    |  |                                  |
    |        |      |    +--+----- Mapper # (lower 4-bits)     |
    |   7    |  1   | ROM Control Byte #2                      |
    |        |      |   %####00PV                              |
    |        |      |    |  |  |+- 1=VS-Unisystem Images       |
    |        |      |    |  |  +-- 1=PlayChoice10 Images       |
    |        |      |    |  |                                  |
    |        |      |    +--+----- Mapper # (upper 4-bits)     |
    |  8-15  |  8   | $00                                      |
    | 16-..  |      | Actual 16K PRG-ROM pages (in linear      |
    |  ...   |      | order). If a trainer exists, it precedes |
    |  ...   |      | the first PRG-ROM page.                  |
    | ..-EOF |      | CHR-ROM pages (in ascending order).      |
    +--------+------+------------------------------------------+
*/

#endif	// !__ROM_INCLUDED__
