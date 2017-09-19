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

	// 1������ͷ�ڵ㲢��ʼ��
	pHead = (SList *)malloc(sizeof(SList));
	if (NULL == pHead)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;

	// 2���Ӽ����������ݣ�����ҵ��ڵ�
	printf("please enter the data of node(-1: quit)");
	scanf("%d", &data);

	// 3����ʼ����ǰ�ڵ�ָ��ͷ�ڵ�
	pCur = pHead;

	// ѭ������
	while (-1 != data)
	{
		// 1��malloc �µ�ҵ��ڵ� �� pM
		pM = (SList *)malloc(sizeof(SList));
		if (NULL == pM)
		{
			Destory(pHead);
			return NULL;
		}
		pM->data = data;
		pM->next = NULL;

		// 2���� pM �ڵ�������
		pCur->next = pM;

		// 3��pM �ڵ��ɵ�ǰ�ڵ�
		pCur = pM;

		// 4��������ȡ�û����������
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

	// 1������ͷ�ڵ㲢��ʼ��
	pHead = (SList *)malloc(sizeof(SList));
	if (NULL == pHead)
	{
		ret = -1;
		printf("func Create2() errCode: %d \n", ret);
		return ret;
	}
	pHead->data = 0;
	pHead->next = NULL;

	// 2���Ӽ����������ݣ�����ҵ��ڵ�
	printf("please enter the data of node(-1: quit) ");
	scanf("%d", &data);

	// 3����ʼ����ǰ�ڵ�ָ��ͷ�ڵ�
	pCur = pHead;

	// ѭ������
	while (-1 != data)
	{
		// 1��malloc �µ�ҵ��ڵ� �� pM
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

		// 2���� pM �ڵ�������
		pCur->next = pM;

		// 3��pM �ڵ��ɵ�ǰ�ڵ�
		pCur = pM;

		// 4��������ȡ�û����������
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
		// ������һ���ڵ��λ��
		tmp = p->next;
		free(p); // �ͷŵ�ǰָ��ָ����ڴ�
		p = tmp; // �ڵ�ָ�����
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

	// ׼�� pCur��pPre 
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

	// 1��pM �ڵ����Ӻ������
	pM->next = pPre->next;

	// 2����ǰ���ڵ����� pM
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

		pPre = pCur; // ��ǰ���ڵ����
		pCur = pCur->next;
	}

	if (NULL == pCur)
	{
		ret = -2;
		printf("func Del errCode: %d", ret);
		return ret;
	}

	// ��������ɾ���ڵ�
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
		// һ��Ԫ�ؽڵ㶼û��
		ret = -2;
		printf("func Reverse errCode: %d", ret);
		return ret;
	}

	if (NULL == pHead->next->next)
	{
		// ֻ��һ��Ԫ���޷�����
		ret = -3;
		printf("func Reverse errCode: %d", ret);
		return ret;
	}

	p = pHead->next;
	q = pHead->next->next;

	while (q)
	{
		// ���� q �ĺ�̽ڵ�
		tmp = q->next;

		// ���ò���
		q->next = p;

		// p ����
		p = q;

		// q ����
		q = tmp;
	}

	// ����ĵ� 1 ���ڵ� next ��Ȼָ�� �� 2 ���ڵ㣬���� 2 ���ڵ� next �Ѿ�ָ���˵� 1 ���ڵ㣬����ѭ��
	pHead->next->next = NULL;
	// ͷ�ڵ�ָ�����һ���ڵ�
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