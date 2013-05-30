#include "WQMap.h"
#include "WQBobbel.h"
#include "WQMapValues.h"
#include "WQCustomTypes.h"
#include "WQDiamondSquareGenerator.h"
#include "WQBitmapHelper.h"
#include "WQBobbelActionManager.h"
#include "WQMapHelper.h"
#include <windows.h>
#include <Winuser.h>
#include <math.h> 
#include "WQResource.h"

#define IDT_TIMER_ANIMATION		1
#define IDT_TIMER_ACTIONS		2
#define IDT_TIMER_CLEAN_UP		3

const bool						DEBUG = false;

bool							world_initialized = false;

const COLORREF					MASK_COLOR_HBITMAP = RGB(224, 128, 192);
const int						max_z_layer = 128;
const int						neighbor_count = 10;

CWQMap *						m_cwq_map;
int								cxClient, cyClient ; 
int								CWQBobbel::count = 0;
DWORD							startzeit;
LRESULT							CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM); 
HBITMAP							hBitmap;
HBITMAP							hBitmap2;
HBITMAP							hBitmapMask;

void							test_bobbeles();
void							let_bobbles_live();
void							draw_ground(HWND hwnd);
void							initialize_wq_world(CWQMap *);
void							initialize_wq_world_test(CWQMap *);
void							let_bobbel_move(CWQBobbel * _bobbel_to_move);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) 
{ 
	static TCHAR szAppName[] = TEXT ("Bobbels!!!!!!!") ; 
	HWND           hwnd ; 
	MSG            msg ; 
	WNDCLASS       wndclass ; 

	wndclass.style          = CS_HREDRAW | CS_VREDRAW ; 
	wndclass.lpfnWndProc    = WndProc ; 
	wndclass.cbClsExtra     = 0 ; 
	wndclass.cbWndExtra     = 0 ; 
	wndclass.hInstance      = hInstance ; 
	wndclass.hIcon          = LoadIcon (NULL, IDI_APPLICATION) ; 
	wndclass.hCursor        = LoadCursor (NULL, IDC_ARROW) ; 
	wndclass.hbrBackground	= (HBRUSH) GetStockObject (WHITE_BRUSH) ; 
	wndclass.lpszMenuName	= NULL ; 
	wndclass.lpszClassName	= szAppName ; 	

	if (!RegisterClass (&wndclass)) 
	{ 
	   MessageBox (NULL, TEXT ("Program requires Windows NT!"), 
					szAppName, MB_ICONERROR) ; 
	   return 0 ; 
	} 		   

	hwnd = CreateWindow (szAppName, TEXT ("Punkte!!!!!!!"), 
						WS_OVERLAPPEDWINDOW, 
						CW_USEDEFAULT, CW_USEDEFAULT, 
						525, 540, 
						NULL, NULL, hInstance, NULL) ; 	

	SetTimer(hwnd, IDT_TIMER_ANIMATION, 40, NULL);
	SetTimer(hwnd, IDT_TIMER_ACTIONS, 1000, NULL);
	SetTimer(hwnd, IDT_TIMER_CLEAN_UP, 5000, NULL);

	CWQBitmapHelper::instance()->set_current_window_handle(hwnd);

	//initializing cwqmap
	CWQMap cwq_map(max_z_layer, neighbor_count);
	m_cwq_map = &cwq_map;	

	//initializing diamond/sqare generator class
	CWQDiamondSquareGenerator diamond_square_generator(513, 75.f);	
	m_cwq_map->set_diamond_square_generator(&diamond_square_generator);

	//populate the map with some bobbel
	initialize_wq_world(m_cwq_map);
	
	//m_action_manager->set_map(m_cwq_map);
	ShowWindow (hwnd, iCmdShow) ; 
	UpdateWindow (hwnd) ; 

	//drawing the result of diamond/square class
	draw_ground(hwnd);

	while (GetMessage (&msg, NULL, 0, 0)) 
	{ 
		TranslateMessage (&msg) ; 
		DispatchMessage (&msg) ;
	} 

	return msg.wParam ; 
} 

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) 
{ 

	switch (message) 
	{ 
	case WM_SIZE: 
		cxClient = LOWORD (lParam); 
		cyClient = HIWORD (lParam); 
		return 0 ; 
	case WM_PAINT: 
		{
			if(world_initialized){
				CustomTypes::BobbelsOnMap::iterator		it;
				PAINTSTRUCT								ps ; 
				BITMAP									bm;
				RECT									r;
				HBRUSH									hBrush;	
				HBRUSH									hBrushRed;
				HBRUSH									hBrushGreen;
				HBITMAP									hBitmapHdcWindow;
				HDC										hdcWindow = BeginPaint(hwnd, &ps) ; 					
				HDC										hdcMem = CreateCompatibleDC(hdcWindow);
				HDC										hdcMem2 = CreateCompatibleDC(hdcWindow);
				//POINT pntArray[2];

				hBitmapHdcWindow = CreateCompatibleBitmap(hdcWindow, cxClient, cyClient);
				hBrush = CreateSolidBrush(RGB(255, 255, 255));
				hBrushRed = CreateSolidBrush(RGB(255, 0, 0));
				hBrushGreen = CreateSolidBrush(RGB(0, 255, 0));
				
				CWQBobbelActionManager::instance()->execute(m_cwq_map);

				r.left = 0;
				r.top = 0;
				r.right = cxClient;
				r.bottom = cyClient;
								  
				SelectObject(hdcMem2, hBitmapHdcWindow);
				FillRect(hdcMem2, &r, hBrush);
				GetObject(hBitmap, sizeof(bm), &bm);				

				SelectObject(hdcMem, m_cwq_map->get_diamond_square_generator()->get_hBitmap());
				BitBlt(hdcMem2, 0, 0, cxClient, cyClient, hdcMem, 0, 0, SRCCOPY);

				if(DEBUG){
					SelectObject(hdcMem2, GetStockObject(NULL_BRUSH));

					for (it = m_cwq_map->get_cwq_map_values()->get_bobbels_on_map()->begin(); it !=  m_cwq_map->get_cwq_map_values()->get_bobbels_on_map()->end(); it++){	
						Ellipse(hdcMem2, (int) it[0]->get_start_x() - (int) it[0]->get_range_of_interest(), (int) it[0]->get_start_y() - (int) it[0]->get_range_of_interest(), (int) it[0]->get_start_x() + (int) it[0]->get_range_of_interest(), (int) it[0]->get_start_y() + (int) it[0]->get_range_of_interest());				
					}

					for (it = m_cwq_map->get_cwq_map_values()->get_bobbels_on_map()->begin(); it !=  m_cwq_map->get_cwq_map_values()->get_bobbels_on_map()->end(); it++){	
						for(unsigned int k = 0; k < it[0]->get_current_target_list()->size();k++){
							if(it[0]->get_current_target_list()->at(k).active){
								RECT r1;
								r1.left = (long) it[0]->get_current_target_list()->at(k).target->get_x() - (it[0]->get_current_target_list()->at(k).target->get_width()/2);
								r1.top = (long) it[0]->get_current_target_list()->at(k).target->get_y() - (it[0]->get_current_target_list()->at(k).target->get_height()/2);;
								r1.right = (long) r1.left + it[0]->get_current_target_list()->at(k).target->get_width();
								r1.bottom = (long) r1.top + it[0]->get_current_target_list()->at(k).target->get_height();
								if(!it[0]->get_current_target_list()->at(k).reachable){
									FillRect(hdcMem2, &r1, hBrushRed);										
								}else{
									FillRect(hdcMem2, &r1, hBrushGreen);										
								}												   
							}
						}	
					}
				}

				for (it = m_cwq_map->get_cwq_map_values()->get_bobbels_on_map()->begin(); it !=  m_cwq_map->get_cwq_map_values()->get_bobbels_on_map()->end(); it++){	
					if(it[0]->is_visible()){					
						//Bitmapmaske in MemDc setzen
						SelectObject(hdcMem, it[0]->get_hbitmap_mask());
						//BitBlit der Maske auf Window DC
						//StretchBlt(hdcMem2, it[0]->get_bobbel_dimension().left, it[0]->get_bobbel_dimension().top, it[0]->get_width(), it[0]->get_height(), hdcMem, 0, 0, bm.bmWidth, bm.bmHeight, SRCAND);				
						BitBlt(hdcMem2, it[0]->get_bobbel_dimension().left, it[0]->get_bobbel_dimension().top, it[0]->get_width(), it[0]->get_height(), hdcMem, 0, 0, SRCAND);

						//////Setzen des original Bitmap in den kompatiblen DC
						SelectObject(hdcMem, it[0]->get_hbitmap());
						////BitBlit des orignal Bitmap auf Window DC
						//StretchBlt(hdcMem2, it[0]->get_bobbel_dimension().left, it[0]->get_bobbel_dimension().top, it[0]->get_width(), it[0]->get_height(), hdcMem, 0, 0, bm.bmWidth, bm.bmHeight, SRCPAINT);										
						BitBlt(hdcMem2, it[0]->get_bobbel_dimension().left, it[0]->get_bobbel_dimension().top, it[0]->get_width(), it[0]->get_height(), hdcMem, 0, 0, SRCPAINT);				
					}
				}	

				BitBlt(hdcWindow, 0, 0, cxClient, cyClient, hdcMem2, 0, 0, SRCCOPY);
				DeleteObject(hBrushRed);
				DeleteObject(hBrushGreen);
				DeleteObject(hBitmapHdcWindow);	
				DeleteObject(hBrush);
				DeleteDC(hdcMem);
				DeleteDC(hdcMem2);
				DeleteDC(hdcWindow);
		
				EndPaint(hwnd, &ps);
			}
			return 0 ;
		} 
	case WM_DESTROY: 
		KillTimer(hwnd, IDT_TIMER_ACTIONS);
		KillTimer(hwnd, IDT_TIMER_ANIMATION);
		KillTimer(hwnd, IDT_TIMER_CLEAN_UP);
		PostQuitMessage(0); 
		return 0; 
	case WM_CLOSE:
        DestroyWindow(hwnd);
		return 0;
	case WM_TIMER:
		switch (wParam) 
		{ 
			case IDT_TIMER_ANIMATION: 

				InvalidateRect(hwnd, NULL, false);
				return 0;
			

			case IDT_TIMER_ACTIONS:
				
				CWQMapHelper::instance()->generate_food(m_cwq_map);	
				return 0;

			case IDT_TIMER_CLEAN_UP:
				
				CustomTypes::BobbelsOnMap::iterator it;

				for (it = m_cwq_map->get_cwq_map_values()->get_bobbels_on_map()->begin(); it !=  m_cwq_map->get_cwq_map_values()->get_bobbels_on_map()->end(); it++){	
					if(!it[0]->is_visible() && !it[0]->is_active()){
						m_cwq_map->get_cwq_map_values()->get_bobbels_on_map()->erase(it);
						it = m_cwq_map->get_cwq_map_values()->get_bobbels_on_map()->begin();
					}
				}


			return 0;
		} 
		return 0;
	} 
	return DefWindowProc (hwnd, message, wParam, lParam); 
} 

void initialize_wq_world(CWQMap * cwq_map){
	
	int randMax = 10;
	srand((unsigned)time(NULL));	

	HBITMAP h1, h2, h3, h4, h5, h6, h7;												   

	h1 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP_BOBBEL_LEFT_1));
	h2 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP_BOBBEL_LEFT_2));
	h3 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP_BOBBEL_LEFT_3));
	h4 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP_BOBBEL_RIGHT_1));
	h5 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP_BOBBEL_RIGHT_2));
	h6 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP_BOBBEL_RIGHT_3));
	h7 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP_BOBBEL_DEAD));
	
	for(int i = 0; i < 25; i++){
		CWQBobbel * bobbel = new CWQBobbel(cwq_map);

		bobbel->set_bobbel_type(CustomTypes::btStandard);
		bobbel->set_width(10 + ((rand()*randMax)/(RAND_MAX)));
		bobbel->set_height(10 + ((rand()*randMax)/(RAND_MAX)));


		CustomTypes::BobbelTexture * bt = new CustomTypes::BobbelTexture();
		bt->bitmap = CWQBitmapHelper::instance()->resize_bitmap(h1, bobbel->get_width(), bobbel->get_height());
		bt->bitmap_mask = CWQBitmapHelper::instance()->create_bitmap_mask_using_bitblit(bt->bitmap, MASK_COLOR_HBITMAP);
		bobbel->add_texture(bt);

		bt = new CustomTypes::BobbelTexture();
		bt->bitmap = CWQBitmapHelper::instance()->resize_bitmap(h2, bobbel->get_width(), bobbel->get_height());
		bt->bitmap_mask = CWQBitmapHelper::instance()->create_bitmap_mask_using_bitblit(bt->bitmap, MASK_COLOR_HBITMAP);
		bobbel->add_texture(bt);

		bt = new CustomTypes::BobbelTexture();
		bt->bitmap = CWQBitmapHelper::instance()->resize_bitmap(h3, bobbel->get_width(), bobbel->get_height());
		bt->bitmap_mask = CWQBitmapHelper::instance()->create_bitmap_mask_using_bitblit(bt->bitmap, MASK_COLOR_HBITMAP);
		bobbel->add_texture(bt);

		bt = new CustomTypes::BobbelTexture();
		bt->bitmap = CWQBitmapHelper::instance()->resize_bitmap(h4, bobbel->get_width(), bobbel->get_height());
		bt->bitmap_mask = CWQBitmapHelper::instance()->create_bitmap_mask_using_bitblit(bt->bitmap, MASK_COLOR_HBITMAP);
		bobbel->add_texture(bt);

		bt = new CustomTypes::BobbelTexture();
		bt->bitmap = CWQBitmapHelper::instance()->resize_bitmap(h5, bobbel->get_width(), bobbel->get_height());
		bt->bitmap_mask = CWQBitmapHelper::instance()->create_bitmap_mask_using_bitblit(bt->bitmap, MASK_COLOR_HBITMAP);
		bobbel->add_texture(bt);

		bt = new CustomTypes::BobbelTexture();
		bt->bitmap = CWQBitmapHelper::instance()->resize_bitmap(h6, bobbel->get_width(), bobbel->get_height());
		bt->bitmap_mask = CWQBitmapHelper::instance()->create_bitmap_mask_using_bitblit(bt->bitmap, MASK_COLOR_HBITMAP);
		bobbel->add_texture(bt);

		bt = new CustomTypes::BobbelTexture();
		bt->bitmap = CWQBitmapHelper::instance()->resize_bitmap(h7, bobbel->get_width(), bobbel->get_height());
		bt->bitmap_mask = CWQBitmapHelper::instance()->create_bitmap_mask_using_bitblit(bt->bitmap, MASK_COLOR_HBITMAP);
		bobbel->add_texture(bt);

		bobbel->get_born();
	}

	HBITMAP hBitmap1 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP_BOBBEL_FOOD_1));

	for(int i = 0; i < 50; i++){
		CWQBobbel * bobbel = new CWQBobbel(cwq_map);

		bobbel->set_bobbel_type(CustomTypes::btFood);
		bobbel->set_width(15);
		bobbel->set_height(15);

		CustomTypes::BobbelTexture * bt = new CustomTypes::BobbelTexture();
		bt->bitmap = CWQBitmapHelper::instance()->resize_bitmap(hBitmap1, bobbel->get_width(), bobbel->get_height());
		bt->bitmap_mask = CWQBitmapHelper::instance()->create_bitmap_mask_using_bitblit(bt->bitmap, MASK_COLOR_HBITMAP);
		bobbel->add_texture(bt);

		bobbel->get_born();
		bobbel->disable_move();
	}


	world_initialized = true;

}

void draw_ground(HWND hwnd)
{
	static float		scale = 1.f;
	RECT r0;
	HBRUSH hBrush;
	HDC hdcWindow = GetDC(hwnd), hdcMem;
	HBITMAP hBitmapOld0;
	HBITMAP hBitmap0 = CreateCompatibleBitmap(hdcWindow, cxClient, cyClient);

	hdcMem = CreateCompatibleDC(hdcWindow);
	hBitmapOld0 = (HBITMAP) SelectObject(hdcMem, hBitmap0);	
	
	for(float i = 0; i < m_cwq_map->get_diamond_square_generator()->get_data_size()-1; i++){
		for(float j = 0; j < m_cwq_map->get_diamond_square_generator()->get_data_size()-1; j++){
			SetRect(&r0,(int)  i*scale,(int)  j*scale,(int) (i*scale)+scale,(int) (j*scale) + scale);				 
			hBrush = CreateSolidBrush(m_cwq_map->get_diamond_square_generator()->get_color_by_val(m_cwq_map->get_diamond_square_generator()->map_values[i*m_cwq_map->get_diamond_square_generator()->get_data_size() + j].height));
			FillRect(hdcMem, &r0 , hBrush );				
			DeleteObject(hBrush);
		}				
	}	// malen	

	SelectObject(hdcMem, hBitmapOld0);
	DeleteDC(hdcMem);
	DeleteDC(hdcWindow);
	DeleteObject(hBitmapOld0);

	m_cwq_map->get_diamond_square_generator()->set_hBitmap(hBitmap0);
}