#include "MyCircle.h"
#include<iostream>
#include "MyPoint.h"

using namespace std;

void MyCircle::setCircle(int _x1, int _y1, int _r)
{
	x1 = _x1;
	y1 = _y1;
	r = _r;
}

void MyCircle::judge(int x0, int  y0)
{
	int a = (x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0) - r*r;
	if (a > 0)
	{
		cout << "点在圆外";
	}
	else
	{
		cout << "点在圆内";
	}
}

void MyCircle::judge(MyPoint &p)
{
	int a = (x1 - p.getX())*(x1 - p.getX()) + (y1 - p.getY())*(y1 - p.getY()) - r*r;
	if (a > 0)
	{
		cout << "点在圆外";
	}
	else
	{
		cout << "点在圆内";
	}
}