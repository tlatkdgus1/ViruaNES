/*----------------------------------------------------------------------*/
/*                                                                      */
/*      NES Mapper                                                      */
/*                                                           Norix      */
/*                                               written     2001/02/05 */
/*                                               last modify ----/--/-- */
/*----------------------------------------------------------------------*/
#ifndef	__MAPPER_INCLUDED__
#define	__MAPPER_INCLUDED__

#define	WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "typedef.h"
#include "macro.h"

// class prototype
class	NES;

// Mapper base class
class	Mapper
{
public:
	Mapper( NES* parent );
	virtual	~Mapper();

	// For Mapper
	// Reset
	virtual	void	Reset() = 0;

	// $8000-$FFFF Memory write
	virtual	void	Write( WORD addr, BYTE data ) {}

	// $4100-$7FFF Lower Memory read/write
	virtual	BYTE	ReadLow ( WORD addr );
	virtual	void	WriteLow( WORD addr, BYTE data );

	// $4018-$40FF Extention register read/write
	virtual	BYTE	ExRead ( WORD addr )	{ return 0x00; }
	virtual	void	ExWrite( WORD addr, BYTE data ) {}

	// Extension commands
	// For ExCmdRead command
	enum	EXCMDRD {
		EXCMDRD_NONE = 0,
	};
	// For ExCmdWrite command
	enum	EXCMDWR {
		EXCMDWR_NONE = 0,
		EXCMDWR_DISKINSERT,
		EXCMDWR_DISKEJECT,
	};

	virtual	BYTE	ExCmdRead ( EXCMDRD cmd )	{ return 0x00; }
	virtual	void	ExCmdWrite( EXCMDWR cmd, BYTE data ) {}

	// H sync/V sync/Clock sync
	virtual	void	HSync( INT scanline ) {}
	virtual	void	VSync() {}
	virtual	void	Clock( INT cycles ) {}

	// PPU address bus latch
	virtual	void	PPU_Latch( WORD addr ) {}

	// PPU Character latch
	virtual	void	PPU_ChrLatch( WORD addr ) {}

	// PPU Extention character/palette
	virtual	void	PPU_ExtLatchX( INT x ) {}
	virtual	void	PPU_ExtLatch( WORD addr, BYTE& chr_l, BYTE& chr_h, BYTE& attr ) {}

	// For State save
	virtual	BOOL	IsStateSave() { return FALSE; }
	virtual	void	SaveState( LPBYTE p ) {}
	virtual	void	LoadState( LPBYTE p ) {}

protected:
	NES*	nes;

private:
};

// Create class instance
extern	Mapper*	CreateMapper( NES* parent, INT no );

#include "Mapper000.h"
#include "Mapper001.h"
#include "Mapper002.h"
#include "Mapper003.h"
#include "Mapper004.h"
#include "Mapper005.h"
#include "Mapper006.h"
#include "Mapper007.h"
#include "Mapper008.h"
#include "Mapper009.h"
#include "Mapper010.h"
#include "Mapper011.h"
#include "Mapper013.h"
#include "Mapper015.h"
#include "Mapper016.h"
#include "Mapper017.h"
#include "Mapper018.h"
#include "Mapper019.h"
#include "MapperFDS.h"	// 020
#include "Mapper021.h"
#include "Mapper022.h"
#include "Mapper023.h"
#include "Mapper024.h"
#include "Mapper025.h"
#include "Mapper026.h"
#include "Mapper032.h"
#include "Mapper033.h"
#include "Mapper034.h"
#include "Mapper040.h"
#include "Mapper041.h"
#include "Mapper042.h"
#include "Mapper043.h"
#include "Mapper048.h"
#include "Mapper064.h"
#include "Mapper065.h"
#include "Mapper066.h"
#include "Mapper067.h"
#include "Mapper068.h"
#include "Mapper069.h"
#include "Mapper070.h"
#include "Mapper071.h"
#include "Mapper072.h"
#include "Mapper073.h"
#include "Mapper075.h"
#include "Mapper076.h"
#include "Mapper077.h"
#include "Mapper078.h"
#include "Mapper079.h"
#include "Mapper080.h"
#include "Mapper082.h"
#include "Mapper083.h"
#include "Mapper085.h"
#include "Mapper086.h"
#include "Mapper087.h"
#include "Mapper088.h"
#include "Mapper089.h"
#include "Mapper092.h"
#include "Mapper093.h"
#include "Mapper094.h"
#include "Mapper095.h"
#include "Mapper096.h"
#include "Mapper097.h"
#include "Mapper100.h"
#include "Mapper101.h"
#include "Mapper107.h"
#include "Mapper118.h"
#include "Mapper119.h"
#include "Mapper122.h"
#include "Mapper180.h"
#include "Mapper185.h"
#include "Mapper188.h"
#include "Mapper189.h"

#include "MapperNSF.h"

#endif
