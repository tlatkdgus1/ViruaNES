//Famicom Disk System

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//      FDS plugin                                                      //
//                                                           Norix      //
//                                               written     2001/09/18 //
//                                               last modify ----/--/-- //
//////////////////////////////////////////////////////////////////////////
#include "DebugOut.h"

#include "APU_FDS.h"

HINSTANCE CFDSplugin::hFDSplugin = NULL;

// プラグインをロ?ドしておく為だけのインス?ンス(ぉ
CFDSplugin FDSplugin;

CFDSplugin::CFDSplugin()
{
	hFDSplugin = ::LoadLibrary( "fdsplugin.dll" );
}

CFDSplugin::~CFDSplugin()
{
	if( hFDSplugin ) {
		::FreeLibrary( hFDSplugin );
		hFDSplugin = NULL;
	}
}

APU_FDS::APU_FDS()
{
	hFDS = NULL;
	HINSTANCE hFDSplugin = CFDSplugin::GetFDSpluginHandle();
	if( hFDSplugin ) {
		FDSplug_Create    = (FDSCREATE   )::GetProcAddress( hFDSplugin, "FDS_Create" );
		FDSplug_Close     = (FDSCLOSE    )::GetProcAddress( hFDSplugin, "FDS_Close" );
		FDSplug_Reset     = (FDSRESET    )::GetProcAddress( hFDSplugin, "FDS_Reset" );
		FDSplug_Setup     = (FDSSETUP    )::GetProcAddress( hFDSplugin, "FDS_Setup" );
		FDSplug_Write     = (FDSWRITE    )::GetProcAddress( hFDSplugin, "FDS_Write" );
		FDSplug_Read      = (FDSREAD     )::GetProcAddress( hFDSplugin, "FDS_Read" );
		FDSplug_Process   = (FDSPROCESS  )::GetProcAddress( hFDSplugin, "FDS_Process" );
		FDSplug_WriteSync = (FDSWRITESYNC)::GetProcAddress( hFDSplugin, "FDS_WriteSync" );
		FDSplug_ReadSync  = (FDSREADSYNC )::GetProcAddress( hFDSplugin, "FDS_ReadSync" );
		FDSplug_Sync      = (FDSSYNC     )::GetProcAddress( hFDSplugin, "FDS_Sync" );
		FDSplug_GetFreq   = (FDSGETFREQ  )::GetProcAddress( hFDSplugin, "FDS_GetFreq" );

		if( !(!FDSplug_Create || !FDSplug_Close || !FDSplug_Reset || !FDSplug_Setup || !FDSplug_Write || !FDSplug_Read || !FDSplug_Process
		 || !FDSplug_WriteSync || !FDSplug_ReadSync || !FDSplug_Sync || !FDSplug_GetFreq) ) {
			if( (hFDS = FDSplug_Create()) ) {
				FDSplug_Reset( hFDS, 22050 );	// 仮の周波数
			}
		}
	}
}

APU_FDS::~APU_FDS()
{
	if( hFDS ) {
		FDSplug_Close( hFDS );
		hFDS = NULL;
	}
}

void	APU_FDS::Reset( INT nRate )
{
	if( hFDS ) {
		FDSplug_Reset( hFDS, nRate );
	}
}

void	APU_FDS::Setup( INT nRate )
{
	if( hFDS ) {
		FDSplug_Setup( hFDS, nRate );
	}
}

void	APU_FDS::Write( WORD addr, BYTE data )
{
	if( hFDS ) {
		FDSplug_Write( hFDS, addr, data );
	}
}

BYTE	APU_FDS::Read ( WORD addr )
{
	if( hFDS ) {
		return	FDSplug_Read( hFDS, addr );
	}
	return	0;
}

INT	APU_FDS::Process( INT channel )
{
	if( hFDS ) {
		return	FDSplug_Process( hFDS );
	}
	return	0;
}

void	APU_FDS::WriteSync( WORD addr, BYTE data )
{
	if( hFDS ) {
		FDSplug_WriteSync( hFDS, addr, data );
	}
}

BYTE	APU_FDS::ReadSync( WORD addr )
{
BYTE	data = 0;

	if( hFDS ) {
		data = FDSplug_ReadSync( hFDS, addr );
	}

	return	data;
}

// hFDS default = NULL
// FDSplug_Sync()ﾀｺ FDSplugin.dllﾀﾇ FDS_Syncｸｦ ｽﾇﾇ猊ﾔ. 
BOOL	APU_FDS::Sync( INT cycles )
{
	if( hFDS ) {
		FDSplug_Sync( hFDS, cycles );
	}
	return	FALSE;
}

INT	APU_FDS::GetFreq( INT channel )
{
	if( hFDS ) {
		return	FDSplug_GetFreq( hFDS );
	}
	return	0;
}

