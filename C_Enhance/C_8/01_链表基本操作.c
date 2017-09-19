#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int data;
	struct Node *next;
}SList;

SList *Create();
int Create2(SList **pHead);
int Print(SList *pHead);
int Destory(SList *pHead);
int Insert(SList *pHead, int x, int y);
int Del(SList *pHead, int x);
int Reverse(SList *pHead);

SList *Create()
{
	SList *pHead = NULL, *pM = NULL, *pCur = NULL;
	int data = 0;

	// 1、创建头节点并初始化
	pHead = (SList *)malloc(sizeof(SList));
	if (NULL == pHead)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;

	// 2、从键盘输入数据，创建业务节点
	printf("please enter the data of node(-1: quit)");
	scanf("%d", &data);

	// 3、初始化当前节点指向头节点
	pCur = pHead;

	// 循环创建
	while (-1 != data)
	{
		// 1、malloc 新的业务节点 给 pM
		pM = (SList *)malloc(sizeof(SList));
		if (NULL == pM)
		{
			Destory(pHead);
			return NULL;
		}
		pM->data = data;
		pM->next = NULL;

		// 2、让 pM 节点入链表
		pCur->next = pM;

		// 3、pM 节点变成当前节点
		pCur = pM;

		// 4、继续获取用户输入的数据
		printf("please enter the data of node(-1: quit)");
		scanf("%d", &data);
	}

	return pHead;
}

int Create2(SList **mypHead)
{
	int ret = 0;
	SList *pHead = NULL, *pM = NULL, *pCur = NULL;
	int data = 0;

	// 1、创建头节点并初始化
	pHead = (SList *)malloc(sizeof(SList));
	if (NULL == pHead)
	{
		ret = -1;
		printf("func Create2() errCode: %d \n", ret);
		return ret;
	}
	pHead->data = 0;
	pHead->next = NULL;

	// 2、从键盘输入数据，创建业务节点
	printf("please enter the data of node(-1: quit) ");
	scanf("%d", &data);

	// 3、初始化当前节点指向头节点
	pCur = pHead;

	// 循环创建
	while (-1 != data)
	{
		// 1、malloc 新的业务节点 给 pM
		pM = (SList *)malloc(sizeof(SList));
		if (NULL == pM)
		{
			Destory(pHead);
			ret = -2;
			printf("func Create2() errCode: %d \n", ret);
			return ret;
		}
		pM->data = data;
		pM->next = NULL;

		// 2、让 pM 节点入链表
		pCur->next = pM;

		// 3、pM 节点变成当前节点
		pCur = pM;

		// 4、继续获取用户输入的数据
		printf("please enter the data of node(-1: quit) ");
		scanf("%d", &data);
	}

	*mypHead = pHead;
	return ret;
}

int Print(SList *pHead)
{
	int ret = 0;
	SList *p = NULL;

	if (NULL == pHead)
	{
		ret = -1;
		printf("func Print errCode: %d \n", ret);
		return ret;
	}

	p = pHead->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}

	return ret;
}

int Destory(SList *pHead)
{
	int ret = 0;
	SList *p = NULL, *tmp = NULL;

	if (NULL == pHead)
	{
		ret = -1;
		printf("func Destory errCode: %d", ret);
		return ret;
	}

	p = pHead;
	while (p)
	{
		// 保存下一个节点的位置
		tmp = p->next;
		free(p); // 释放当前指针指向的内存
		p = tmp; // 节点指针后移
	}

	return 0;
}

int Insert(SList *pHead, int x, int y)
{
	int ret = 0;
	SList *pCur = NULL, *pPre = NULL, *pM = NULL;

	pM = (SList *)malloc(sizeof(SList));
	if (NULL == pM)
	{
		ret = -1;
		printf("func Insert errCode: %d", ret);
		return ret;
	}
	pM->data = y;
	pM->next = NULL;

	// 准备 pCur、pPre 
	pPre = pHead;
	pCur = pHead->next;

	while (pCur)
	{
		if (pCur->data == x)
		{
			break;
		}

		pPre = pCur;
		pCur = pCur->next;
	}

	// 1、pM 节点链接后继链表
	pM->next = pPre->next;

	// 2、让前驱节点连接 pM
	pPre->next = pM;

	return ret;
}

int Del(SList *pHead, int x)
{
	int ret = 0;
	SList *pCur = NULL, *pPre = NULL;

	if (NULL == pHead)
	{
		ret = -1;
		printf("func Del errCode: %d", ret);
		return ret;
	}

	pPre = pHead;
	pCur = pHead->next;

	while (pCur)
	{
		if (pCur->data == x)
		{
			break;
		}

		pPre = pCur; // 让前驱节点后移
		pCur = pCur->next;
	}

	if (NULL == pCur)
	{
		ret = -2;
		printf("func Del errCode: %d", ret);
		return ret;
	}

	// 从链表上删除节点
	pPre->next = pCur->next;
	free(pCur);

	return ret;
}

int Reverse(SList *pHead)
{
	int ret = 0;
	SList *tmp = NULL, *p = NULL, *q = NULL;

	if (NULL == pHead)
	{
		ret = -1;
		printf("func Reverse errCode: %d", ret);
		return ret;
	}

	if (NULL == pHead->next)
	{
		// 一个元素节点都没有
		ret = -2;
		printf("func Reverse errCode: %d", ret);
		return ret;
	}

	if (NULL == pHead->next->next)
	{
		// 只有一个元素无法逆置
		ret = -3;
		printf("func Reverse errCode: %d", ret);
		return ret;
	}

	p = pHead->next;
	q = pHead->next->next;

	while (q)
	{
		// 保存 q 的后继节点
		tmp = q->next;

		// 逆置操作
		q->next = p;

		// p 后移
		p = q;

		// q 后移
		q = tmp;
	}

	// 最初的第 1 个节点 next 仍然指向 第 2 个节点，而第 2 个节点 next 已经指向了第 1 个节点，无限循环
	pHead->next->next = NULL;
	// 头节点指向最后一个节点
	pHead->next = p;

	return ret;
}

void main()
{
	int ret = 0;
	SList *pHead = NULL;

	ret = Create2(&pHead);
	if (0 != ret)
	{
		printf("func Create2 errCode: %d", ret);
		return;
	}

	ret = Print(pHead);
	if (0 != NULL)
	{
		printf("func Print errCode: %d", ret);
		return;
	}
	printf("\n");

	ret = Insert(pHead, 20, 19);
	if (0 != NULL)
	{
		printf("func Insert errCode: %d", ret);
		return;
	}

	ret = Print(pHead);
	if (0 != NULL)
	{
		printf("func Print errCode: %d", ret);
		return;
	}
	printf("\n");

	ret = Del(pHead, 19);
	if (0 != NULL)
	{
		printf("func Del errCode: %d", ret);
		return;
	}

	ret = Print(pHead);
	if (0 != NULL)
	{
		printf("func Print errCode: %d", ret);
		return ;
	}
	printf("\n");

	ret = Reverse(pHead);
	if (0 != NULL)
	{
		printf("func Reverse errCode: %d", ret);
		return;
	}

	ret = Print(pHead);
	if (0 != NULL)
	{
		printf("func Print errCode: %d", ret);
		return;
	}
	printf("\n");

	system("pause");
}