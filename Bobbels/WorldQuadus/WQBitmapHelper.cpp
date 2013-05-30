#include "WQBitmapHelper.h"

const COLORREF TRANSPARENT_COLOR = RGB(255, 255, 255);
CWQBitmapHelper * CWQBitmapHelper::pInstance = 0;

CWQBitmapHelper * CWQBitmapHelper::instance()
{
	if(pInstance == 0){
		pInstance = new CWQBitmapHelper();
	}

	return pInstance;
}

CWQBitmapHelper::CWQBitmapHelper(void): is_window_handle_set(false)
{
}

CWQBitmapHelper::~CWQBitmapHelper(void)
{
}

HBITMAP CWQBitmapHelper::create_bitmap_mask_using_bitblit(HBITMAP source_bitmap, COLORREF TRANSPARENT_COLOR)
{
	HDC hdc1, hdcMem;
	HBITMAP mask;
	BITMAP bm;

	//Erstellen einer 1 Bit Maske

	GetObject(source_bitmap, sizeof(BITMAP), &bm);
	mask = CreateBitmap(bm.bmWidth, bm.bmHeight, 1, 1, NULL);

	//Holen von DC´s

	hdc1 = CreateCompatibleDC(0);
	hdcMem = CreateCompatibleDC(0);

	//Schieben der Bitmaps in die DC´s

	SelectObject(hdc1, source_bitmap);
	SelectObject(hdcMem, mask);

	//Hintergrundfarbe des Quellbitmaps auf übergebene Farbe setzen

	SetBkColor(hdc1, TRANSPARENT_COLOR);

	//Kopieren des farbigen Bitmap in das monochrome Bitmap.
	//Dabei wird alles auf weiss geset_zt, was in der Hintergrundfarbe der Quelle ist. Der Rest schwarz.

	BitBlt(hdcMem, 0, 0, bm.bmWidth, bm.bmHeight, hdc1, 0, 0, SRCCOPY);

	//Die monochrome Maske wird wieder auf das Quellbitmap geschoben.
	//Durch SRCINVERT werden alle Bereiche des Quellbitmap nun auf schwarz geset_zt, die in der Maske weiss sind.

	BitBlt(hdc1, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCINVERT);	

	DeleteDC(hdc1);
	DeleteDC(hdcMem);

	return mask;
}

HBITMAP CWQBitmapHelper::resize_bitmap(HBITMAP source_bitmap, int width_destination, int height_destination)
{
	BITMAP bm;	
	GetObject(source_bitmap, sizeof(BITMAP), &bm);

	HBITMAP mask_bitmap = CreateBitmap(width_destination, height_destination, bm.bmPlanes, 32, NULL); 

	HDC hdcWindow = CreateCompatibleDC(0);
	HBITMAP hOld = (HBITMAP) SelectObject(hdcWindow, mask_bitmap);

   	HDC hdcMem = CreateCompatibleDC(hdcWindow);
	HBITMAP hOldM = (HBITMAP) SelectObject(hdcMem, source_bitmap);

	StretchBlt(hdcWindow, 0, 0, width_destination, height_destination, hdcMem, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY); 

	DeleteObject(hOld);
	DeleteObject(hOldM);
	//DeleteObject(mask_bitmap);											
	DeleteDC(hdcWindow);
	DeleteDC(hdcMem);
	
	return mask_bitmap;
}

COLORREF CWQBitmapHelper::get_bitmap_pixel_color(HBITMAP hSource, int x, int y){

	BITMAP bm;
	BITMAPINFOHEADER bi;	
	PAINTSTRUCT ps;
	GetObject(hSource, sizeof(BITMAP), &bm);

	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biBitCount = 32;
	bi.biWidth = bm.bmWidth;
	bi.biHeight = bm.bmHeight;
	bi.biPlanes = 1;
	bi.biCompression = BI_RGB;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrImportant = 0;
	bi.biClrUsed = 0;
	bi.biSizeImage = 0;

	HDC drawDc = BeginPaint(get_current_window_handle(), &ps);

	HBITMAP hBmOld = (HBITMAP)SelectObject(drawDc, hSource);

	DWORD dwBmSize = ((bm.bmWidth * bi.biBitCount + 31)/32) * 4 * bm.bmHeight;    

	LPVOID hDip = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwBmSize);
	BYTE *bitsBm = (BYTE*) GlobalLock(hDip);

	GetDIBits(drawDc , hSource, 0, (UINT)bm.bmHeight, bitsBm, (BITMAPINFO *) &bi, DIB_RGB_COLORS);

	int posInBitArray = (x*bi.biWidth + y) * 4;
	int r = 0;
	int g = 0;
	int b = 0;

	if (dwBmSize > posInBitArray)
	{
		try{
			r = bitsBm[posInBitArray+2];	
			g = bitsBm[posInBitArray+1];	
			b = bitsBm[posInBitArray];		

			HeapFree(GetProcessHeap(), HEAP_NO_SERIALIZE, hDip);

			DeleteObject(hDip);	

			SelectObject(drawDc, hBmOld);
			DeleteObject(hBmOld);

			EndPaint(get_current_window_handle(), &ps);
		}catch(...){
		}
	}

	return RGB(r, g, b);
}

bool CWQBitmapHelper::bitmap_collision(int x1, int y1, HBITMAP hbitmap_1, int x2, int y2, HBITMAP hbitmap_2){

	BITMAP b1, b2;
	int i, j;
	int xmin = 0, ymin = 0, xmax = 0, ymax = 0, xmax1 = 0, ymax1 = 0, xmax2 = 0, ymax2 = 0;
	int startxbm1 = 0, startybm1 = 0, startxbm2 = 0, startybm2 = 0;

	if(!is_window_handle_set)
		return false;
	
	GetObject(hbitmap_1, sizeof(BITMAP), &b1);
	GetObject(hbitmap_2, sizeof(BITMAP), &b2);

	xmax1 = x1 + b1.bmWidth;
	ymax1 = y1 + b1.bmHeight;
	xmax2 = x2 + b2.bmWidth;
	ymax2 = y2 + b2.bmHeight;

	xmin = max(x1, x2);
	ymin = max(y1, y2);

	xmax = min(xmax1, xmax2);
	ymax = min(ymax1, ymax2);
	
	if(xmax <= xmin || ymax <= ymin){
		return false;
	}

	if(y1 > y2){
		startybm1 = 0;		
		startybm2 = ymin - y2;
	}else if(y2 > y1){		
		startybm1 = ymin - y1;
		startybm2 = 0;		
	}

	COLORREF c1, c2;
	for(j = 0; j < ymax-ymin-1; j++){

		if(x1 > x2){
			startxbm2 = xmin - x2;
			startxbm1 = 0;				
		}else if(x2 > x1){
			startxbm1 = xmin - x1;
			startxbm2 = 0;				
		}

		for(i = 0; i < xmax-xmin-1; i++){
			c1 = get_bitmap_pixel_color(hbitmap_1, startxbm1, startybm1); 
			c2 = get_bitmap_pixel_color(hbitmap_2, startxbm2, startybm2); 

			if(c1 == TRANSPARENT_COLOR && c2 == TRANSPARENT_COLOR){
				//return false;
			}else if(c1 != TRANSPARENT_COLOR && c2 != TRANSPARENT_COLOR){
				return true;
			}

			startxbm1++;
			startxbm2++;			
		}
		startybm1++;
		startybm2++;
	}

	return false;
}

void CWQBitmapHelper::set_current_window_handle(HWND window_handle){
	current_window_handle = window_handle;
	is_window_handle_set = true;
}

HWND CWQBitmapHelper::get_current_window_handle(){
	return current_window_handle;
}