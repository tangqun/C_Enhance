#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

// 1、当类中没有定义任何一个构造函数时，c++编译器会提供无参构造函数 和 拷贝构造函数
// 2、当类中定义了任意的非拷贝构造函数（无参、有参），c++编译器不会提供无参构造函数
// 3、当类中定义了拷贝构造函数时，c++编译器不会提供无参构造函数
// 4、默认拷贝构造函数成员变量简单赋值 ★

class Name
{
public:
	// 有参构造函数
	Name(const char *pname)
	{
		cout << "开始构造" << endl;
		size = strlen(pname);
		pName = (char *)malloc(size + 1);
		strcpy(pName, pname);
	};
	// 拷贝构造函数
	Name(Name &obj)
	{
		cout << "从已有对象构造" << endl;
		size = obj.size;
		pName = (char *)malloc(size + 1);
		strcpy(pName, obj.pName);
	}
	// 析构函数
	~Name()
	{
		cout << "开始析构" << endl;
		if (NULL != pName)
		{
			free(pName);
			pName = NULL;
			size = 0;
		}
	};
 	void operator=(Name &obj)
	{
		cout << "=号操作符重载" << endl;

		// 等号操作符左边的自身的值
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
	cout << "业务操作" << endl;
}

void main09()
{
	playObj();

	system("pause");
}