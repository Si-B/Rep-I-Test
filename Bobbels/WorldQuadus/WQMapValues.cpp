#include "WQMapValues.h"
#include "WQBobbel.h"
#include "WQCustomTypes.h"

CWQMapValues::CWQMapValues(): 
							width(0), 
							height(0),
							size(0),
							bobbel_add_count(0)
{
	bobbels_on_map.resize(0);
	bobbels_on_map_static.resize(0);
}

CWQMapValues::CWQMapValues(int _width, int _height):
													width(_width),
													height(_height),
													size(_width*_height),
													bobbel_add_count(0)													
{
	bobbels_on_map.resize(0);
	//bobbels_on_map_static.resize(0);
}

CWQMapValues::~CWQMapValues()
{
}

void CWQMapValues::add_bobbel(CWQBobbel* _new_bobbel)
{	
	bobbel_add_count++;
	//if(_new_bobbel->get_bobbel_type() == CustomTypes::btStandard){
		bobbels_on_map.push_back(_new_bobbel);						  
	//}else{
		//bobbels_on_map_static.push_back(_new_bobbel);						  
	//}
}

CustomTypes::BobbelsOnMap * CWQMapValues::get_bobbels_on_map()
{
	return &bobbels_on_map;
}

CustomTypes::BobbelsOnMap * CWQMapValues::get_bobbels_on_map_static()
{
	return &bobbels_on_map_static;
}

bool CWQMapValues::is_map_full()
{
	return bobbel_add_count >= size;
}

int CWQMapValues::get_width()
{
	return CWQMapValues::width;
}

int CWQMapValues::get_height()
{
	return CWQMapValues::height;
}

int CWQMapValues::get_size()
{
	return CWQMapValues::size;
}

int CWQMapValues::get_bobbel_add_count()
{
	return CWQMapValues::bobbel_add_count;
}