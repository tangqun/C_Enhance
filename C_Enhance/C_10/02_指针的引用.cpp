#include<iostream>

using namespace std;

struct Teacher
{
	int age;
	char name[32];
};

int getTe(Teacher **myp)
{
	Teacher *p = (Teacher *)malloc(sizeof(Teacher));

	if (NULL == p)
	{
		return -1;
	}

	p->age = 100;

	*myp = p;

	return 0;
}

int getTe2(Teacher * &myp)
{
	Teacher *p = (Teacher *)malloc(sizeof(Teacher));

	if (NULL == p)
	{
		return -1;
	}

	p->age = 100;

	myp = p;

	return 0;
}

void main02()
{
	Teacher *p = NULL;

	//getTe(&p);
	getTe2(p);

	cout << p->age << "\n";

	system("pause");
}