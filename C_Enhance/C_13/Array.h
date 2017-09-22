#pragma once

class Array
{
public:
	Array(int length);
	Array(const Array &obj);
	int length();
	void setData(int index, int value);
	int getData(int index);

	int& operator[](int i);
	Array& operator=(Array &a1);

	bool operator==(Array &a2);
	bool operator!=(Array &a2);

	~Array();

private:
	int mLength;
	int* mSpace;
};

