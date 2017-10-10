#include<iostream>

using namespace std;

template<class T>
class Complex;

template<class T>
Complex<T> sub(Complex<T> &c1, Complex<T> &c2);

template<class T>
class Complex
{
public:
	Complex(T real, T image);
	Complex(T a);

	Complex operator-(Complex &c2)
	{
		Complex tmp(this->_real - c2._real, this->_image - c2._image);
		return tmp;
	}

	friend Complex operator+<T>(Complex &c1, Complex &c2);// <T> �ñ�������������ʹ�õ����͵� ���ͺ���
	friend Complex sub<T>(Complex &c1, Complex &c2); 

	friend ostream operator<<(ostream &out, Complex &c);

	void print()
	{
		cout << this->_real << " + " << this->_image << "i" << endl;
	}
private:
	int _real;
	int _image;
};

template<class T>
Complex<T>::Complex(T real, T image)
{
	this->_real = real;
	this->_image = image;
}

template<class T>
Complex<T>::Complex(T a)
{
	this->_real = a;
	this->_image = 0;
}

//������	����	˵��	��Ŀ	�ļ�	��	��ֹ��ʾ״̬
//����	LNK2019	�޷��������ⲿ���� 
//"class Complex<int> __cdecl operator+(class Complex<int> &,class Complex<int> &)" (? ? H@YA?AV ? $Complex@H@@AAV0@0@Z)���÷����ں��� _main �б�����	C_18	E : \github\C_Enhance\C_Enhance\C_18\02_��ģ��������Ԫ���������������ѽ��.obj	1

template<class T>
Complex<T> operator+(Complex<T> &c1, Complex<T> &c2)
{
	Complex<T> tmp(c1._real + c2._real, c1._image + c2._image);
	return tmp;
}

template<class T>
Complex<T> sub(Complex<T> &c1, Complex<T> &c2)
{
	Complex<T> tmp(c1._real - c2._real, c1._image - c2._image);
	return tmp;
}

template<class T>
ostream operator<<(ostream &out, Complex<T> &c1)
{
	out << c1._real << " + " << c1._image << "i" << endl;
	return out;
}

void main()
{
	Complex<int> c1(10, 20);
	Complex<int> c2(2, 4);

	Complex<int> c3 = c1 - c2;
	c3.print();

	Complex<int> c4 = c1 + c2;
	c4.print();

	Complex<int> c5 = sub(c1, c2);
	c5.print();

	system("pause");
}