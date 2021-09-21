
#include <windows.h>
#include "drawMaze.h"
#include "saveBmp.h"
// Experimental - not part of the project ... 
// #include "saveDesktop.h"
// ... it works but the test is over

#define W 32
#define H 32
#define O 0

const char g_szClassName[] = "MyWindowClass";

BOOL g_drawn;

/** */
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
		LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;
	//Step 1: Registering the Window Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
		MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	// Step 2: Creating the Window
	hwnd = CreateWindowEx(
	WS_EX_CLIENTEDGE,
	g_szClassName,
	"Test Maze made with Win-GDI",
	WS_OVERLAPPEDWINDOW, // 
	CW_USEDEFAULT, CW_USEDEFAULT, (W+O)*25, (H+O)*25, // dimensions
	NULL, NULL, hInstance, NULL);
	if(hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
		MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	// Step 3: The Message Loop
	while(GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}


// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_PAINT:
		{
			if(g_drawn) break;
			RECT r;
			HDC hdc;
			hdc = GetDC(hwnd);
			GetClientRect(hwnd, &r);
			FillRect(hdc, &r, GetStockObject(WHITE_BRUSH));
			drawMaze(hdc, W, H); ////////////////////////////////////////////// 
			
			/* Create bitmap file */
			HBITMAP hbmp = CreateCompatibleBitmap(hdc, r.right-r.left, r.bottom-r.top);
			HDC hdc1 = CreateCompatibleDC(hdc);
			SelectObject(hdc1, hbmp);
			BitBlt(hdc1, r.left, r.top, r.right, r.bottom, hdc, 0, 0, SRCCOPY);
			LPSTR szFNm = (LPSTR)GlobalAlloc(GPTR, 0x40);
			sprintf(szFNm, "../out/zz_maze%010x.bmp", (unsigned)time(NULL));
			CreateBMPFile(hwnd, szFNm, 
				CreateBitmapInfoStruct(hwnd, hbmp), hbmp, hdc);
			GlobalFree(szFNm);
			/* */ 
			RedrawWindow(hwnd, &r, NULL, RDW_ERASE);
			// release resources
			ReleaseDC(hwnd, hdc);
			g_drawn = TRUE;
			break;
		}
		case WM_LBUTTONDOWN:
		{
			break;
		}
		case WM_RBUTTONDOWN:
		{
			// saveDesktopWindowInBitmap(); // the test is over, so ...
			// ... don't use it anymore
			break;
		}
		case WM_CLOSE:
		{
			DestroyWindow(hwnd);
			break;
		}
		case WM_KEYDOWN:
		{
			if (wParam == VK_ESCAPE)
			{
				PostQuitMessage(0);
			}
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}


