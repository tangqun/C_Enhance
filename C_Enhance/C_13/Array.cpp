#include "Array.h"
#include<iostream>
using namespace std;

Array::Array(int length)
{
	if (length < 0)
	{
		length = 0;
	}

	mLength = length;
	// 对象创建的时候已经分配了内存空间
	mSpace = new int[mLength];
}

Array::Array(const Array &obj)
{
	mLength = obj.mLength;
	mSpace = new int[mLength];

	for (int i = 0; i < mLength; i++)
	{
		mSpace[i] = obj.mSpace[i];
	}
}

int Array::length()
{
	return mLength;
}

void Array::setData(int index, int value)
{
	mSpace[index] = value;
}

int Array::getData(int index)
{
	return mSpace[index];
}

int& Array::operator[](int i)
{
	return mSpace[i];
}

Array& Array::operator=(Array &a1)
{
	if (NULL != this->mSpace)
	{
		delete[] mSpace;
		this->mLength = 0;
	}

	this->mLength = a1.mLength;
	this->mSpace = new int[a1.mLength];
	
	for (int i = 0; i < this->mLength; i++)
	{
		mSpace[i] = a1[i];
	}

	return *this;
}

bool Array::operator==(Array &a2)
{
	if (this->mLength != a2.mLength)
	{
		return false;
	}

	for (int i = 0; i < this->mLength; i++)
	{
		if (this->mSpace[i] != a2[i])
		{
			return false;
		}
	}

	return true;
}

bool Array::operator!=(Array &a2)
{
	return !(*this == a2);
}

Array::~Array()
{
	mLength = -1;
	delete[] mSpace;
}
