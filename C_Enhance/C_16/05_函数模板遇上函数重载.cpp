#include<iostream>

using namespace std;


/*
1 ����ģ���������ͨ����һ��������
2 C++���������ȿ�����ͨ����
3 �������ģ����Բ���һ�����õ�ƥ�䣬��ôѡ��ģ��
4 ����ͨ����ģ�壨<> �����ϸ��͵��ã�ʵ���б���﷨�޶�������ֻͨ��ģ��ƥ��
*/

/*
����ģ�岻�����Զ�����ת��
��ͨ�����ܹ������Զ�����ת��
*/

/*
����ģ��ı��ʣ�
ͨ������֪ ���������˶������
*/
int max(int a, int b)
{
	cout << "int max(int a, int b)" << endl;
	return a > b ? a : b;
}

template <typename T>
T max(T a, T b)
{
	cout << "T max(T a, T b)" << endl;
	return a > b ? a : b;
}

template <typename T>
T max(T a, T b, T c)
{
	cout << "T max(T a, T b, T c)" << endl;
	return max(max(a, b), c);
}

void main()
{
	int a = 1;
	int b = 2;

	cout << max(a, b) << endl;
	cout << max<>(a, b) << endl;

	cout << max(3.0, 4.0) << endl;
	
	cout << max(5.0, 6.0, 7.0) << endl;

	cout << max('a', 100) << endl;

	system("pause");
}