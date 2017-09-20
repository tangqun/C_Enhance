#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int readFile(const char *pfilename /*in*/, char ***p /*out*/, int *lineNum /*int out*/);
void freeFile(char **p, int lineNum);

// p 是一个二维数组的首地址
int readFile(const char *pfilename /*in*/, char ***p /*out*/, int *lineNum /*int out*/)
{
	int ret = 0;
	FILE *fp = NULL;
	char tmpLineBuf[1024 * 4];

	char **pTmp = NULL;

	// 用来存储读取一行之后的的首地址 pTmp2 = fgets(tmpLineBuf, 1024 * 4, fp);
	char *pTmp2 = NULL;

	int tmpLineNum = 0, tmpLineLen = 0, i = 0;

	if (NULL == pfilename || NULL == p || NULL == lineNum)
	{
		ret = -1;
		printf("func readFile2 errCode: %d", ret);
		goto End;
	}

	fp = fopen(pfilename, "r");
	if (NULL == fp)
	{
		ret = -2;
		printf("fopen err, errCode: %d", ret);
		goto End;
	}

	while (!feof(fp))
	{
		memset(tmpLineBuf, 0, sizeof(tmpLineBuf));
		pTmp2 = fgets(tmpLineBuf, 1024 * 4, fp);
		if (NULL == pTmp2)
		{
			break;
		}
		else
		{
			tmpLineNum++;
		}
	}

	// 二级数组，一维是每一行的地址， 二维是 行数据
	pTmp = (char **)malloc(tmpLineNum * sizeof(char *));
	if (NULL == pTmp)
	{
		ret = -3;
		printf("malloc err, errCode: %d", ret);
		goto End;
	}

	// 让文件指针指向文件的开头，目的：第二次从头检索
	fseek(fp, 0L, SEEK_SET);

	while (!feof(fp))
	{
		//读每一行
		memset(tmpLineBuf, 0, sizeof(tmpLineBuf));
		pTmp2 = fgets(tmpLineBuf, 1024 * 4, fp);
		if (NULL == pTmp2)
		{
			break;
		}

		tmpLineLen = strlen(tmpLineBuf);
		pTmp[i] = (char *)malloc((tmpLineLen + 1) * sizeof(char));

		if (NULL == pTmp[i])
		{
			ret = -4;
			printf("malloc err, errCode: %d", ret);
			goto End;
		}

		strcpy(pTmp[i], tmpLineBuf);
		i++;
	}

End:
	if (NULL != fp)
	{
		fclose(fp);
	}
	*lineNum = tmpLineNum;
	*p = pTmp;
	return ret;
}

void freeFile(char **p, int lineNum)
{
	int i = 0;
	if (NULL == p)
	{
		return;
	}
	for (i = 0; i < lineNum; i++)
	{
		if (NULL == p[i])
		{
			free(p[i]);
		}
	}
	free(p);
	return;
}

void main02()
{
	/*
	2 编写一个业务函数，实现按行读取文件。把内容按照第三种内存模型打包数据传出，把行数通过函数参数传出。
	函数原型有两个，任意选择其一
	要求1：请自己任意选择一个接口（函数），并实现功能；70分
	要求2：编写测试用例。30分
	要求3：自己编写内存释放函数
	*/
	int ret = 0, lineNum = 0;
	char **p = NULL;


	ret = readFile("c:/kms10.log", &p, &lineNum);
	if (ret != 0)
	{
		printf("func readFile2 errCode: %d", ret);
		return;
	}

	for (int i = 0; i < lineNum; i++)
	{
		printf("%s", p[i]);
	}

	freeFile(p, lineNum);

	system("pause");
}