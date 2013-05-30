#ifndef WQBobbel_H
#define WQBobbel_H

#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <vector>

class CWQMap;

class CWQBobbel{

public:
	CWQBobbel();
	CWQBobbel(CWQMap* _map);	
	~CWQBobbel();

	static int									count;	
	void										get_born();
	void										let_move_own_direction();
	inline void									move_random_direction();
	inline void									follow_current_target();
	inline void									take_current_target_to_start();
	void										set_bobbel_dimension(RECT);
	void										set_x(double _x);
	void										set_y(double _y);
	void										set_z(int _z);
	void										set_width(int _width);
	void										set_height(int _height);
	void										set_active(bool _value);
	void										set_visible(bool _value);
	inline void									generate_new_direction();
	inline void									increase_range_of_interest();
	void									disable_move();
	inline void									enable_move();
	void										set_bobbel_type(int);
	void										add_target(CWQBobbel * _target);	
	void										arrived_at(CWQBobbel * _target);
	void										add_texture(CustomTypes::BobbelTexture * _texture);
	int											get_z();
	int											get_width();
	int											get_height();
	int											get_bobbel_type();
	int											get_current_target_index();
	long										get_action_flag();
	long										get_available_actions();
	inline double								get_move_direction();	
	double										get_x();
	double										get_y();
	inline double								get_new_x(double _x);
	inline double								get_new_y(double _y);
	double										get_start_x();
	double										get_start_y();
	double										get_range_of_interest();	
	inline double								calculate_range_from_start();
	inline bool									has_valid_target();
	inline bool									find_reachable_target();
	bool										is_active();
	bool										is_visible();
	HBITMAP										get_hbitmap();
	HBITMAP										get_hbitmap_mask();
	RECT										get_bobbel_dimension();
	CWQMap *									get_map();
	CustomTypes::TargetList *					get_current_target_list();
private:
	int											width;
	int											height;
	int											z;																												
	int											move_count;
	int											food_count;
	int											bobbel_type;
	int											place;
	unsigned int								step_count;
	unsigned int								current_target;
	double										x;
	double										y;
	double										start_x;
	double										start_y;
	double										range_of_interest;
	double										current_view_angle;
	long										action_flag;
	long										available_actions;
	bool										visible;
	bool										active;
	bool										has_target;
	inline bool									bobbel_in_target_list(CWQBobbel * _bobbel);
	CWQMap *									map;	
	RECT										bobbel_dimension;
	CustomTypes::TargetList						target_list;	
	std::vector<CustomTypes::BobbelTexture*>	textures;
	CustomTypes::BobbelViewDirection			bobbel_view_direction;
};



#endif