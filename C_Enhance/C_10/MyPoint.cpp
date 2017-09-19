#include "MyPoint.h"
#include<iostream>

using namespace std;

void MyPoint::setP(int _x0, int _y0)
{
	x0 = _x0;
	y0 = _y0;
}
int MyPoint::getX()
{
	return x0;
}
int MyPoint::getY()
{
	return y0;
}

