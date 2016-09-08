//
// Debug output
//
#include "DebugOut.h"

CDebugOut	Dbg;

static const CHAR szClassName[] = "DebugWindow_wndclass";

CDebugOut::CDebugOut()
{
	hWndDebugOutput = ::FindWindow( szClassName, NULL );
	if( !hWndDebugOutput ) {
		::OutputDebugString( "DebugWindow Ç™Ç†ÇËÇ‹ÇπÇÒ\n" );
	}
}

void __cdecl CDebugOut::Out( LPSTR fmt, ... )
{
	CHAR	buf[1000];
	va_list	va;
	va_start( va, fmt );
	::vsprintf( buf, fmt, va );

	if( hWndDebugOutput ) {
		if( ::IsWindow( hWndDebugOutput ) ) {
			COPYDATASTRUCT	cds;
			cds.dwData = 0;
			cds.lpData = (void*)buf;
			cds.cbData = ::strlen(buf)+1; //  èIí[ÇÃNULLÇ‡ëóÇÈ
			//  ï∂éöóÒëóêM
			::SendMessage( hWndDebugOutput, WM_COPYDATA, (WPARAM)NULL, (LPARAM)&cds );
		} else {
			::OutputDebugString( buf );
		}
	} else {
		::OutputDebugString( buf );
	}
}

void CDebugOut::Out( const string& str )
{
	Out( (LPSTR)str.c_str() );
}

