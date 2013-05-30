#include "AStarPathFinding.h"
#include "WQBobbel.h"
#include "WQMap.h"
#include "WQMapHelper.h"
#include <string>
#include <time.h>
#include <sstream>
#include <math.h>
#include <stdio.h>

#include <assert.h>

CWQBobbel::CWQBobbel():
						width(0),
						height(0),
						x(width/2),
						y(height/2),
						z(0),
						range_of_interest(0),
						start_x(x),
						start_y(y),
						move_count(0),
						action_flag(0),
						available_actions(0),
						food_count(1250),
						current_view_angle(-1),
						step_count(0),
						current_target(-1),
						active(true),
						visible(true)
{
}


CWQBobbel::CWQBobbel(CWQMap* _map):
									width(20),
									height(24),
									x(width/2),
									y(height/2),
									z(0),
									range_of_interest(10),
									start_x(x),
									start_y(y),
									move_count(0),
									action_flag(0),
									available_actions(0),
									food_count(750),
									current_view_angle(-1),
									step_count(0),
									has_target(false),
									current_target(-1),
									active(true),
									visible(true)
									
{
	map = _map;
	place = ++count;
	bobbel_dimension.left = (long) x - (get_width()/2);
	bobbel_dimension.top = (long) y - (get_height()/2);
	bobbel_dimension.right = (long) bobbel_dimension.left + get_width();
	bobbel_dimension.bottom = (long) bobbel_dimension.top + get_height();
}

CWQBobbel::~CWQBobbel()
{
	map = 0;
}


void CWQBobbel::get_born()
{	

	map->add_bobbel(this);		

	while(!map->get_born_at(this, rand() % (map->get_cwq_map_values()->get_width()), rand() % (map->get_cwq_map_values()->get_height())));

	action_flag += CustomTypes::baMove;
	set_visible(true);

	if(this->get_bobbel_type() == CustomTypes::btStandard){
		action_flag += CustomTypes::baEat;
		//action_flag += CustomTypes::baCollect;
	}

	start_x = get_x();
	start_y = get_y();
}

void CWQBobbel::let_move_own_direction()
{
	if(food_count < 1){
		disable_move();
		target_list.clear();
	}		

	if(has_target){
		follow_current_target();
	}else{	
		if(target_list.size() > 0){
			if(!find_reachable_target()){			
				move_random_direction();			
			}else{
				follow_current_target();
			}
		}else{
			move_random_direction();					
		}	
	}
};

void CWQBobbel::take_current_target_to_start()
{

	if(has_target){
		if(target_list.at(current_target).execute_action){
			
		}else{
			let_move_own_direction();
		}
	}else{
		let_move_own_direction();
	}

}

void CWQBobbel::follow_current_target()
{

	double newX = 0, newY = 0, newZ = 0;
	int pos = 0;

	if (target_list.size()  == 0)
	{
		return;
	}

	if(step_count < target_list.at(current_target).path_to_target.size()){

		pos = target_list.at(current_target).path_to_target.at(step_count);
				  
		newY = pos%CWQMap::map_width;
		newX = (pos-newY)/CWQMap::map_width;			

			if(newX <= get_x()){
				bobbel_view_direction = CustomTypes::bvdLeft;
			}else{
				bobbel_view_direction = CustomTypes::bvdRight;
			}

			if(map->move_to(this, newX, newY)){
				if(target_list.at(current_target).current_action == CustomTypes::baCollect){
					target_list.at(current_target).target->set_x(newX);
					target_list.at(current_target).target->set_y(newY);
				}								   
			}else{
				if(target_list.at(current_target).current_action == CustomTypes::baCollect){
					target_list.at(current_target).target->set_active(false);
					target_list.at(current_target).active = false;
					has_target = false;
				}								   			
			}
			step_count++;
			move_count++;
			food_count--;			
	}else{
		//if(target_list.at(current_target).current_action == CustomTypes::baFollow){
			target_list.at(current_target).active = false;
			has_target = false;
		//}else if(target_list.at(current_target).current_action == CustomTypes::baCollect){
		
		//}
	}
}

bool CWQBobbel::find_reachable_target()
{
	for(unsigned int i = 0; i < target_list.size(); i++){			
		if(target_list.at(i).active){
			//if(GetTickCount() - target_list.at(i).last_path_check > 1250){
				target_list.at(i).path_to_target = AStarPathFinding::find_path(this, (int) target_list.at(i).target->get_x(), (int) target_list.at(i).target->get_y(), (int) get_x(), (int) get_y());
				target_list.at(i).reachable = target_list.at(i).path_to_target.size() > 0;
				target_list.at(i).last_path_check = GetTickCount();
				target_list.at(i).current_action = CustomTypes::baFollow;

				if(target_list.at(i).reachable){
					current_target = i;
					has_target = true;
					step_count = 0;	
					break;
				}															   			
			//}				
		}
	}

	return has_target;
}

void CWQBobbel::move_random_direction()
{
	double newX = 0, newY = 0, newZ = 0;

	if(calculate_range_from_start() < range_of_interest){		
		
		if(current_view_angle < 0){
			generate_new_direction();
		}

		if (current_view_angle < 22.5 || current_view_angle > 337.5) {
			newX = get_new_x(get_x() + 1);
			newY = get_new_y(get_y());
		 } else if (current_view_angle < 67.5 && current_view_angle > 22.5) {
			newX = get_new_x(get_x() + 1);
			newY = get_new_y(get_y() - 1);
		 } else if (current_view_angle < 112.5 && current_view_angle > 67.5) {
			newX = get_new_x(get_x());
			newY = get_new_y(get_y() - 1);
		 } else if (current_view_angle < 157.5 && current_view_angle > 112.5) {
			newX = get_new_x(get_x() - 1);
			newY = get_new_y(get_y() - 1);
		 } else if (current_view_angle < 202.5 && current_view_angle > 157.5) {	 
			newX = get_new_x(get_x() - 1);
			newY = get_new_y(get_y());
		 } else if (current_view_angle < 247.5 && current_view_angle > 202.5) {
			newX = get_new_x(get_x() - 1);
			newY = get_new_y(get_y() + 1);
		 } else if (current_view_angle < 292.5 && current_view_angle > 247.5) {
			newX = get_new_x(get_x());
			newY = get_new_y(get_y() + 1);
		 } else if (current_view_angle < 337.5 || current_view_angle > 292.5) {
			newX = get_new_x(get_x() + 1);
			newY = get_new_y(get_y() + 1);       
		 }					 

		if(newX <= get_x()){
			bobbel_view_direction = CustomTypes::bvdLeft;
		}else{
			bobbel_view_direction = CustomTypes::bvdRight;
		}
				    					
		if(!map->can_move_to(this, newX, newY, false)){			
			generate_new_direction();				
		}else{
			map->move_to(this, newX, newY);
			move_count++;
			food_count--;
		}									   

	}else{
		generate_new_direction();
		increase_range_of_interest();
	}
}

void CWQBobbel::add_target(CWQBobbel * _target)
{

	if(_target == 0)
		return;

	if(has_target)
		if(target_list.at(current_target).target == _target)
			return;		

	if(bobbel_in_target_list(_target))
		return;
	
	CustomTypes::BobbelLink bobbel_link;							  	

	bobbel_link.active = true;
	bobbel_link.target = _target;
	bobbel_link.last_path_check = 0;
	bobbel_link.available_actions = _target->get_available_actions();
	bobbel_link.reachable = false;

	target_list.push_back(bobbel_link);

};

void CWQBobbel::arrived_at(CWQBobbel * _target)
{
	if(action_flag & CustomTypes::baEat){		
		if(_target->get_bobbel_type() == CustomTypes::btFood){
			food_count+=500;

			//if(bobbel_in_target_list(_target)){
			//
			//}



			if(target_list.size() > 0){					
				if(has_target){				
					if(target_list.at(current_target).target == _target){
						target_list.at(current_target).active = has_target = false;
						_target->set_visible(false);
						_target->set_active(false);
						return;
					}
				}

				for(unsigned int i = 0; i < target_list.size(); i++){
					if(target_list.at(i).target == _target){
						target_list.at(i).active = false;
						break;
					}		
				}
			}
			_target->set_visible(false);
			_target->set_active(false);
		}
	}else if(action_flag & CustomTypes::baCollect){

		for(unsigned int i = 0; i < target_list.size(); i++){
			if(target_list.at(i).target == _target){

				if(_target->get_available_actions() & CustomTypes::baFollow){
					target_list.at(i).path_to_target = AStarPathFinding::find_path(this, get_start_x(), get_start_y(), get_x(), get_y());
					target_list.at(i).reachable = true;
					target_list.at(i).execute_action = true;
					target_list.at(i).current_action = CustomTypes::baCollect;
					current_target = i;
					step_count = 0;
					has_target = true;					
					break;				
				}

			}		
		}

	}
}

void CWQBobbel::generate_new_direction()
{		
	current_view_angle = rand() % 360;
};

void CWQBobbel::increase_range_of_interest()
{
	range_of_interest++;
};

void CWQBobbel::disable_move()
{
	action_flag = action_flag ^ CustomTypes::baMove;
};

void CWQBobbel::enable_move()
{
	action_flag = action_flag | CustomTypes::baMove;
};

void CWQBobbel::set_bobbel_type(int _bobbel_type)
{

	if(_bobbel_type	== CustomTypes::btStandard){
		available_actions = available_actions | CustomTypes::baMove;
		available_actions = available_actions | CustomTypes::baEat;
		available_actions = available_actions | CustomTypes::baCollect;			
	}else if(_bobbel_type == CustomTypes::btFood){
		available_actions = available_actions | CustomTypes::baFollow;			
	}

	bobbel_type = _bobbel_type;
};

double CWQBobbel::calculate_range_from_start()
{

	double side_a, side_b, side_c;
	
	if(get_x() < start_x){
		side_a = start_x - get_x();
	}else{
		side_a = get_x() - start_x;
	}

	if(get_y() < start_y){
		side_b = start_y - get_y();
	}else{
		side_b = get_y() - start_y;
	}

	side_c = side_a*side_a + side_b*side_b;

	return sqrt(side_c);
};

int CWQBobbel::get_bobbel_type()
{
	return bobbel_type;
};

double CWQBobbel::get_x()
{
	return bobbel_dimension.left + (get_width()/2);
};

void CWQBobbel::set_x(double _x)
{												  
	bobbel_dimension.left = (long) _x - (get_width()/2),
	bobbel_dimension.right = bobbel_dimension.left + get_width();
};


double CWQBobbel::get_y()
{
	return bobbel_dimension.top + (get_height()/2);
};


void CWQBobbel::set_y(double _y)
{
	bobbel_dimension.top = (long) _y - (get_height()/2);
	bobbel_dimension.right = bobbel_dimension.top + get_height();
};

int CWQBobbel::get_width()
{
	return width;
};

void CWQBobbel::set_width(int _width)
{
	width = _width;
};

int CWQBobbel::get_height()
{
	return height;
};

void CWQBobbel::set_height(int _height){
	height = _height;
};

double CWQBobbel::get_start_x()
{
	return start_x;
};

double CWQBobbel::get_start_y()
{
	return start_y;
};

double CWQBobbel::get_new_x(double _x)
{
	if (_x < 1) {
		generate_new_direction();
		return 1;
	} else if (_x > map->get_cwq_map_values()->get_width()) {
		generate_new_direction();
		return map->get_cwq_map_values()->get_width();
	} else {
		return _x;
	}
};

double CWQBobbel::get_new_y(double _y)
{			
	if (_y < 1) {
		generate_new_direction();
		return 1;
	} else if (_y > map->get_cwq_map_values()->get_height()){
		generate_new_direction();
		return map->get_cwq_map_values()->get_height();
	} else {
		return _y;
	}
};

long CWQBobbel::get_action_flag()
{
	return action_flag;
};

long CWQBobbel::get_available_actions()
{
	return available_actions;
};

HBITMAP CWQBobbel::get_hbitmap()
{

	if(food_count < 1){
		return textures.at(6)->bitmap;
	}

	if(bobbel_view_direction == CustomTypes::bvdLeft){
		return textures.at(move_count)->bitmap;
	}else if(bobbel_view_direction == CustomTypes::bvdRight){
		return textures.at((move_count+3))->bitmap;
	}else{
		return textures.at(move_count)->bitmap;
	}

}

HBITMAP CWQBobbel::get_hbitmap_mask()
{

	if(food_count < 1){
		return textures.at(6)->bitmap_mask;
	}

	if(move_count > 2){
		move_count = 0;
	}

	if(bobbel_view_direction == CustomTypes::bvdLeft){
		return textures.at(move_count)->bitmap_mask;
	}else if(bobbel_view_direction == CustomTypes::bvdRight){
		return textures.at(move_count+3)->bitmap_mask;
	}else{
		return textures.at(move_count)->bitmap_mask;
	}

}

RECT CWQBobbel::get_bobbel_dimension()
{		
	return CWQBobbel::bobbel_dimension;
};

void CWQBobbel::set_bobbel_dimension(RECT _new_dimension)
{	
	CWQBobbel::bobbel_dimension = _new_dimension;
	x = bobbel_dimension.left + (get_width()/2);
	y = bobbel_dimension.top + (get_height()/2);

};

double CWQBobbel::get_range_of_interest()
{
	return range_of_interest;
};

CWQMap * CWQBobbel::get_map()
{
	return map;
};

CustomTypes::TargetList * CWQBobbel::get_current_target_list()
{
	return &target_list;
};

int CWQBobbel::get_current_target_index()
{
	return current_target;
}

void CWQBobbel::add_texture(CustomTypes::BobbelTexture * _texture){
	textures.push_back(_texture);
}

bool CWQBobbel::has_valid_target()
{
	return has_target;
}

bool CWQBobbel::is_active()
{
	return active;
}

bool CWQBobbel::is_visible()
{
	return visible;
}

void CWQBobbel::set_visible(bool _value)
{
	visible = _value;
}

void CWQBobbel::set_active(bool _value)
{
	active = _value;
}

bool CWQBobbel::bobbel_in_target_list(CWQBobbel *_bobbel)
{
	for(int i = target_list.size()-1; i > -1; i--){
		if(target_list.at(i).target == _bobbel){
			return true;			
		}		
	}

	return false;
}