// put a bitmap image on a Windows Console display
// BCX basic original by Joe Caverly and Kevin Diggins
// BCX generated C code modified for PellesC/Dev-C++
 
#include <stdio.h>
#include <string.h>
#include <windows.h>    // Win32Api Header File 
		
static HWND hConWnd;
HWND BCX_Bitmap(char*,HWND=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0);
HWND GetConsoleWndHandle(void);
int main()
{
	hConWnd = GetConsoleWndHandle();
	if (hConWnd)
	{
		// select a bitmap file you have or use one of the files in the Windows folder
		// filename, handle, ID, ulcX, ulcY, width, height   0,0 auto-adjusts
		BCX_Bitmap("C:\\Windows\\greenstone.bmp",hConWnd,123,1,1,0,0);
		
		getchar();  // wait
	}
	return 0;
}
// draw the bitmap
HWND BCX_Bitmap(char* Text,HWND hWnd,int id,int X,int Y,int W,int H,int Res,int Style,int Exstyle)
{
	HWND A;
	HBITMAP hBitmap;
	
	// set default style
	if (!Style) Style = WS_CLIPSIBLINGS|WS_CHILD|WS_VISIBLE|SS_BITMAP|WS_TABSTOP;
	
	// form for the image
	A = CreateWindowEx(Exstyle,"static",NULL,Style,X,Y,0,0,hWnd,(HMENU)id,GetModuleHandle(0),NULL);
											
	// Text contains filename
	hBitmap=(HBITMAP)LoadImage(0,Text,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	// auto-adjust width and height
	if (W || H) hBitmap = (HBITMAP)CopyImage(hBitmap,IMAGE_BITMAP,W,H,LR_COPYRETURNORG);
	SendMessage(A,(UINT)STM_SETIMAGE,(WPARAM)IMAGE_BITMAP,(LPARAM)hBitmap);
	if (W || H) SetWindowPos(A,HWND_TOP,X,Y,W,H,SWP_DRAWFRAME);
	return A;
}
// tricking Windows just a little ...
HWND GetConsoleWndHandle(void)
{
	HWND hConWnd;
	OSVERSIONINFO os;
	char szTempTitle[64], szClassName[128], szOriginalTitle[1024];
	os.dwOSVersionInfoSize = sizeof( OSVERSIONINFO );
	GetVersionEx( &os );
	// may not work on WIN9x
	if ( os.dwPlatformId == VER_PLATFORM_WIN32s ) return 0;
	GetConsoleTitle( szOriginalTitle, sizeof ( szOriginalTitle ) );
	sprintf( szTempTitle,"%u - %u", GetTickCount(), GetCurrentProcessId() );
	SetConsoleTitle( szTempTitle );
	Sleep( 40 );
	// handle for NT and XP
	hConWnd = FindWindow( NULL, szTempTitle );
	SetConsoleTitle( szOriginalTitle );
	// may not work on WIN9x
	if ( os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS )
	{
		hConWnd = GetWindow( hConWnd, GW_CHILD );
		if ( hConWnd == NULL ) return 0;
		GetClassName( hConWnd, szClassName, sizeof ( szClassName ) );
		// while ( _stricmp( szClassName, "ttyGrab" ) != 0 )
		while ( strcmp( szClassName, "ttyGrab" ) != 0 )
		{
			hConWnd = GetNextWindow( hConWnd, GW_HWNDNEXT );
			if ( hConWnd == NULL ) return 0;
			GetClassName( hConWnd, szClassName, sizeof( szClassName ) );
		}
	}
	return hConWnd;
}