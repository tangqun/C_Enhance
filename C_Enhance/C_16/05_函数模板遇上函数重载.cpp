#include<iostream>

using namespace std;


/*
1 函数模板可以像普通函数一样被重载
2 C++编译器优先考虑普通函数
3 如果函数模板可以产生一个更好的匹配，那么选择模板
4 可以通过空模板（<> 就是严格泛型调用）实参列表的语法限定编译器只通过模板匹配
*/

/*
函数模板不允许自动类型转化
普通函数能够进行自动类型转换
*/

/*
函数模板的本质：
通过汇编得知 就是生成了多个函数
*/
int max(int a, int b)
{
	cout << "int max(int a, int b)" << endl;
	return a > b ? a : b;
}

template <typename T>
T max(T a, T b)
{
	cout << "T max(T a, T b)" << endl;
	return a > b ? a : b;
}

template <typename T>
T max(T a, T b, T c)
{
	cout << "T max(T a, T b, T c)" << endl;
	return max(max(a, b), c);
}

void main()
{
	int a = 1;
	int b = 2;

	cout << max(a, b) << endl;
	cout << max<>(a, b) << endl;

	cout << max(3.0, 4.0) << endl;
	
	cout << max(5.0, 6.0, 7.0) << endl;

	cout << max('a', 100) << endl;

	system("pause");
}