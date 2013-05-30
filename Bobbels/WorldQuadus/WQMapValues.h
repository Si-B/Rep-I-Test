#ifndef WQMapValues_H
#define WQMapValues_H

#include <iostream>
#include <map>
#include "WQCustomTypes.h"

class CWQMapValues{

public: 		
	CWQMapValues();
	CWQMapValues(int, int);	
	~CWQMapValues();
	void							add_bobbel(CWQBobbel* _new_bobbel);
	int								get_width();
	int								get_height();
	int								get_size();
	int								get_bobbel_add_count();
	bool							is_map_full();
	CustomTypes::BobbelsOnMap *		get_bobbels_on_map();
	CustomTypes::BobbelsOnMap *		get_bobbels_on_map_static();
private:
	CustomTypes::BobbelsOnMap		bobbels_on_map;
	CustomTypes::BobbelsOnMap		bobbels_on_map_static;
	int								width,
									height,
									size,
									bobbel_add_count;
};

#endif