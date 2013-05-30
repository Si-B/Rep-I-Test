#ifndef AStarPathFinding_H
#define AStarPathFinding_H

#include "WQCustomTypes.h"
#include "WQMap.h"
#include "WQBobbel.h"
#include <vector>
#include <iostream>

#include <fstream>
#include <sstream>

namespace AStarPathFinding{

const int not_listed = 0, listed_open = 1, listed_closed = 2;
const double PI(3.14159265);

int which_list[CWQMap::map_width * CWQMap::map_height];
int g_cost_list[CWQMap::map_width * CWQMap::map_height];
int h_cost_list[CWQMap::map_width * CWQMap::map_height];
int f_cost_list[CWQMap::map_width * CWQMap::map_height];
int parent_list[CWQMap::map_width * CWQMap::map_height];

int sorted_f_cost_list[CWQMap::map_width * CWQMap::map_height];

int current_node_to_check_in_which_list = 0;
int current_g_cost = 0;
int current_h_cost = 0;
int items_on_fcost_list = 1;

CustomTypes::Node current_node_in_coords;
CustomTypes::Node current_node_to_check_in_coords;
CustomTypes::Node left_of_current_node_in_coords;
CustomTypes::Node top_left_of_current_node_in_coords;
CustomTypes::Node top_of_current_node_in_coords;
CustomTypes::Node top_right_of_current_node_in_coords;
CustomTypes::Node right_of_current_node_in_coords;
CustomTypes::Node bottom_right_of_current_node_in_coords;
CustomTypes::Node bottom_of_current_node_in_coords;
CustomTypes::Node bottom_left_of_current_node_in_coords;

std::vector<int> path_revert;
//std::vector<CustomTypes::Food *> food_to_check;

int current_node_in_which_list = 0;
int left_of_current_node_in_which_list = 0;
int top_left_of_current_node_in_which_list = 0;
int top_of_current_node_in_which_list = 0;
int top_right_of_current_node_in_which_list = 0;
int right_of_current_node_in_which_list = 0;
int bottom_right_of_current_node_in_which_list = 0;
int bottom_of_current_node_in_which_list = 0;
int bottom_left_of_current_node_in_which_list = 0;

int close_count = 0;
int open_count = 1;

bool path_found = false;
bool calculating = false;
inline bool can_move_there(CustomTypes::Node _node);

inline int get_h_cost(int _x_start, int _y_start, int _x_target, int _y_target);
inline int add_fcost_to_list(int _node_location_in_which_list, int _f_cost);
inline void remove_first_item();

std::stringstream my_log;

std::ofstream myfile;

DWORD calculation_start = 0;

inline std::vector<int> find_path(CWQBobbel * _bobbel_to_move, int _x_start, int _y_start, int _x_target, int _y_target)
{

	double possible_map_points = (_bobbel_to_move->get_range_of_interest()*_bobbel_to_move->get_range_of_interest()) * PI;

	calculating = true;

	close_count = 0;
	open_count = 1;

	int size = CWQMap::map_width * CWQMap::map_height;
	int next_node = 0;
	
	calculation_start = GetTickCount();

	path_found = false;

	items_on_fcost_list = 1;

	for(int i = 0; i < size; i++){
		which_list[i] = not_listed;
	}
	
	current_node_in_coords.x = _x_start;
	current_node_in_coords.y = _y_start; 		

	while(!path_found){

		if(items_on_fcost_list == 1){
			which_list[_x_start * CWQMap::map_width + _y_start] = listed_closed; //setting startnode on closedlist			
			current_node_in_which_list = _x_start * CWQMap::map_width + _y_start;		
		}else{
			remove_first_item();
			current_node_in_which_list = next_node;
			which_list[current_node_in_which_list] = listed_closed; //setting current_node to closed_list
						
			current_node_in_coords.y = current_node_in_which_list%CWQMap::map_width;
			current_node_in_coords.x = (current_node_in_which_list-current_node_in_coords.y)/CWQMap::map_width;

			if(current_node_in_coords.x == _x_target && current_node_in_coords.y == _y_target){
				path_found = true;
				break;
			}
		}

		close_count++;
		open_count--;

		if(open_count < 0)
			break;

		if(open_count > possible_map_points)
			break;

		if(GetTickCount() - calculation_start >100)
			break;

		if(open_count == close_count)
			break;

		//if(GetTickCount() - start > 1000)
		//	break;

		left_of_current_node_in_coords.x = current_node_in_coords.x-1;					   
		left_of_current_node_in_coords.y = current_node_in_coords.y;

		top_left_of_current_node_in_coords.x = current_node_in_coords.x-1;
		top_left_of_current_node_in_coords.y = current_node_in_coords.y-1;

		top_of_current_node_in_coords.x = current_node_in_coords.x;
		top_of_current_node_in_coords.y = current_node_in_coords.y-1;

		top_right_of_current_node_in_coords.x = current_node_in_coords.x+1;
		top_right_of_current_node_in_coords.y = current_node_in_coords.y-1;

		right_of_current_node_in_coords.x = current_node_in_coords.x+1;
		right_of_current_node_in_coords.y = current_node_in_coords.y;

		bottom_right_of_current_node_in_coords.x = current_node_in_coords.x+1;
		bottom_right_of_current_node_in_coords.y = current_node_in_coords.y+1;

		bottom_of_current_node_in_coords.x = current_node_in_coords.x;
		bottom_of_current_node_in_coords.y = current_node_in_coords.y+1;

		bottom_left_of_current_node_in_coords.x = current_node_in_coords.x-1;
		bottom_left_of_current_node_in_coords.y = current_node_in_coords.y+1;

		left_of_current_node_in_which_list = left_of_current_node_in_coords.x * CWQMap::map_width + left_of_current_node_in_coords.y;
		top_left_of_current_node_in_which_list = top_left_of_current_node_in_coords.x * CWQMap::map_width + top_left_of_current_node_in_coords.y;
		top_of_current_node_in_which_list = top_of_current_node_in_coords.x * CWQMap::map_width + top_of_current_node_in_coords.y;
		top_right_of_current_node_in_which_list = top_right_of_current_node_in_coords.x * CWQMap::map_width + top_right_of_current_node_in_coords.y;
		right_of_current_node_in_which_list = right_of_current_node_in_coords.x * CWQMap::map_width + right_of_current_node_in_coords.y;
		bottom_right_of_current_node_in_which_list = bottom_right_of_current_node_in_coords.x * CWQMap::map_width + bottom_right_of_current_node_in_coords.y;
		bottom_of_current_node_in_which_list = bottom_of_current_node_in_coords.x * CWQMap::map_width + bottom_of_current_node_in_coords.y;
		bottom_left_of_current_node_in_which_list = bottom_left_of_current_node_in_coords.x * CWQMap::map_width + bottom_left_of_current_node_in_coords.y;

		for(int i = 0; i < 8; i++){
		
			switch(i){
				case 0: current_node_to_check_in_which_list = left_of_current_node_in_which_list;
						current_node_to_check_in_coords = left_of_current_node_in_coords;
						current_g_cost = 10;
						current_h_cost = get_h_cost(left_of_current_node_in_coords.x, left_of_current_node_in_coords.y, _x_target, _y_target);
						break;
				case 1:	current_node_to_check_in_which_list = top_left_of_current_node_in_which_list;
						current_node_to_check_in_coords = top_left_of_current_node_in_coords;
						current_g_cost = 14;
						current_h_cost = get_h_cost(top_left_of_current_node_in_coords.x, top_left_of_current_node_in_coords.y, _x_target, _y_target);
						break;
				case 2: current_node_to_check_in_which_list = top_of_current_node_in_which_list;
						current_node_to_check_in_coords = top_of_current_node_in_coords;
						current_g_cost = 10;
						current_h_cost = get_h_cost(top_of_current_node_in_coords.x, top_of_current_node_in_coords.y, _x_target, _y_target);
						break;
				case 3: current_node_to_check_in_which_list = top_right_of_current_node_in_which_list;
						current_node_to_check_in_coords = top_right_of_current_node_in_coords;
						current_g_cost = 14;
						current_h_cost = get_h_cost(top_right_of_current_node_in_coords.x, top_right_of_current_node_in_coords.y, _x_target, _y_target);
						break;
				case 4: current_node_to_check_in_which_list = right_of_current_node_in_which_list;
						current_node_to_check_in_coords = right_of_current_node_in_coords;
						current_g_cost = 10;
						current_h_cost = get_h_cost(right_of_current_node_in_coords.x, right_of_current_node_in_coords.y, _x_target, _y_target);
						break;
				case 5: current_node_to_check_in_which_list = bottom_right_of_current_node_in_which_list;
						current_node_to_check_in_coords = bottom_left_of_current_node_in_coords;
						current_g_cost = 14;
						current_h_cost = get_h_cost(bottom_right_of_current_node_in_coords.x, bottom_right_of_current_node_in_coords.y, _x_target, _y_target);
						break;
				case 6:	current_node_to_check_in_which_list = bottom_of_current_node_in_which_list;
						current_node_to_check_in_coords = bottom_of_current_node_in_coords;
						current_g_cost = 10;
						current_h_cost = get_h_cost(bottom_of_current_node_in_coords.x, bottom_of_current_node_in_coords.y, _x_target, _y_target);
						break;
				case 7: current_node_to_check_in_which_list = bottom_left_of_current_node_in_which_list;
						current_node_to_check_in_coords = bottom_left_of_current_node_in_coords;
						current_g_cost = 14;
						current_h_cost = get_h_cost(bottom_left_of_current_node_in_coords.x, bottom_left_of_current_node_in_coords.y, _x_target, _y_target);
						break;
			}
			
			if(current_node_to_check_in_coords.x < 0 || current_node_to_check_in_coords.x > CWQMap::map_width)
				break;

			if(current_node_to_check_in_coords.y < 0 || current_node_to_check_in_coords.y > CWQMap::map_height)
				break;


			if(current_node_to_check_in_which_list > -1 && current_node_to_check_in_which_list < size){
				if(!_bobbel_to_move->get_map()->can_move_to(_bobbel_to_move, current_node_to_check_in_coords.x, current_node_to_check_in_coords.y, true)){			
				}else{
					if(which_list[current_node_to_check_in_which_list] != listed_open && which_list[current_node_to_check_in_which_list] != listed_closed){					
						which_list[current_node_to_check_in_which_list] = listed_open;
						parent_list[current_node_to_check_in_which_list] = current_node_in_which_list;
						g_cost_list[current_node_to_check_in_which_list] = current_g_cost + g_cost_list[parent_list[current_node_to_check_in_which_list]];
						//h_cost_list[current_node_to_check_in_which_list] = current_h_cost;
						f_cost_list[current_node_to_check_in_which_list] = current_h_cost + g_cost_list[current_node_to_check_in_which_list];
						add_fcost_to_list(current_node_to_check_in_which_list, f_cost_list[current_node_to_check_in_which_list]);
						open_count++;
					}					
				}
			}
		}
		next_node = sorted_f_cost_list[1];
	}

	path_revert.clear();

	if(path_found){		
							   
		while(current_node_in_coords.x != _x_start && current_node_in_coords.y != _y_start){

			path_revert.push_back(current_node_in_which_list);
			
			current_node_in_coords.y = current_node_in_which_list%CWQMap::map_width;
			current_node_in_coords.x = (current_node_in_which_list-current_node_in_coords.y)/CWQMap::map_width;

			current_node_in_which_list = parent_list[current_node_in_which_list];
		}			   
	}

	//calculating = false;
	//int calc_time = (GetTickCount() - start);
	//
	//if(calc_time > 250){
		//__asm{int 3};
/*		my_log << GetTickCount() << " PATH_FOUND: " << path_found << " CALC_TIME: " << calc_time << " POSSIBLE_NODES: " << possible_map_points << " OPEN_NODES:" << open_count << " CLOSED_NODES: " << close_count << std::endl;	
		myfile << my_log.str()*/;
	//}

	//

	//myfile.close();
	return path_revert;
}

inline bool can_move_there(CustomTypes::Node _node){

	if(_node.x == 2 && _node.y == 2){
		return false;
	}else{
		return true;
	}
	if(_node.x == 2 && _node.y == 3){
		return false;
	}else{
		return true;
	}
	if(_node.x == 2 && _node.y == 1){
		return false;
	}else{
		return true;
	}

}

inline int add_fcost_to_list(int _node_location_in_which_list, int _f_cost)
{	
	int current_location_in_heap = 0;
	int location_cache = 0;
	int last_insert = 0;
	int f_cost_of_current_sorted_entry = 0;

	sorted_f_cost_list[items_on_fcost_list] = _node_location_in_which_list;
	last_insert = items_on_fcost_list;
	current_location_in_heap = items_on_fcost_list/2;
	
	while(current_location_in_heap > 0){
		f_cost_of_current_sorted_entry = f_cost_list[sorted_f_cost_list[current_location_in_heap]];
		if(f_cost_of_current_sorted_entry > _f_cost && f_cost_list[sorted_f_cost_list[current_location_in_heap]] > 0){ //wenn neuer f wert kleiner ist als das seines elternteiles, tauschen
			location_cache = sorted_f_cost_list[current_location_in_heap];
			sorted_f_cost_list[current_location_in_heap] = _node_location_in_which_list;
			sorted_f_cost_list[last_insert] = location_cache;
		}
		 current_location_in_heap = current_location_in_heap/2;
		 last_insert /= 2;
	}

	items_on_fcost_list++;

	return 0;
}

inline void remove_first_item()
{
	int f_cost_children_1 = 0;
	int f_cost_children_2 = 0;
	int f_cost_cache = 0;

	sorted_f_cost_list[1] = sorted_f_cost_list[items_on_fcost_list-1];

	for(int i = 1; (i*2)+1 < items_on_fcost_list; i++){
	
		f_cost_children_1 = f_cost_list[sorted_f_cost_list[i*2]];
		f_cost_children_2 = f_cost_list[sorted_f_cost_list[(i*2)+1]];

		if(f_cost_list[sorted_f_cost_list[i]] < f_cost_children_1){
			f_cost_cache = sorted_f_cost_list[i*2];
			sorted_f_cost_list[i*2] = sorted_f_cost_list[i];
			sorted_f_cost_list[i] = f_cost_cache;

		}else if(f_cost_list[sorted_f_cost_list[i]] < f_cost_children_2){
			f_cost_cache = sorted_f_cost_list[(i*2)+1];
			sorted_f_cost_list[(i*2)+1] = sorted_f_cost_list[i];
			sorted_f_cost_list[i] = f_cost_cache;
		}else{
			if(f_cost_children_1 < f_cost_children_2){
				f_cost_cache = sorted_f_cost_list[i*2];
				sorted_f_cost_list[i*2] = sorted_f_cost_list[i];
				sorted_f_cost_list[i] = f_cost_cache;				
			}else{
				f_cost_cache = sorted_f_cost_list[i*2+1];
				sorted_f_cost_list[i*2+1] = sorted_f_cost_list[i];
				sorted_f_cost_list[i] = f_cost_cache;				
			}
		}

	}

}

int get_g_cost(int _x_start, int _y_start, int _x_neighbor, int _y_neighbor)
{

	int g_cost = 10;

	if(_y_start > _y_neighbor && _x_start > _x_neighbor){ //diagonal way top left
		g_cost += 4;	
	}else if(_y_start > _y_neighbor && _x_start < _x_neighbor){ //diagonal way top right
		g_cost += 4;	
	}else if(_y_start < _y_neighbor && _x_start > _x_neighbor){ //diagonal way bottom left
		g_cost += 4;
	}else if(_y_start < _y_neighbor && _x_start < _x_neighbor){ //diagonal way bottom right
		g_cost += 4;
	}

	return g_cost;
}

inline int get_h_cost(int _x_start, int _y_start, int _x_target, int _y_target)
{
	int xd = 0, yd = 0;

	if(_x_start < _x_target){
		xd = _x_target - _x_start;
	}else{
		xd = _x_start - _x_target;
	}

	if(_y_start < _y_target){
		yd = _y_target - _y_start;
	}else{
		yd = _y_start - _y_target;
	}	

	return (yd + xd) * 10;

}
};
#endif