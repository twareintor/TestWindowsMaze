

#include <windows.h>
#include <stdio.h>

/** */
void errhandler(LPCSTR szCls, HWND hwnd);

/** */
PBITMAPINFO CreateBitmapInfoStruct(HWND hwnd, HBITMAP hBmp);

/** */
void CreateBMPFile(HWND hwnd, LPTSTR pszFile, PBITMAPINFO pbi, 
                   HBITMAP hBMP, HDC hDC);

