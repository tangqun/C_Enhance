#include<iostream>

using namespace std;

class Test5
{
public:
	Test5();
	~Test5();

	int getA() const
	{
		//this->_a++;
		return _a;
	}
private:
	int _a;
	int _b;
};

Test5::Test5()
{
}

Test5::~Test5()
{
}

void main()
{

}