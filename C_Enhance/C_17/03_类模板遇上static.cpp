#include<iostream>

using namespace std;

template<typename T>
class A3
{
public:
	static T _stp;

private:
	T _tp;
};

template<typename T>
T A3<T>::_stp = 0;

void main03()
{
	A3<int> a1;
	A3<int> a2; // 同种类型的 static 共用一个  a1 、 a2 值相等

	A3<char> b1; // 生成了 int、char 两个类  
	A3<char> b2;

	a1._stp++;
	b2._stp = 100;

	cout << a1._stp << endl;
	cout << b2._stp << endl;
	cout << b2._stp << endl;

	system("pause");
}