#ifndef WQBobbelActionManager_H
#define WQBobbelActionManager_H

#include "WQMap.h"

class CWQBobbelActionManager
{
public:
	static CWQBobbelActionManager* 			instance();
	void									execute(CWQMap * map);	
	void									set_map(CWQMap * map);
	void									enable();
	void									disable();
	bool									is_enabled();
	int										get_new_x(int _x, CWQBobbel * _bobbel_to_move);
	int										get_new_y(int _y, CWQBobbel * _bobbel_to_move);
private:
	CWQBobbelActionManager(void);	
	~CWQBobbelActionManager(void);
	static CWQBobbelActionManager *	 		pInstance;
	CWQMap *								current_map;
	void									let_bobbel_move(CWQBobbel * _bobbel_to_move);
	bool									execute_enabled;
};

#endif
