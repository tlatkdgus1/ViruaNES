//////////////////////////////////////////////////////////////////////////
//                                                                      //
//      NES Pad                                                         //
//                                                           Norix      //
//                                               written     2001/02/22 //
//                                               last modify ----/--/-- //
//////////////////////////////////////////////////////////////////////////

#ifndef	__PAD_INCLUDED__
#define	__PAD_INCLUDED__

#include "typedef.h"
#include "macro.h"

// class prototypes
class	NES;
class	EXPAD;

class	PAD
{
public:
	PAD( NES* parent );
	virtual	~PAD();

// ÉÅÉìÉoä÷êî
	void	Reset();

	// For movie
	DWORD	GetSyncData();
	void	SetSyncData( DWORD data );
	DWORD	GetSyncExData();
	void	SetSyncExData( DWORD data );

	void	Sync();
	BYTE	SyncSub( INT no );

	void	Strobe();
	WORD	StrobeSub( INT no );

	BYTE	Read( WORD addr );
	void	Write( WORD addr, BYTE data );

	void	SetExController( INT type );
	INT	GetExController()	    { return excontroller_select; }

	BOOL	IsZapperMode() { return bZapperMode; };

	enum	EXCONTROLLER {
		EXCONTROLLER_NONE = 0,
		EXCONTROLLER_PADDLE,
		EXCONTROLLER_HYPERSHOT,
		EXCONTROLLER_ZAPPER,
		EXCONTROLLER_KEYBOARD,
		EXCONTROLLER_CRAZYCLIMBER,
		EXCONTROLLER_TOPRIDER,
		EXCONTROLLER_SPACESHADOWGUN,
	};

	DWORD	pad1bit, pad2bit;
	DWORD	pad3bit, pad4bit;

	// Frame Synchronized
	LONG	zapperx, zappery;
	BYTE	zapperbit;
	BYTE	crazyclimberbit;

	// For NSF Player
	BYTE	GetNsfController() { return nsfbit; }

protected:
	NES*	nes;
	// Extension Devices
	EXPAD*	expad;

	// Frame Synchronized
	BYTE	padbit[4];
	BYTE	micbit;

	INT	excontroller_select;
	INT	padcnt[4][2];

	BOOL	bStrobe;
	BOOL	bZapperMode;

	// For NSF Player
	void	NsfSub();

	BYTE	nsfbit;
private:
};

#include "EXPAD.h"
#include "EXPAD_Zapper.h"
#include "EXPAD_Paddle.h"
#include "EXPAD_HyperShot.h"
#include "EXPAD_Keyboard.h"
#include "EXPAD_CrazyClimber.h"
#include "EXPAD_Toprider.h"
#include "EXPAD_SpaceShadowGun.h"

#endif	// !__PAD_INCLUDED__

