#define _CRT_SECURE_NO_WARNINGS
#include "String.h"



String::String()
{
}

String::String(const char *str)
{
	if (NULL == str)
	{
		this->p = NULL;
		this->len = 0;
	}
	else
	{
		this->len = strlen(str);
		this->p = (char *)malloc(this->len * sizeof(char));
		strcpy(this->p, str);
	}
}

String::String(const String &obj)
{
	this->len = obj.len;
	this->p = (char *)malloc(this->len * sizeof(char));
	strcpy(this->p, obj.p);
}

String::~String()
{
	/*if (NULL != this->p)
	{
		free(this->p);
		this->p = NULL;
		this->len = 0;
	}*/
}

char* String::getString()
{
	return this->p;
}

int String::length()
{
	return this->len;
}

String& String::operator=(String &str)
{
	if (NULL != this->p)
	{
		free(this->p);
		this->p = NULL;
		this->len = 0;
	}
	this->len = str.len;
	this->p = (char *)malloc(this->len * sizeof(char));
	strcpy(this->p, str.p);
	return *this;
}

String& String::operator=(const char *str)
{
	if (NULL != this->p)
	{
		free(this->p);
		this->p = NULL;
		this->len = 0;
	}
	this->len = strlen(str);
	this->p = (char *)malloc(this->len * sizeof(char));
	strcpy(this->p, str);
	return *this;
}

String String::operator+(String &str)
{
	String srv;
	srv.len = this->len + str.len;
	srv.p = (char *)malloc((this->len + 1) * sizeof(char));
	strcpy(srv.p, this->p);
	strncpy((srv.p + this->len), str.p, str.len);
	srv.p[srv.len] = '\0';
	return srv;
}

bool String::operator==(String &str)
{
	if (this->len != str.len)
	{
		return false;
	}

	for (int i = 0; i < this->len; i++)
	{
		if (this->p[i] != str.p[i])
		{
			return false;
		}
	}

	return true;
}

bool String::operator!=(String &str)
{
	return !(*this == str);
}

ostream& operator<<(ostream &out, String &str)
{
	out << str.getString();
	return out;
}