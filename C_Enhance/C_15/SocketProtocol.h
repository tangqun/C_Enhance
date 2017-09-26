#pragma once
#include<iostream>

using namespace std;

class SocketProtocol
{
public:
	SocketProtocol()
	{

	};
	virtual ~SocketProtocol()
	{

	};

	virtual int cltSocketInit() = 0;
	virtual int cltSocketSend(unsigned char *buf, int buflen) = 0;
	virtual int cltSocketRev(unsigned char *buf, int *buflen) = 0;
	virtual int cltSocketDestory() = 0;
 
private:

};