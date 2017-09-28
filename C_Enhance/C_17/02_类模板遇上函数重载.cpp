#include<iostream>

using namespace std;

template<typename T>
class A2
{
public:
	A2(T real, T image);

private:
	T _real;
	T _image;
};

template<typename T>
A2<T>::A2(T real, T image)
{
	this->_real = real;
	this->_image = image;
}

void main02()
{
	system("pause");
}