#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

typedef struct _LinkList
{
	int data;
	struct _LinkList *next;
} LinkList;

int create_list(LinkList **pHead);
int delEven_list(LinkList *pHead);
void print_list(LinkList *pHead);

int create_list(LinkList **mypHead)
{
	int ret = 0, data = 0;
	LinkList *pHead = NULL, *pCur = NULL, *pM = NULL;

	pHead = (LinkList *)malloc(sizeof(LinkList));
	if (NULL == pHead)
	{
		ret = -1;
		printf("func create_list errCode: %d", ret);
		return ret;
	}
	pHead->data = 0;
	pHead->next = NULL;

	printf("please enter the data of node(-1: quit)");
	scanf("%d", &data);

	pCur = pHead;

	while (-1 != data)
	{
		pM = (LinkList *)malloc(sizeof(LinkList));
		if (NULL == pM)
		{
			ret = -2;
			printf("func create_list errCode: %d \n", ret);
			return ret;
		}
		pM->data = data;
		pM->next = NULL;

		pCur->next = pM;

		pCur = pM;

		printf("please enter the data of node(-1: quit)");
		scanf("%d", &data);
	}

	*mypHead = pHead;
	return 0;
}

int delEven_list(LinkList *pHead)
{
	int ret = 0;
	LinkList *pCur = NULL, *pPre = NULL, *pTmp = NULL;

	if (NULL == pHead)
	{
		ret = -1;
		printf("func delEven_list errCode: %d", ret);
		return ret;
	}

	pPre = pHead;
	pCur = pHead->next;

	while (pCur)
	{
		if (pCur->data % 2 == 0)
		{
			pTmp = pCur;
			pPre->next = pCur->next;
			pCur = pCur->next;
			free(pTmp);
		}
		else
		{
			pPre = pCur;
			pCur = pCur->next;
		}

		
	}

	return 0;
}

void print_list(LinkList *pHead)
{
	if (NULL == pHead)
	{
		return;
	}

	LinkList *p = pHead->next;

	while (NULL != p)
	{
		printf("%d ", p->data);
		p = p->next;
	}

	printf("\n");
}

void main03()
{
	/*3 链表如下
	typedef struct _LinkList
	{
	int data;
	struct _LinkList*next;
	} LinkList;
	有如下结点数据域  1 2 3 4 5 6 7 8 12 19 。。。。
	要求1：创建链表
	要求2：删除结点值为偶数的结点 ；70分
	要求3：编写测试用例  30分
	*/

	int ret = 0;
	LinkList *pHead = NULL;

	ret = create_list(&pHead);
	if (ret != 0)
	{
		printf("func create errCode: %d", ret);
		return;
	}

	printf("删除前 \n");
	print_list(pHead);

	ret = delEven_list(pHead);
	if (ret != 0)
	{
		printf("func delEven errCode: %d", ret);
		return;
	}

	printf("删除后 \n");
	print_list(pHead);

	system("pause");
}