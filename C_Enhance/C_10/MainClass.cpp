#include<iostream>
#include "MyPoint.h"
#include "MyCircle.h"

using namespace std;

void main()
{
	MyPoint myp;
	MyCircle c1;

	myp.setP(1, 1);
	c1.setCircle(2, 2, 3);
	c1.judge(myp);

	system("pause");
	system("pause");
}