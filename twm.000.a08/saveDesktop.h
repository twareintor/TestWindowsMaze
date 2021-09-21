
/** 
 * this function will save a bitmap with the main screen
 * NOTE: use it responsable and only for reasonable purposes
 */
int saveDesktopWindowInBitmap()
{
    HWND hwnd;
    HDC hdc[2];
    HBITMAP hbitmap;
    RECT rect;
	
    hwnd = GetDesktopWindow();
    GetClientRect(hwnd, &rect);
    hdc[0] = GetWindowDC(hwnd);
    hbitmap = CreateCompatibleBitmap(hdc[0], rect.right, rect.bottom); 
    hdc[1] = CreateCompatibleDC(hdc[0]);
    SelectObject(hdc[1], hbitmap);    

    BitBlt(hdc[1], 0, 0, rect.right, rect.bottom,
        hdc[0], 0, 0, SRCCOPY);
	CreateBMPFile(hwnd, "desktop001.bmp", 
		CreateBitmapInfoStruct(hwnd, hbitmap), hbitmap, hdc[0]);

    return 0;
}