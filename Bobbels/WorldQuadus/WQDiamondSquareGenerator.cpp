#include "WQDiamondSquareGenerator.h"
#include <time.h>

CWQDiamondSquareGenerator::CWQDiamondSquareGenerator() :minz_z(0), max_z(0), data_size(0), height_range(0.f)
{	
}

CWQDiamondSquareGenerator::CWQDiamondSquareGenerator(int size = 1, float height = 1.f): minz_z(0), max_z(0), data_size(size), height_range(height)
{	
	map_values.resize(size*size);
}

CWQDiamondSquareGenerator::~CWQDiamondSquareGenerator(void)
{	
}

HBITMAP CWQDiamondSquareGenerator::get_hBitmap()
{
	return hBitmap;
}

void CWQDiamondSquareGenerator::set_hBitmap(HBITMAP _hBitmap)
{
	hBitmap = _hBitmap;
}

float CWQDiamondSquareGenerator::average_square_vals(int i, int j, int halfSide)
{
	float returnVal = 0.f;
	float leftTop, rightTop, leftBottom, rightBottom;

	leftTop = map_values[(i-halfSide) * get_data_size() + (j-halfSide)].height;
	rightTop = map_values[(i+halfSide) * get_data_size() + (j-halfSide)].height;
	leftBottom = map_values[(i-halfSide)* get_data_size() + (j+halfSide)].height;
	rightBottom = map_values[(i+halfSide) * get_data_size() + (j+halfSide)].height;
		
	returnVal = (leftTop + rightTop + leftBottom + rightBottom) * 0.25f;

	return returnVal;
}

float CWQDiamondSquareGenerator::average_diamond_vals(int i, int j, int halfSide)
{
	float returnVal = 0.f;
	float leftCenter = 0.f, rightCenter = 0.f, topCenter = 0.f, aboveCenter = 0.f;

	if(i == 0){		
		rightCenter = map_values[((i+halfSide)*get_data_size()) + j].height ;		
		leftCenter = map_values[((get_data_size()-halfSide)*get_data_size()) + j].height ; //*
		topCenter = map_values[(i*get_data_size()) + j-halfSide].height ;
		aboveCenter = map_values[(i*get_data_size()) + j+halfSide].height ;
	
	}else if(i == get_data_size()-1){
		
		rightCenter = map_values[((0+halfSide)*get_data_size()) + j].height ; //*		
		leftCenter = map_values[((i-halfSide)*get_data_size()) + j].height ; 
		topCenter = map_values[(i*get_data_size()) + j-halfSide].height ;
		aboveCenter = map_values[(i*get_data_size()) + j+halfSide].height ;
	
	}else if(j == 0){
		
		rightCenter = map_values[((i+halfSide)*get_data_size()) + j].height ; 
		leftCenter = map_values[((i-halfSide)*get_data_size()) + j].height ; 
		topCenter = map_values[(i*get_data_size()) + get_data_size()-halfSide].height ; //*
		aboveCenter = map_values[(i*get_data_size()) + j+halfSide].height ;
		
	
	}else if(j == get_data_size()-1){

		rightCenter = map_values[((i+halfSide)*get_data_size()) + j].height ; 
		leftCenter = map_values[((i-halfSide)*get_data_size()) + j].height ; 
		topCenter = map_values[(i*get_data_size()) + j-halfSide].height ; 
		aboveCenter = map_values[(i*get_data_size()) + 0+halfSide].height ; //*
			
	}else{
		leftCenter = map_values[((i-halfSide)*get_data_size()) + j].height ; 			
		rightCenter = map_values[((i+halfSide)*get_data_size()) + j].height ; //*
		topCenter = map_values[(i*get_data_size()) + j-halfSide].height ;
		aboveCenter = map_values[(i*get_data_size()) + j+halfSide].height ;		
	}

	returnVal = (leftCenter + rightCenter + topCenter + aboveCenter) * 0.25f;

	return returnVal;
}

float CWQDiamondSquareGenerator::get_min_z()
{
	return minz_z;
}

float CWQDiamondSquareGenerator::get_max_z()
{
	return max_z;
}

int CWQDiamondSquareGenerator::get_data_size()
{
	return data_size;
}

void CWQDiamondSquareGenerator::set_scale(float _scale)
{
	scale = _scale;
}

float CWQDiamondSquareGenerator::get_scale()
{
	return scale;
}

COLORREF CWQDiamondSquareGenerator::get_color_by_val(float val)
{
	float newColorValues, nVal = 0.f, range = 0.f;

	range = max_z+(-minz_z);

	if(minz_z < 0){
		nVal = val+(-minz_z);
	}

	newColorValues = 255 * (nVal/range);  

	if(val < get_min_z()/2){
		return RGB(0, newColorValues, 255);
	}

	if(val < get_max_z()/3){
		return RGB(0, newColorValues, 0);
	}

	if(val < get_max_z() - get_max_z()/3){
		//return RGB(62, 192, 14);
		
	}

	return RGB(newColorValues, newColorValues, newColorValues);
}

float CWQDiamondSquareGenerator::rand_height_noise(float minH, float maxH)
{
	float nVal, randMax;	

	randMax = maxH+(-minH);
	nVal = minH + ((rand()*randMax)/(RAND_MAX));	

	return nVal;
}

void CWQDiamondSquareGenerator::calculate()
{
	int halfSide, sideLength, i , j;

	srand((unsigned)time(0));

	sideLength = get_data_size() - 1;
	halfSide = sideLength/2;

	map_values[0*get_data_size()+0].height  = 1.f;
	map_values[sideLength*get_data_size()+0].height = 1.f;
	map_values[0*get_data_size()+sideLength].height = 1.f;
	map_values[sideLength*get_data_size()+sideLength].height = 1.f;

	while(sideLength/2 > 0){
	
		for(i = halfSide; i < get_data_size()-1; i += sideLength){
			for(j = halfSide; j < get_data_size()-1; j += sideLength){
				//i = x and j = y			
				map_values[i*get_data_size() + j].height = rand_height_noise(-height_range, height_range) +  average_square_vals(i, j, halfSide);
			}										
		}

		for(i = 0; i < get_data_size()-1; i += halfSide){
			for(j = (i+halfSide)%sideLength; j < get_data_size()-1; j += sideLength){	
				//i = x and j = y	
				map_values[i*get_data_size() + j].height = rand_height_noise(-height_range, height_range) +  average_diamond_vals(i, j, halfSide);
			}		
		}

		sideLength /= 2;
		halfSide /= 2;
		height_range *= 1.0f;
	}

	for(i = 0; i < get_data_size()*get_data_size(); i++){
		if(map_values[i].height < minz_z){
			minz_z = map_values[i].height ;
		}else if(map_values[i].height > max_z){
			max_z = map_values[i].height;
		}
	}
}
