#include<iostream>

using namespace std;

void main01()
{
	cout << "Hello World" << endl;

	system("pause");
}

// struct Circle
class Circle
{
public:
	double R;
	void setR(double r)
	{
		R = r;
	}
	
	double getS()
	{
		return 3.14 * R * R;
	}
};

void main02()
{
	Circle c1;
	double r = 0, s = 0;
	cout << "ÇëÊäÈëÔ²µÄ°ë¾¶ ";

	cin >> r;

	c1.setR(r);

	s = c1.getS();

	std::cout << s << "\n";

	system("pause");
}