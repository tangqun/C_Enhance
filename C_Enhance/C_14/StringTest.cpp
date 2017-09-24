#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "String.h"

using namespace std;

void main()
{
	String str = "abcd";

	//cout << str.getString() << endl;

	String str2 = str;
	cout << str2 << endl;

	//String *str3 = new String("abcde");
	//delete str3;

	String str4("efgh");

	String str10 = str + str4;

	system("pause");
}