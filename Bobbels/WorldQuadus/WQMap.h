#ifndef WQMap_H
#define WQMap_H

#include "WQMapValues.h"
#include "WQDiamondSquareGenerator.h"
#include "WQBitmapHelper.h"
#include <iostream>
#include <vector>
#include <windows.h>

class CWQMap {	

public:		
	CWQMap();
	CWQMap(int _max_z_layer, int _neighbour_count_at_begin);
	CWQMap(const CWQMap& _orig);
	~CWQMap();			
	static const int				map_width = 512;
	static const int				map_height = 512;	
	CWQMapValues *					get_cwq_map_values();		
	void							add_bobbel(CWQBobbel* _new_bobbel);	
	void							initialize_neighborhood();
	void							initialize_kollision_map();
	void							set_default_draw_dc(HDC _draw_dc);
	void							set_default_window_handle(HWND _window_handle);
	void							set_diamond_square_generator(CWQDiamondSquareGenerator * _diamond_square_generator);
	void							set_bitmap_helper(CWQBitmapHelper * _bitmap_helper);
	void							increase_round_count();
	int								get_round_count();
	int								get_max_z_layer();
	int								get_width();
	int								get_height();
	bool							is_map_full();
	bool							dimension_collision(RECT, RECT);
	
	bool							get_born_at(CWQBobbel* _point_to_move, double _x, double _y);
	
	bool							bobbel_range_collision(int _x_to_move, int _y_to_move, CWQBobbel * _bobbel);
	bool							bobbel_range_collision(CWQBobbel * _bobbel_to_move, CWQBobbel * _bobbel);

	bool							bobbel_world_collision(RECT * _dimension_move_to, CWQBobbel * _bobbel_to_move);
	bool							bobbel_world_collision(CWQBobbel* _point_to_move, double _x, double _y);

	bool							bobbel_collision(RECT * _dimension_move_to, CWQBobbel * _bobbel_to_move);
	bool							bobbel_collision(CWQBobbel * _bobbel_to_move, double _x, double _y);

	bool							can_move_to(CWQBobbel* _point_to_move, double _x, double _y, bool ignore_active_objects);
	
	bool							move_to(CWQBobbel* _point_to_move, double _x, double _y);
	bool							move_to(CWQBobbel* _point_to_move, RECT * _dimension_move_to);
	
	
	COLORREF						get_bitmap_pixel_color(HBITMAP hSource, int x, int y);
	CWQDiamondSquareGenerator *		get_diamond_square_generator();
private:
	int								current_z_layer,
									max_z_layer,
									neighbour_count_at_begin,
									scale_collision_map,
									round_count;	
	double							min_height,
									max_height; 
	CWQMapValues					cwq_map_values;
	CustomTypes::NeighboursPerLayer neighbours_per_layer;
	CWQDiamondSquareGenerator *		diamond_square_generator;
	CWQBitmapHelper *				bitmap_helper;
	CustomTypes::BobbelKollisionMap bobbel_kollision_map;
};

#endif