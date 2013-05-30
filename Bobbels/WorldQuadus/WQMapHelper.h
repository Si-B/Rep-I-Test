#ifndef WQMapHelper_H
#define WQMapHelper_H

class CWQMap;

class CWQMapHelper
{
public:
	static CWQMapHelper *			instance();
	void							generate_food(CWQMap * _map);
	double							get_range(int _x1, int _y1, int _x2, int _y2);	
private:
	CWQMapHelper(void);
	~CWQMapHelper(void);
	static CWQMapHelper *			pInstance;
};

#endif