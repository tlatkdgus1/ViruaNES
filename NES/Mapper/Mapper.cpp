/*----------------------------------------------------------------------*/
/*                                                                      */
/*      NES Mapeers                                                     */
/*                                                           Norix      */
/*                                               written     2000/02/05 */
/*                                               last modify ----/--/-- */
/*----------------------------------------------------------------------*/
/*--------------[ INCLUDE               ]-------------------------------*/
#define	WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "DebugOut.h"
#include "typedef.h"
#include "macro.h"

#include "nes.h"
#include "mmu.h"
#include "cpu.h"
#include "ppu.h"
#include "apu.h"
#include "pad.h"
#include "rom.h"

#include "mapper.h"

//#include "DirectDraw.h"
//#include "DirectSound.h"
//#include "DirectInput.h"

/*--------------[ DEFINE                ]-------------------------------*/
/*--------------[ EXTERNAL PROGRAM      ]-------------------------------*/
/*--------------[ EXTERNAL WORK         ]-------------------------------*/
/*--------------[ WORK                  ]-------------------------------*/
/*--------------[ PROTOTYPE             ]-------------------------------*/
/*--------------[ CONST                 ]-------------------------------*/
/*--------------[ PROGRAM               ]-------------------------------*/

//////////////////////////////////////////////////////////////////////////
// Based class implement
//////////////////////////////////////////////////////////////////////////
Mapper::Mapper( NES* parent ) : nes(parent)
{
}

Mapper::~Mapper()
{
}

// $4100-$7FFF Lower Memory read
BYTE	Mapper::ReadLow( WORD addr )
{
	// $6000-$7FFF WRAM
	if( addr >= 0x6000 ) {
		return	CPU_MEM_BANK[addr>>13][addr&0x1FFF];
	}

	return	(BYTE)(addr>>8);
}

// $4100-$7FFF Lower Memory write
void	Mapper::WriteLow( WORD addr, BYTE data )
{
	// $6000-$7FFF WRAM
	if( addr >= 0x6000 ) {
		CPU_MEM_BANK[addr>>13][addr&0x1FFF] = data;
	}
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#include "Mapper000.cpp"
#include "Mapper001.cpp"
#include "Mapper002.cpp"
#include "Mapper003.cpp"
#include "Mapper004.cpp"
#include "Mapper005.cpp"
#include "Mapper006.cpp"
#include "Mapper007.cpp"
#include "Mapper008.cpp"
#include "Mapper009.cpp"
#include "Mapper010.cpp"
#include "Mapper011.cpp"
#include "Mapper013.cpp"
#include "Mapper015.cpp"
#include "Mapper016.cpp"
#include "Mapper017.cpp"
#include "Mapper018.cpp"
#include "Mapper019.cpp"
#include "MapperFDS.cpp"	// 020
#include "Mapper021.cpp"
#include "Mapper022.cpp"
#include "Mapper023.cpp"
#include "Mapper024.cpp"
#include "Mapper025.cpp"
#include "Mapper026.cpp"
#include "Mapper032.cpp"
#include "Mapper033.cpp"
#include "Mapper034.cpp"
#include "Mapper040.cpp"
#include "Mapper041.cpp"
#include "Mapper042.cpp"
#include "Mapper043.cpp"
#include "Mapper048.cpp"
#include "Mapper064.cpp"
#include "Mapper065.cpp"
#include "Mapper066.cpp"
#include "Mapper067.cpp"
#include "Mapper068.cpp"
#include "Mapper069.cpp"
#include "Mapper070.cpp"
#include "Mapper071.cpp"
#include "Mapper072.cpp"
#include "Mapper073.cpp"
#include "Mapper075.cpp"
#include "Mapper076.cpp"
#include "Mapper077.cpp"
#include "Mapper078.cpp"
#include "Mapper079.cpp"
#include "Mapper080.cpp"
#include "Mapper082.cpp"
#include "Mapper083.cpp"
#include "Mapper085.cpp"
#include "Mapper086.cpp"
#include "Mapper087.cpp"
#include "Mapper088.cpp"
#include "Mapper089.cpp"
#include "Mapper092.cpp"
#include "Mapper093.cpp"
#include "Mapper094.cpp"
#include "Mapper095.cpp"
#include "Mapper096.cpp"
#include "Mapper097.cpp"
#include "Mapper100.cpp"
#include "Mapper101.cpp"
#include "Mapper107.cpp"
#include "Mapper118.cpp"
#include "Mapper119.cpp"
#include "Mapper122.cpp"
#include "Mapper180.cpp"
#include "Mapper185.cpp"
#include "Mapper188.cpp"
#include "Mapper189.cpp"

#include "MapperNSF.cpp"

//////////////////////////////////////////////////////////////////////////
// Create mapper class instance
//////////////////////////////////////////////////////////////////////////
Mapper*	CreateMapper( NES* parent, INT no )
{
	switch( no ) {
		case	0:
			return new Mapper000(parent);
		case	1:
			return new Mapper001(parent);
		case	2:
			return new Mapper002(parent);
		case	3:
			return new Mapper003(parent);
		case	4:
			return new Mapper004(parent);
		case	5:
			return new Mapper005(parent);
		case	6:
			return new Mapper006(parent);
		case	7:
			return new Mapper007(parent);
		case	8:
			return new Mapper008(parent);
		case	9:
			return new Mapper009(parent);
		case	10:
			return new Mapper010(parent);
		case	11:
			return new Mapper011(parent);
		case	13:
			return new Mapper013(parent);
		case	15:
			return new Mapper015(parent);
		case	16:
			return new Mapper016(parent);
		case	17:
			return new Mapper017(parent);
		case	18:
			return new Mapper018(parent);
		case	19:
			return new Mapper019(parent);
		case	20:
			return new Mapper020(parent);
		case	21:
			return new Mapper021(parent);
		case	22:
			return new Mapper022(parent);
		case	23:
			return new Mapper023(parent);
		case	24:
			return new Mapper024(parent);
		case	25:
			return new Mapper025(parent);
		case	26:
			return new Mapper026(parent);
		case	32:
			return new Mapper032(parent);
		case	33:
			return new Mapper033(parent);
		case	34:
			return new Mapper034(parent);
		case	40:
			return new Mapper040(parent);
		case	41:
			return new Mapper041(parent);
		case	42:
			return new Mapper042(parent);
		case	43:
			return new Mapper043(parent);
		case	48:
			return new Mapper048(parent);
		case	64:
			return new Mapper064(parent);
		case	65:
			return new Mapper065(parent);
		case	66:
			return new Mapper066(parent);
		case	67:
			return new Mapper067(parent);
		case	68:
			return new Mapper068(parent);
		case	69:
			return new Mapper069(parent);
		case	70:
			return new Mapper070(parent);
		case	71:
			return new Mapper071(parent);
		case	72:
			return new Mapper072(parent);
		case	73:
			return new Mapper073(parent);
		case	75:
			return new Mapper075(parent);
		case	76:
			return new Mapper076(parent);
		case	77:
			return new Mapper077(parent);
		case	78:
			return new Mapper078(parent);
		case	79:
			return new Mapper079(parent);
		case	80:
			return new Mapper080(parent);
		case	82:
			return new Mapper082(parent);
		case	83:
			return new Mapper083(parent);
		case	85:
			return new Mapper085(parent);
		case	86:
			return new Mapper086(parent);
		case	87:
			return new Mapper087(parent);
		case	88:
			return new Mapper088(parent);
		case	89:
			return new Mapper089(parent);
		case	92:
			return new Mapper092(parent);
		case	93:
			return new Mapper093(parent);
		case	94:
			return new Mapper094(parent);
		case	95:
			return new Mapper095(parent);
		case	96:
			return new Mapper096(parent);
		case	97:
			return new Mapper097(parent);
		case	100:
			return new Mapper100(parent);
		case	101:
			return new Mapper101(parent);
		case	107:
			return new Mapper107(parent);
		case	118:
			return new Mapper118(parent);
		case	119:
			return new Mapper119(parent);
		case	122:
		case	184:
			return new Mapper122(parent);
		case	180:
			return new Mapper180(parent);
		case	185:
			return new Mapper185(parent);
		case	188:
			return new Mapper188(parent);
		case	189:
			return new Mapper189(parent);
		case	0x100:
			return new MapperNSF(parent);
		default:
			break;
	}

	return	NULL;
}

