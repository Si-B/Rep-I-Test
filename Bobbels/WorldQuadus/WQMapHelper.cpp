#include "WQMapHelper.h"
#include "WQMap.h"
#include "WQBobbel.h"
#include "WQResource.h"
#include <math.h>

const COLORREF MASK_COLOR_HBITMAP = RGB(224, 128, 192);

CWQMapHelper * CWQMapHelper::pInstance = 0;

CWQMapHelper * CWQMapHelper::instance()
{
	if(pInstance == 0){
		pInstance = new CWQMapHelper();
	}

	return pInstance;
}

CWQMapHelper::CWQMapHelper(void)
{
}

CWQMapHelper::~CWQMapHelper(void)
{
}

void CWQMapHelper::generate_food(CWQMap * _map)
{

	CWQBobbel * bobbel = new CWQBobbel(_map);	
	bobbel->set_bobbel_type(CustomTypes::btFood);
	bobbel->set_width(15);
	bobbel->set_height(15);

	CustomTypes::BobbelTexture * bt = new CustomTypes::BobbelTexture();
	bt->bitmap = CWQBitmapHelper::instance()->resize_bitmap(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP_BOBBEL_FOOD_1)), bobbel->get_width(), bobbel->get_height());
	bt->bitmap_mask = CWQBitmapHelper::instance()->create_bitmap_mask_using_bitblit(bt->bitmap, MASK_COLOR_HBITMAP);

	bobbel->add_texture(bt);
	bobbel->disable_move();
	bobbel->get_born();

};

double CWQMapHelper::get_range(int _x1, int _y1, int _x2, int _y2)
{
	double side_a, side_b, side_c;
	
	if(_x1 < _x2){
		side_a = _x2 - _x1;
	}else{
		side_a = _x1 - _x2;
	}

	if(_y1 < _y2){
		side_b = _y2 - _y1;
	}else{
		side_b = _y1 - _y2;
	}

	side_c = side_a*side_a + side_b*side_b;

	return sqrt(side_c);
};
