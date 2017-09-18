#include<iostream>

using namespace std;

int add(int *a, int *b)
{
	return *a + *b;
}

// int * const a, int * const b
int add2(int &a, int &b)
{
	return a + b;
}

int assign(int *p)
{
	*p = 100;

	return 0;
}

int assign2(int &p)
{
	p = 120;

	return 0;
}

int assignPoint(int *p)
{
	p = (int *)0x01;

	return 0;
}

void main()
{
	int a = 10, b = 20;
	int sum = 0;

	int &b2 = b;

	cout << b2 << "\n";

	b = 30;

	cout << "b: " << b << ", b2: " << b2 << "\n";

	*(&b2) = 40;
	
	cout << "b: " << b << ", b2: " << b2 << "\n";

	b2 = 50;

	cout << "b: " << b << ", b2: " << b2 << "\n";

	assign(&b);

	cout << "b: " << b << ", b2: " << b2 << "\n";

	/*assign(&b2);

	cout << "b: " << b << ", b2: " << b2 << "\n";*/

	/*assign2(b);

	cout << "b: " << b << ", b2: " << b2 << "\n";*/

	assign2(b2);

	cout << "b: " << b << ", b2: " << b2 << "\n"; 

	assignPoint(&b2);

	cout << "b: " << b << ", b2: " << b2 << "\n";

	cout << "&b: " << &b << ", &b2: " << &b2 << "\n";
	
	sum = add(&a, &b);
	cout << sum << "\n";

	sum = add2(a, b);

	cout << sum << "\n";

	system("pause");
}