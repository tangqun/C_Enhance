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
	/*4、从键盘中输入一个不超过40个字符的字符串，再输入3个位数（每次删除一个字符），删除对应 位数的字符，然后输出删除指定字符后的字符串。
	输入：hellokityManGood
	3  6   9
	helokityManGood

	heloktyManGood

	heloktyMnGood

	输出：heloktyMnGood
	要求1：编写业务接口并实现核心功能 70分
	要求2：写出测试用例 30分*/

	char buf[1024] = { 0 };
	char *str, *str2;
	int num = 0, ret = 0;

	printf("请输入一个不超过40个字符的字符串 ");
	gets_s(buf, 1023);

	printf("请输入要删除的字符的位置(-1: quit) ");
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

		printf("请输入要删除的字符的位置(-1: quit) ");
		scanf("%d", &num);




		str = str2;
		str2 = NULL;
	}

	system("pause");
}