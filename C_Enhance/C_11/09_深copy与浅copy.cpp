#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

// 1��������û�ж����κ�һ�����캯��ʱ��c++���������ṩ�޲ι��캯�� �� �������캯��
// 2�������ж���������ķǿ������캯�����޲Ρ��вΣ���c++�����������ṩ�޲ι��캯��
// 3�������ж����˿������캯��ʱ��c++�����������ṩ�޲ι��캯��
// 4��Ĭ�Ͽ������캯����Ա�����򵥸�ֵ ��

class Name
{
public:
	// �вι��캯��
	Name(const char *pname)
	{
		cout << "��ʼ����" << endl;
		size = strlen(pname);
		pName = (char *)malloc(size + 1);
		strcpy(pName, pname);
	};
	// �������캯��
	Name(Name &obj)
	{
		cout << "�����ж�����" << endl;
		size = obj.size;
		pName = (char *)malloc(size + 1);
		strcpy(pName, obj.pName);
	}
	// ��������
	~Name()
	{
		cout << "��ʼ����" << endl;
		if (NULL != pName)
		{
			free(pName);
			pName = NULL;
			size = 0;
		}
	};
 	void operator=(Name &obj)
	{
		cout << "=�Ų���������" << endl;

		// �ȺŲ�������ߵ������ֵ
		if (NULL != pName)
		{
			free(pName);
			pName = NULL;
			size = 0;
		}

		size = obj.size;
		pName = (char *)malloc(size + 1);
		strcpy(pName, obj.pName);
	}
private:
	char *pName;
	int size;
};

void playObj()
{
	Name obj1("obj1......");
	Name obj2 = obj1;

	Name obj3("obj3......");
	obj2 = obj3;
	cout << "ҵ�����" << endl;
}

void main09()
{
	playObj();

	system("pause");
}