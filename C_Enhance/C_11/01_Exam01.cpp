#include<iostream>

using namespace std;

int GetString(const char *str1 /*in*/, char *str2 /*in*/);
int GetString_Adv(const char *str1 /*in*/, char **str2 /*out*/);
int GetString_Adv_Free1(char *str2);
int GetString_Adv_Free2(char **str2);

int GetString(const char *str1 /*in*/, char *str2 /*in*/)
{
	int ret = 0, i = 0;
	if (NULL == str1)
	{
		ret = -1;
		printf("func GetString errCode: %d", ret);
		return ret;
	}
	if (NULL == str2)
	{
		ret = -2;
		printf("func GetString errCode: %d", ret);
		return ret;
	}

	while (str1[i])
	{
		if (i >= 1 && str1[i - 1] == ' ' && str1[i] != ' ')
		{
			str2[i] = str1[i] - 32;
		}
		else
		{
			str2[i] = str1[i];
		}
		
		i++;
	}

	return 0;
}

int GetString_Adv(const char *str1 /*in*/, char **str2 /*out*/)
{
	int ret = 0, i = 0, str1Len = 0;
	char *p = NULL;

	if (NULL == str1)
	{
		ret = -1;
		printf("func GetString_Adv errCode: %d", ret);
		return ret;
	}
	if (NULL == str2)
	{
		ret = -2;
		printf("func GetString_Adv errCode: %d", ret);
		return ret;
	}

	str1Len = strlen(str1);
	if (str1Len > 0)
	{
		p = (char *)malloc((str1Len + 1) * sizeof(char));
	}

	if (NULL == p)
	{
		ret = -3;
		printf("func GetString_Adv errCode: %d", ret);
		return ret;
	}

	while (str1[i])
	{
		if (i >= 1 && str1[i - 1] == ' ' && str1[i] != ' ')
		{
			p[i] = str1[i] - 32;
		}
		else
		{
			p[i] = str1[i];
		}

		i++;
	}
	p[i] = '\0';

	*str2 = p;

	return 0;
}

int GetString_Adv_Free1(char *str2)
{
	return 0;
}

int GetString_Adv_Free2(char **str2)
{
	int ret = 0;
	if (NULL == str2)
	{
		ret = -1;
		printf("func GetString_Adv_Free2 errCode: %d", ret);
		return ret;
	}

	free(*str2);
	*str2 = NULL;

	return 0;
}

void main01()
{
	/*
	1 编写一个业务函数，实现字符串（前后各有三个空格，单词前后也均有空格）
	"   i am student, you are teacher   " ，
	各个单词首字符大写，结果如下"   i am student,  you are teacher   " ，
	要求1：实现所有接口  70
	要求2：写出测试程序  30
	*/

	/*int ret = 0, i = 0;
	char str1[100] = "   i am student, you are teacher   ";
	char str2[100] = { 0 };

	ret = GetString(str1, str2);
	if (ret != 0)
	{
		printf("func GetString errCode: %d", ret);
		return;
	}

	while (str2[i])
	{
		printf("%c", str2[i]);
		i++;
	}

	ret = GetString_Adv_Free1(str2);
	if (ret != 0)
	{
		printf("func GetString_Adv_Free1 errCode: %d", ret);
		return;
	}*/

	int ret = 0, i = 0;
	char str1[100] = "   i am student, you are teacher   ";
	char *str2 = NULL;

	ret = GetString_Adv(str1, &str2);
	if (ret != 0)
	{
		printf("func GetString_Adv errCode: %d", ret);
		return;
	}

	while (str2[i])
	{
		printf("%c", str2[i]);
		i++;
	}

	ret = GetString_Adv_Free2(&str2);
	if (ret != 0)
	{
		printf("func GetString_Adv errCode: %d", ret);
		return;
	}

	system("pause");
}