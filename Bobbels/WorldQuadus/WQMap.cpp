#include "WQMap.h"
#include "WQBobbel.h"
#include <windows.h>
#include "WQResource.h"
#include "WQMapHelper.h"

const COLORREF		MASK_COLOR = RGB(0, 0, 0);
const int map_size = CWQMap::map_width * CWQMap::map_height;

CWQMap::CWQMap():
				max_z_layer(0),
				neighbour_count_at_begin(0),
				neighbours_per_layer(0),
				cwq_map_values(0, 0),
				current_z_layer(0),
				scale_collision_map(0),
				round_count(0)
{
}

CWQMap::CWQMap(int _max_z_layer, int _neighbour_count_at_begin):
																max_z_layer(_max_z_layer),
																neighbour_count_at_begin(_neighbour_count_at_begin),
																neighbours_per_layer(_max_z_layer),
																cwq_map_values(map_width, map_height),
																current_z_layer(0),
																scale_collision_map(25),
																round_count(0)
{
	//initialize_neighborhood();
	initialize_kollision_map();
}

CWQMap::~CWQMap() 
{	
}

CWQMapValues * CWQMap::get_cwq_map_values()
{
	return &cwq_map_values;
}

void CWQMap::initialize_neighborhood(){

	for(int i = 0; i < CWQMap::max_z_layer; i++){
		CWQMap::neighbours_per_layer[i].resize(2);
	}

	for(int i = CWQMap::max_z_layer-1; i >= 0; i--){
		CWQMap::neighbours_per_layer[i][0] = neighbour_count_at_begin*(CWQMap::max_z_layer-i);
		CWQMap::neighbours_per_layer[i][1] = 0;
	}	
}

void CWQMap::initialize_kollision_map()
{

	int width_kollision_map = 0, height_kollision_map = 0;

	if(get_width() % scale_collision_map > 0){
		width_kollision_map = (get_width() + scale_collision_map) / scale_collision_map ;		
	}else{
		width_kollision_map = get_width() / scale_collision_map;		
	}

	if(get_height() % scale_collision_map > 0){
		height_kollision_map = (get_height() + scale_collision_map) / scale_collision_map;		
	}else{
		height_kollision_map = get_height() / scale_collision_map;		
	}

	bobbel_kollision_map.resize(width_kollision_map*height_kollision_map); 

	//for(int unsigned i = 0; i < bobbel_kollision_map.size(); i++){
	//	bobbel_kollision_map[i].resize(scale_collision_map*scale_collision_map);
	//}

}

void CWQMap::add_bobbel(CWQBobbel* _new_bobbel)
{	
	CWQMap::cwq_map_values.add_bobbel(_new_bobbel);	
}

bool CWQMap::is_map_full()
{	
	return CWQMap::get_cwq_map_values()->is_map_full();
}

int CWQMap::get_max_z_layer()
{
	return CWQMap::max_z_layer;
}

int CWQMap::get_width()
{
	return map_width;
}

int CWQMap::get_height()
{
	return map_height;
}

void CWQMap::set_diamond_square_generator(CWQDiamondSquareGenerator * _diamond_square_generator)
{
	diamond_square_generator = _diamond_square_generator;
	diamond_square_generator->calculate();
	min_height = diamond_square_generator->get_min_z()/2;
	max_height = diamond_square_generator->get_max_z()/2;
}

CWQDiamondSquareGenerator * CWQMap::get_diamond_square_generator()
{
	return diamond_square_generator;
}

void CWQMap::set_bitmap_helper(CWQBitmapHelper * _bitmap_helper)
{
	bitmap_helper = _bitmap_helper;
}

void CWQMap::increase_round_count()
{
	round_count++;
}

int CWQMap::get_round_count()
{
	return round_count;
}

bool CWQMap::dimension_collision(RECT r1, RECT r2)
{
	if(r1.left > r2.right) return false;
	if(r1.top > r2.bottom) return false;
	if(r2.top > r1.bottom) return false;
	if(r2.left > r1.right) return false;

	return true;
}

bool CWQMap::bobbel_range_collision(int _x_to_move, int _y_to_move, CWQBobbel * _bobbel)
{
	double range = CWQMapHelper::instance()->get_range((int) _x_to_move, (int) _y_to_move, (int) _bobbel->get_start_x(), (int) _bobbel->get_start_y());
	double radian = _bobbel->get_range_of_interest();

	return range <= radian;
}

bool CWQMap::bobbel_range_collision(CWQBobbel * _bobbel_to_move, CWQBobbel * _bobbel)
{
	double range = CWQMapHelper::instance()->get_range((int) _bobbel_to_move->get_x(), (int) _bobbel_to_move->get_start_y(), (int) _bobbel->get_start_x(), (int) _bobbel->get_start_y());
	double radian = _bobbel->get_range_of_interest() + _bobbel_to_move->get_range_of_interest();

	return range <= radian;
}

bool CWQMap::bobbel_world_collision(RECT * _dimension_move_to, CWQBobbel * _bobbel_to_move){

	double	current_height;	

	for(int i = 0; i < _bobbel_to_move->get_width(); i++){
		for(int j = 0; j < _bobbel_to_move->get_height(); j++){
			if(CWQBitmapHelper::instance()->get_bitmap_pixel_color(_bobbel_to_move->get_hbitmap_mask(), i, j) == RGB(255, 255, 255)){
				current_height = diamond_square_generator->map_values[i*diamond_square_generator->get_data_size() + j].height;	
				if(current_height >= max_height || current_height <= min_height){
					return true;
				}
			}
		}
	}

	return false;
}

bool CWQMap::bobbel_world_collision(CWQBobbel* _point_to_move, double _x, double _y)
{
	float scale = 2.0f;
	double index = ((_x)*diamond_square_generator->get_data_size() + (_y));
	double current_height = diamond_square_generator->map_values[index].height;

	if(current_height >= max_height || current_height <= min_height){
		return true;
	}

	return false;
}

bool CWQMap::can_move_to(CWQBobbel* _point_to_move, double _x, double _y, bool ignore_active_objects)
{

	if(CWQMapHelper::instance()->get_range((int) _point_to_move->get_start_x(), (int) _point_to_move->get_start_y(), (int) _x, (int) _y) > _point_to_move->get_range_of_interest()+1){
		return false;
	}

	if(bobbel_world_collision(_point_to_move, _x, _y)){
		return false;
	}

	if(!ignore_active_objects){
		if(bobbel_collision(_point_to_move, _x, _y)){
			return false;
		}						   
	}

	return true;
}

bool CWQMap::get_born_at(CWQBobbel* _point_to_move, double _x, double _y)
{

	RECT dimension_move_to;

	if(bobbel_world_collision(_point_to_move, _x, _y))
		return false;

	dimension_move_to.left = (long) _x - (_point_to_move->get_width()/2);
	dimension_move_to.top = (long) _y - (_point_to_move->get_height()/2);
	dimension_move_to.right = dimension_move_to.left + _point_to_move->get_width();
	dimension_move_to.bottom = dimension_move_to.top + _point_to_move->get_height();	

	if(bobbel_collision(&dimension_move_to, _point_to_move)){
		return false;
	}

	move_to(_point_to_move, &dimension_move_to);

	return true;
}

bool CWQMap::bobbel_collision(RECT * _dimension_move_to, CWQBobbel *_bobbel_to_move)
{

	CustomTypes::BobbelsOnMap::iterator it;

	for (it = CWQMap::get_cwq_map_values()->get_bobbels_on_map()->begin(); it !=  CWQMap::get_cwq_map_values()->get_bobbels_on_map()->end(); it++){	
		if(it[0] != _bobbel_to_move){
			if(_bobbel_to_move->get_bobbel_type() != CustomTypes::btFood && it[0]->get_bobbel_type() == CustomTypes::btStandard){			
				if(dimension_collision(*_dimension_move_to, it[0]->get_bobbel_dimension())){
					if(CWQBitmapHelper::instance()->bitmap_collision(_dimension_move_to->left, _dimension_move_to->top, _bobbel_to_move->get_hbitmap_mask(), it[0]->get_bobbel_dimension().left, it[0]->get_bobbel_dimension().top, it[0]->get_hbitmap_mask())){						
						return true;
					}
				}
			}		
		}
	}

	return false;

}

bool CWQMap::bobbel_collision(CWQBobbel * _bobbel_to_move, double _x, double _y)
{

	RECT dimension_move_to;

	dimension_move_to.left = (long) _x - (_bobbel_to_move->get_width()/2);
	dimension_move_to.top = (long) _y - (_bobbel_to_move->get_height()/2);
	dimension_move_to.right = dimension_move_to.left + _bobbel_to_move->get_width();
	dimension_move_to.bottom = dimension_move_to.top + _bobbel_to_move->get_height();

	CustomTypes::BobbelsOnMap::iterator it;

	for (it = CWQMap::get_cwq_map_values()->get_bobbels_on_map()->begin(); it !=  CWQMap::get_cwq_map_values()->get_bobbels_on_map()->end(); it++){
		if(it[0] != _bobbel_to_move){
			if(_bobbel_to_move->get_bobbel_type() != CustomTypes::btFood && it[0]->get_bobbel_type() == CustomTypes::btStandard){			
				if(dimension_collision(dimension_move_to, it[0]->get_bobbel_dimension())){
					if(CWQBitmapHelper::instance()->bitmap_collision(dimension_move_to.left, dimension_move_to.top, _bobbel_to_move->get_hbitmap_mask(), it[0]->get_bobbel_dimension().left, it[0]->get_bobbel_dimension().top, it[0]->get_hbitmap_mask())){						
						return true;
					}
				}
			}
		}
	}

	return false;

}


bool CWQMap::move_to(CWQBobbel* _point_to_move, double _x, double _y)
{
	RECT dimension_move_to;

	CustomTypes::BobbelsOnMap::iterator it;

	dimension_move_to.left = (long) _x - (_point_to_move->get_width()/2);
	dimension_move_to.top = (long) _y - (_point_to_move->get_height()/2);
	dimension_move_to.right = dimension_move_to.left + _point_to_move->get_width();
	dimension_move_to.bottom = dimension_move_to.top + _point_to_move->get_height();

	for (it = this->get_cwq_map_values()->get_bobbels_on_map()->begin(); it !=  this->get_cwq_map_values()->get_bobbels_on_map()->end(); it++){	
		if(it[0]->is_visible()){
			if(it[0] != _point_to_move && _point_to_move->get_bobbel_type() != CustomTypes::btFood && it[0]->is_active()){			
				
				if(it[0]->get_bobbel_type() == CustomTypes::btFood){
					if(bobbel_range_collision(it[0], _point_to_move)){	
						_point_to_move->add_target(it[0]);
					}			
				}
				
				if(dimension_collision(dimension_move_to, it[0]->get_bobbel_dimension())){
					if(CWQBitmapHelper::instance()->bitmap_collision(dimension_move_to.left, dimension_move_to.top, _point_to_move->get_hbitmap_mask(), it[0]->get_bobbel_dimension().left, it[0]->get_bobbel_dimension().top, it[0]->get_hbitmap_mask())){						
						if(it[0]->get_bobbel_type() != CustomTypes::btStandard){
							_point_to_move->arrived_at(it[0]);
							get_cwq_map_values()->get_bobbels_on_map()->erase(it);
						}

						return false;
					}
				}

			}
		}		
	}

	_point_to_move->set_bobbel_dimension(dimension_move_to);

	return true;

}

bool CWQMap::move_to(CWQBobbel* _point_to_move, RECT * _dimension_move_to)
{	
	CustomTypes::BobbelsOnMap::iterator it;

	for (it = CWQMap::get_cwq_map_values()->get_bobbels_on_map()->begin(); it !=  CWQMap::get_cwq_map_values()->get_bobbels_on_map()->end(); it++){	
		if(it[0]->is_visible()){
			if(it[0] != 0 && it[0] != _point_to_move && _point_to_move->get_bobbel_type() != CustomTypes::btFood){			
				
				if(it[0]->get_bobbel_type() == CustomTypes::btFood){
					if(bobbel_range_collision(it[0], _point_to_move)){	
						_point_to_move->add_target(it[0]);
					}			
				}

				if(dimension_collision(*_dimension_move_to, it[0]->get_bobbel_dimension())){
					if(CWQBitmapHelper::instance()->bitmap_collision(_dimension_move_to->left, _dimension_move_to->top, _point_to_move->get_hbitmap_mask(), it[0]->get_bobbel_dimension().left, it[0]->get_bobbel_dimension().top, it[0]->get_hbitmap_mask())){						
						if(it[0]->get_bobbel_type() != CustomTypes::btStandard){
							_point_to_move->arrived_at(it[0]);
							//get_cwq_map_values()->get_bobbels_on_map()->erase(it);
						}

						return false;
					}
				}

			}	
		}
	}

	_point_to_move->set_bobbel_dimension(*_dimension_move_to);

	return true;
}