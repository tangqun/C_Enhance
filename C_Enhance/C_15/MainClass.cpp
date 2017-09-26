#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "MySocket1.h"

using namespace std;

int mainOP(SocketProtocol *sp, unsigned char *buf, int buflen, unsigned char *out, int *outlen)
{
	int ret = 0;
	ret = sp->cltSocketInit();
	ret = sp->cltSocketSend(buf, buflen);
	ret = sp->cltSocketRev(out, outlen);
	ret = sp->cltSocketDestory();
	return ret;
}

class CryptoClass
{
public:
	CryptoClass()
	{

	};
	~CryptoClass()
	{

	};

	void Encrypto(unsigned char *buf, int buflen)
	{
		for (int i = 0; i < buflen; i++)
		{
			buf[i] = buf[i] + 1;
		}
	}

	void Decrypto(unsigned char *out, int outlen)
	{
		for (int i = 0; i < outlen; i++)
		{
			out[i] = out[i] - 1;
		}
	}

private:

};

class MainOPClass
{
public:
	MainOPClass()
	{
		sp = NULL;
	};
	~MainOPClass()
	{

	};

	int mainOP(unsigned char *buf, int buflen, unsigned char *out, int *outlen)
	{
		int ret = 0;
		ret = sp->cltSocketInit();

		// ¼ÓÃÜ
		CryptoClass *cc = new CryptoClass();
		cc->Encrypto(buf, buflen);

		ret = sp->cltSocketSend(buf, buflen);

		ret = sp->cltSocketRev(out, outlen);
		
		// ½âÃÜ
		cc->Decrypto(out, *outlen);

		ret = sp->cltSocketDestory();

		delete cc;
		return ret;
	}

	// get/set
	SocketProtocol * getSp() const
	{
		return sp;
	}
	void setSp(SocketProtocol * val)
	{
		sp = val;
	}

private:
	SocketProtocol *sp;
};

void main()
{
	int ret = 0;

	char buf[1024] = { 0 };
	int buflen = 10;

	char out[1024] = { 0 };
	int outlen = 0;
	SocketProtocol *sp = NULL;
	strcpy(buf, "dddddsssdadsadafsafsa");

	sp = new MySocket1();
	//ret = mainOP(sp, (unsigned char *)buf, buflen, (unsigned char *)out, &outlen);
	MainOPClass *mainOPClass = new MainOPClass();
	mainOPClass->setSp(sp);

	mainOPClass->mainOP((unsigned char *)buf, buflen, (unsigned char *)out, &outlen);

	cout << out << endl;

	delete mainOPClass;
	delete sp;


	system("pause");
}