#include<iostream>

using namespace std;

class A11
{
public:
	A11(int x, int y)
	{
		_x = x;
		_y = y;
	};
	~A11()
	{

	};

private:
	int _x;
	int _y;
};

void main11()
{
	int *a = new int(100);
	*a = 200;
	delete a;

	int *b = new int[100];
	b[0] = 1;
	b[1] = 2;
	delete[] b;

	A11 *c = new A11(1, 2);
	delete c;

	int *a2 = (int *)malloc(sizeof(int));
	free(a2);

	int *b2 = (int *)malloc(100 * sizeof(int));
	b2[0] = 1;
	b2[1] = 2;
	free(b2);

	A11 *c2 = (A11 *)malloc(sizeof(A11)); // 不会调用构造函数
	free(c2); // 不会调用析构函数
}