#ifndef WQBitmapHelper_H 
#define WQBitmapHelper_H

#include <windows.h>

class CWQBitmapHelper
{
public:
	static CWQBitmapHelper *		instance();
	void							set_current_window_handle(HWND window_handle);
	bool							is_window_handle_set;
	bool							bitmap_collision(int x1, int y1, HBITMAP hbitmap_1, int x2, int y2, HBITMAP hbitmap_2);	
	HWND							get_current_window_handle();
	HBITMAP							create_bitmap_mask_using_bitblit(HBITMAP source_bitmap, COLORREF mask_color);
	HBITMAP							resize_bitmap(HBITMAP source_bitmap, int width_destination, int height_destination);
	COLORREF						get_bitmap_pixel_color(HBITMAP hSource, int x, int y);
private:
	CWQBitmapHelper(void);
	~CWQBitmapHelper(void);
	static CWQBitmapHelper *		pInstance;
	HWND							current_window_handle;
};

#endif