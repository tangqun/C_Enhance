#include<stdio.h>
#include<stdlib.h>

/*
��Ӹ�ֵ������ 3 ������
1������ 1 ��������ʵ�Σ�
2��������������ʵ��ȡ��ַ�����β�
3��*�β� ȥ��ӵ��޸�ʵ�ε�ֵ
*/
void main()
{
	int a = 10;
	int *p = NULL;

	a = 20; // ֱ���޸�
	printf("a: %d", a);

	p = &a;
	*p = 100; // ����޸�
	printf("a: %d", a);

	system("pause");
}