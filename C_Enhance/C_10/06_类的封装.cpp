#include<iostream>

using namespace std;

class Circle
{
public:
	void setR(int r)
	{
		_r = r;
	}

	double getR()
	{
		return _r;
	}

	double getS()
	{
		return 3.14 * _r * _r;
	}
private:
	double _r;
	double _s;
};

void main06()
{
	Circle c1, c2;

	c1.setR(10);
	cout << "Բ�İ뾶: " << c1.getR() << "\n";

	c2.setR(20);
	cout << "Բ�İ뾶: " << c2.getR() << "�����: " << c2.getS() << "\n";

	system("pause");
}