#include<iostream>
#include<vector>

using namespace std;

void printvector(vector<int> &v)
{
	int vlen = v.size();
	for (int i = 0; i < vlen; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

void main05()
{
	vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);

	printvector(v1);

	vector<int> v2(10);
	printvector(v2);

	system("pause");
}