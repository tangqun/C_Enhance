#include<iostream>

using namespace std;

#pragma once
class String
{
public:
	String();
	String(const char *str);
	String(const String &obj);
	~String();

	char* getString();
	//void setString(String str);
	int length();

	String& operator=(String &str);
	String& operator=(const char *str);
	String operator+(String &str);

	bool operator==(String &str);
	bool operator!=(String &str);

	friend ostream& operator<<(ostream &out, String &str);

private:
	char *p;
	int len;
};

