#include "WQBobbelActionManager.h"
#include "WQCustomTypes.h"
#include "WQMap.h"
#include "WQBobbel.h"
#include "WQMapValues.h"

CWQBobbelActionManager * CWQBobbelActionManager::pInstance = 0;

CWQBobbelActionManager * CWQBobbelActionManager::instance()
{
	if(pInstance == 0){
		pInstance = new CWQBobbelActionManager();
	}

	return pInstance;
}

CWQBobbelActionManager::CWQBobbelActionManager(void):execute_enabled(true)
{
}

CWQBobbelActionManager::~CWQBobbelActionManager(void)
{
	current_map = 0;
}

void CWQBobbelActionManager::execute(CWQMap * map)
{	

	if(!execute_enabled)
		return;

	CustomTypes::BobbelsOnMap::iterator it;	

	for (it = map->get_cwq_map_values()->get_bobbels_on_map()->begin(); it !=  map->get_cwq_map_values()->get_bobbels_on_map()->end(); it++){	
		if(it[0]->get_action_flag() & CustomTypes::baMove){
			it[0]->let_move_own_direction();
		}else if(it[0]->get_action_flag() & CustomTypes::baCollect){
			it[0]->let_move_own_direction();
		}
	}

}

void CWQBobbelActionManager::set_map(CWQMap * _map)
{
	current_map = _map;
}

void CWQBobbelActionManager::enable()
{
	execute_enabled = true;
}

void CWQBobbelActionManager::disable()
{
	execute_enabled = false;
}

bool CWQBobbelActionManager::is_enabled()
{
	return execute_enabled;
}