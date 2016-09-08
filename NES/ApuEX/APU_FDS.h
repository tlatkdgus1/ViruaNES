//////////////////////////////////////////////////////////////////////////
//                                                                      //
//      FDS plugin                                                      //
//                                                           Norix      //
//                                               written     2001/09/18 //
//                                               last modify ----/--/-- //
//////////////////////////////////////////////////////////////////////////
#ifndef	__FDSPLUGIN_INCLUDED__
#define	__FDSPLUGIN_INCLUDED__

#define	WIN32_LEAN_AND_MEAN
#include "windows.h"

#include "typedef.h"
#include "macro.h"

#include "APU_INTERFACE.h"
#include "FDSplugin.h"

class	CFDSplugin
{
public:
	CFDSplugin();
	~CFDSplugin();

	static	HINSTANCE GetFDSpluginHandle() { return hFDSplugin; }
protected:
	// FDS Plugin
	static	HINSTANCE	hFDSplugin;

private:
};

class	APU_FDS : public APU_INTERFACE
{
public:
	APU_FDS();
	~APU_FDS();

	void	Reset( INT nRate );
	void	Setup( INT nRate );
	void	Write( WORD addr, BYTE data );
	BYTE	Read ( WORD addr );
	INT	Process( INT channel );

	void	WriteSync( WORD addr, BYTE data );
	BYTE	ReadSync ( WORD addr );
	BOOL	Sync( INT cycles );

	INT	GetFreq( INT channel );

protected:
	// FDS Plugin
	HFDS		hFDS;
	FDSCREATE	FDSplug_Create;
	FDSCLOSE	FDSplug_Close;
	FDSRESET	FDSplug_Reset;
	FDSSETUP	FDSplug_Setup;
	FDSWRITE	FDSplug_Write;
	FDSREAD		FDSplug_Read;
	FDSPROCESS	FDSplug_Process;

	FDSWRITESYNC	FDSplug_WriteSync;
	FDSREADSYNC	FDSplug_ReadSync;
	FDSSYNC		FDSplug_Sync;

	FDSGETFREQ	FDSplug_GetFreq;
private:

};

#endif	// !__FDSPLUGIN_INCLUDED__
