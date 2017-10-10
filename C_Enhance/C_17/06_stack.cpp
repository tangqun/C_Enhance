#include<iostream>
#include<stack>

using namespace std;

void printstack(stack<int> &s)
{
	while (!s.empty())
	{
		int tmp = s.top();

		s.pop();

		cout << tmp << " ";
	}
	cout << endl;
}

void main06()
{
	stack<int> s1;

	for (int i = 0; i < 5; i++)
	{
		s1.push(i);
	}

	/*while (!s1.empty())
	{
		int tmp = s1.top();

		s1.pop();

		cout << tmp << " ";
	}
	cout << endl;*/

	printstack(s1);

	system("pause");
}