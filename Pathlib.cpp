//
// パスライブラリクラス
//
#include "Pathlib.h"

string	CPathlib::SplitPath( LPCSTR lpszPath )
{
	CHAR	szDrive[ _MAX_DRIVE ];
	CHAR	szDir  [ _MAX_DIR ];
	string	path;
	path.resize( _MAX_PATH+1 );
	::_splitpath( lpszPath, szDrive, szDir, NULL, NULL );
	::_makepath( (LPSTR)path.data(), szDrive, szDir, NULL, NULL );
	return	path;
}

string	CPathlib::SplitFname( LPCSTR lpszPath )
{
	string	fname;
	fname.resize( _MAX_FNAME+1 );
	::_splitpath( lpszPath, NULL, NULL, (LPSTR)fname.data(), NULL );
	return	fname;
}

string	CPathlib::SplitFnameExt( LPCSTR lpszPath )
{
	CHAR	szFname[ _MAX_FNAME ];
	CHAR	szExt  [ _MAX_EXT ];
	string	fname;
	fname.resize( _MAX_FNAME+1 );
	::_splitpath( lpszPath, NULL, NULL, szFname, szExt );
	::_makepath( (LPSTR)fname.data(), NULL, NULL, szFname, szExt );
	return	fname;
}

string	CPathlib::MakePath( LPCSTR lpszPath, LPCSTR lpszFname )
{
	CHAR	szDrive[ _MAX_DRIVE ];
	CHAR	szDir  [ _MAX_DIR ];
	string	path;
	path.resize( _MAX_PATH+1 );
	::_splitpath( lpszPath, szDrive, szDir, NULL, NULL );
	::_makepath( (LPSTR)path.data(), szDrive, szDir, lpszFname, NULL );
	return	path;
}

string	CPathlib::MakePathExt( LPCSTR lpszPath, LPCSTR lpszFname, LPCSTR lpszExt )
{
	CHAR	szDrive[ _MAX_DRIVE ];
	CHAR	szDir  [ _MAX_DIR ];
	string	path;
	path.resize( _MAX_PATH+1 );
	::_splitpath( lpszPath, szDrive, szDir, NULL, NULL );
	::_makepath( (LPSTR)path.data(), szDrive, szDir, lpszFname, lpszExt );
	return	path;
}

INT CALLBACK	CPathlib::BffCallback( HWND hWnd, UINT uMsg, LPARAM lParam, WPARAM wParam )
{
	if( uMsg == BFFM_INITIALIZED && wParam ) {
		::SendMessage( hWnd, BFFM_SETSELECTION, TRUE, wParam );
	}
	return	TRUE;
}

BOOL	CPathlib::SelectFolder( HWND hWnd, LPCSTR lpszTitle, LPSTR lpszFolder )
{
	BROWSEINFO	bi;
	LPITEMIDLIST	pidl;

	ZeroMemory( &bi, sizeof(bi) );
	bi.hwndOwner = hWnd;
	bi.lpszTitle = lpszTitle;
//	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	// For Folder setup
	bi.lpfn = (BFFCALLBACK)BffCallback;

	// 最後に'\'が付いているとデフォルト選択してくれない(Win98)ので...
	if( lpszFolder ) {
		if( ::strlen(lpszFolder) > 3 ) {
			if( lpszFolder[::strlen(lpszFolder)-1] == '\\' )
				lpszFolder[::strlen(lpszFolder)-1] = NULL;
		}
		bi.lParam = (LPARAM)lpszFolder;
	} else {
		bi.lParam = NULL;
	}

	string	path;
	if( (pidl = ::SHBrowseForFolder( &bi )) ) {
		path.resize( _MAX_PATH+1 );
		::SHGetPathFromIDList( pidl, lpszFolder );
		if( ::strlen(lpszFolder) > 3 ) {	// ドライブ名の場合を除く
			::strcat( lpszFolder, "\\" );
		}
		IMalloc* pMalloc;
		::SHGetMalloc( &pMalloc );
		if( pMalloc ) {
			pMalloc->Free( pidl );
			pMalloc->Release();
		}
		return	TRUE;
	}

	return	FALSE;
}

