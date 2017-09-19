#pragma once
#include "MyPoint.h"

class MyCircle
{
public:
	void setCircle(int _x1, int _y1, int _r);
	
	void judge(int x0, int  y0);

	void judge(MyPoint &p);

private:
	int x1;
	int y1;
	int r;
};

