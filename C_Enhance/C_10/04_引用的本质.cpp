#include<iostream>

using namespace std;

struct Teacher
{
	int age;
	char name[16];
};

// 只读
int printTe(const Teacher &t)
{
	// t.age = 10; err

	return 0;
}

// 只读
int printTe2(const Teacher * const myp)
{
	// myp->age = 10; err

	return 0;
}

void main04()
{
	char a = NULL;

	char &b = a;

	cout << a << "\n";

	// int &a2 = 19; // err
	const int &a3 = 19;

	system("pause");

	// 引用的本质就是常量指针

	// 引用与指针的区别
	// (1)指针：指针是一个变量，只不过这个变量存储的是一个地址，指向内存的一个存储单元；
	//    引用跟原来的变量实质上是同一个东西，只不过是原变量的一个别名而已。
	// (2)可以有const指针，但是没有const引用；
	// (3)指针可以有多级，但是引用只能是一级（int **p；合法 而 int &&a是不合法的）
	// (4)引用在定义的时候必须初始化；
	// (5)指针的值在初始化后可以改变，即指向其它的存储单元，
	//    引用的至在进行初始化后就不能改变了。
	// (6)"sizeof指针"得到的是指针本身的大小（4字节）；
	//	  "sizeof引用"得到的是所指向的变量(对象)的大小
	// (7)指针和引用的自增(++)运算意义不一样；
}