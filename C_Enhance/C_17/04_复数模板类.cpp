#include<iostream>

using namespace std;

template<typename T>
class Complex
{
public:
	Complex();
	Complex(T real, T image);
	Complex(T a)
	{
		this->_real = a;
		this->_image = 0;
	}
	void print() const;

	Complex operator+(const Complex<T> &c)
	{
		return Complex(this->_real + c._real, this->_image + c._image);
	}
private:
	T _real;
	T _image;
};

template<typename T>
Complex<T>::Complex()
{
	this->_real = 0;
	this->_image = 0;
}

template<typename T>
Complex<T>::Complex(T real, T image)
{
	this->_real = real;
	this->_image = image;
}

template<typename T>
void Complex<T>::print() const
{
	cout << this->_real << " + " << this->_image << endl;
}

void main04()
{
	Complex<double> c1(2.5, 3.7), c2(4.2, 6.5);
	Complex<double> c;
	c1.print();

	c = c1 + c2;
	c.print();

	system("pause");
}