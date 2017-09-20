#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int readFile(const char *pfilename /*in*/, char ***p /*out*/, int *lineNum /*int out*/);
void freeFile(char **p, int lineNum);

// p ��һ����ά������׵�ַ
int readFile(const char *pfilename /*in*/, char ***p /*out*/, int *lineNum /*int out*/)
{
	int ret = 0;
	FILE *fp = NULL;
	char tmpLineBuf[1024 * 4];

	char **pTmp = NULL;

	// �����洢��ȡһ��֮��ĵ��׵�ַ pTmp2 = fgets(tmpLineBuf, 1024 * 4, fp);
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

	// �������飬һά��ÿһ�еĵ�ַ�� ��ά�� ������
	pTmp = (char **)malloc(tmpLineNum * sizeof(char *));
	if (NULL == pTmp)
	{
		ret = -3;
		printf("malloc err, errCode: %d", ret);
		goto End;
	}

	// ���ļ�ָ��ָ���ļ��Ŀ�ͷ��Ŀ�ģ��ڶ��δ�ͷ����
	fseek(fp, 0L, SEEK_SET);

	while (!feof(fp))
	{
		//��ÿһ��
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
	2 ��дһ��ҵ������ʵ�ְ��ж�ȡ�ļ��������ݰ��յ������ڴ�ģ�ʹ�����ݴ�����������ͨ����������������
	����ԭ��������������ѡ����һ
	Ҫ��1�����Լ�����ѡ��һ���ӿڣ�����������ʵ�ֹ��ܣ�70��
	Ҫ��2����д����������30��
	Ҫ��3���Լ���д�ڴ��ͷź���
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