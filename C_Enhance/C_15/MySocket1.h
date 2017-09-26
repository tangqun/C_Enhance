#pragma once
#include "SocketProtocol.h"
class MySocket1 : public SocketProtocol
{
public:
	MySocket1();
	~MySocket1();

	virtual int cltSocketInit();
	virtual int cltSocketSend(unsigned char *buf, int buflen);
	virtual int cltSocketRev(unsigned char *buf, int *buflen);
	virtual int cltSocketDestory();

private:
	char *pbuf;
	int len;
};

