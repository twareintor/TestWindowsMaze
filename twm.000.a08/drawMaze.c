
#include "drawMaze.h"


INT drawMaze(HDC hdc, int const w, int const h)
{
	int i = 0;
	int f = 0;	// flag/ first row (no ->1), 
	HPEN hPen;
	HPEN hOldPen;
	POINT pt = {10, 10};

	char* szMaze = (char*)GlobalAlloc(GPTR, 0x4000);
	int res = getMaze(szMaze, 0x4000, w, h);
	FILE* fout = fopen("maze.txt", "a");
	fprintf(fout, "%s\n", szMaze); fclose(fout);

	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	hOldPen = SelectObject(hdc, hPen);
	 
	MoveToEx(hdc, pt.x, pt.y, 0);
	while(szMaze[i])
	{
		if('|'==szMaze[i])
		{
			LineTo(hdc, pt.x, pt.y-20);
		}
		else if('_'==szMaze[i])
		{
			MoveToEx(hdc, pt.x-10*f, pt.y, NULL);
			LineTo(hdc, pt.x+10+10*(1-f), pt.y);
			MoveToEx(hdc, pt.x+10*f, pt.y, NULL);
		}
		LineTo(hdc, pt.x, pt.y);
		if('\n'==szMaze[i]){pt.x = 10; pt.y+=20; f = 1;} 
		else{pt.x+=10;}
		MoveToEx(hdc, pt.x, pt.y, 0);
		i++;
	}
	GlobalFree(szMaze);
	
	SelectObject(hdc, hOldPen);
	DeleteObject(hPen);
	// MessageBoxA(NULL, "Done!", "Msg", MB_OK);
	return 0;
}

