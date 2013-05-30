#pragma once

#include <windows.h> 
#include <vector>
#include "WQCustomTypes.h"

//using namespace std;

class CWQDiamondSquareGenerator
{
public:
	CWQDiamondSquareGenerator();
	CWQDiamondSquareGenerator(int size, float height);
	~CWQDiamondSquareGenerator(void);
	void									calculate();
	void									set_hBitmap(HBITMAP _hBitmap);
	void									set_scale(float);
	int										get_data_size();
	float									get_min_z();
	float									get_max_z();
	float									get_scale();
	COLORREF								get_color_by_val(float);
	HBITMAP									get_hBitmap();		
	::std::vector<float>					height_values;
	::std::vector<CustomTypes::MapValue>	map_values; 
private:
	int										data_size;
	float									height_range,
											minz_z,
											max_z,
											scale;
	float									rand_height_noise(float, float);
	float									average_square_vals(int, int, int);
	float									average_diamond_vals(int, int, int);
	HBITMAP									hBitmap;
};
