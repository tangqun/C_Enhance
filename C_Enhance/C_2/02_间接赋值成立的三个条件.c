#include<stdio.h>
#include<stdlib.h>

/*
间接赋值成立的 3 个条件
1、定义 1 个变量（实参）
2、建立关联：把实参取地址传给形参
3、*形参 去间接的修改实参的值
*/
void main()
{
	int a = 10;
	int *p = NULL;

	a = 20; // 直接修改
	printf("a: %d", a);

	p = &a;
	*p = 100; // 间接修改
	printf("a: %d", a);

	system("pause");
}