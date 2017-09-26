#include "MySocket1.h"



MySocket1::MySocket1()
{
	pbuf = NULL;
	len = 0;
}


MySocket1::~MySocket1()
{
}

int MySocket1::cltSocketInit()
{
	pbuf = NULL;
	len = 0;
	return 0;
}
int MySocket1::cltSocketSend(unsigned char *buf, int buflen)
{
	if (NULL == buf || 0 == buflen)
	{
		return -1;
	}
	this->pbuf = (char *)malloc(buflen * sizeof(char));
	if (NULL == this->pbuf)
	{
		return -2;
	}
	memcpy(this->pbuf, buf, buflen);
	this->len = buflen;
	return 0;
}
int MySocket1::cltSocketRev(unsigned char *buf, int *buflen)
{
	if (NULL == buf || NULL == buflen)
	{
		return -1;
	}
	memcpy(buf, this->pbuf, this->len);
	*buflen = this->len;
	return 0;
}
int MySocket1::cltSocketDestory()
{
	if (NULL != this->pbuf)
	{
		free(this->pbuf);
		this->pbuf = NULL;
		this->len = 0;
	}
	return 0;
}
