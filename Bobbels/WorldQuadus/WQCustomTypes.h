#ifndef CustomTypes_H
#define CustomTypes_H

#include <map>
#include <vector>
#include <windows.h>

class CWQBobbel;

namespace CustomTypes
{
	struct BobbelLink{
		CWQBobbel * target;
		long available_actions;
		long current_action;
		bool reachable;
		bool execute_action;
		bool action_complete;
		bool active;
		std::vector<int> path_to_target;
		DWORD last_path_check;
	};

	struct BobbelTexture{
		HBITMAP bitmap;
		HBITMAP bitmap_mask;
	};

	struct Node{
		int x;
		int y;
		int f_cost;
	};

	struct MapValue{
		float height;
	};

	enum BobbelActions{
		baMove = 2,
		baEat = 4,
		baCollect = 8,
		baFollow = 16
	};

	enum BobbelViewDirection{
		bvdLeft,
		bvdRight
	};

	enum BobbelTypes{
		btStandard,
		btFood
	};

	typedef std::vector<CWQBobbel* > BobbelsOnMap;
	typedef std::vector<std::vector<int> > NeighboursPerLayer;
	typedef std::vector<BobbelsOnMap > BobbelKollisionMap;
	typedef std::vector<BobbelLink> TargetList;

};

#endif