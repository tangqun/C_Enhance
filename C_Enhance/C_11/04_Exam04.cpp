#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


int del(const char *str1, int num, char **str2);
void print(char *str);

int del(const char *str1, int num, char **str2)
{
	int ret = 0;
	char *p = (char *)malloc(100 * sizeof(char));

	if (NULL == str1)
	{
		ret = -1;
		printf("func del errCode: %d", ret);
		return ret;
	}

	if (NULL == p)
	{
		ret = -2;
		printf("func del errCode: %d", ret);
		return ret;
	}

	strncpy(p, str1, num - 1);
	strcpy(&p[num - 1], &str1[num]);

	*str2 = p;

	return 0;
}

void print(char *str)
{
	int i = 0;
	if (NULL == str)
	{
		return;
	}

	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}

	printf("\n");
}

void main04()
{
	/*4���Ӽ���������һ��������40���ַ����ַ�����������3��λ����ÿ��ɾ��һ���ַ�����ɾ����Ӧ λ�����ַ���Ȼ�����ɾ��ָ���ַ�����ַ�����
	���룺hellokityManGood
	3  6   9
	helokityManGood

	heloktyManGood

	heloktyMnGood

	�����heloktyMnGood
	Ҫ��1����дҵ��ӿڲ�ʵ�ֺ��Ĺ��� 70��
	Ҫ��2��д���������� 30��*/

	char buf[1024] = { 0 };
	char *str, *str2;
	int num = 0, ret = 0;

	printf("������һ��������40���ַ����ַ��� ");
	gets_s(buf, 1023);

	printf("������Ҫɾ�����ַ���λ��(-1: quit) ");
	scanf("%d", &num);

	str = buf;

	while (-1 != num)
	{
		ret = del(str, num, &str2);
		if (ret != 0)
		{
			printf("func del errCode: %d", ret);
			return;
		}

		print(str2);

		printf("������Ҫɾ�����ַ���λ��(-1: quit) ");
		scanf("%d", &num);




		str = str2;
		str2 = NULL;
	}

	system("pause");
}