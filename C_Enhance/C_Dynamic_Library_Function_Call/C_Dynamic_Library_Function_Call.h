
// C_Dynamic_Library_Function_Call.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CC_Dynamic_Library_Function_CallApp: 
// �йش����ʵ�֣������ C_Dynamic_Library_Function_Call.cpp
//

class CC_Dynamic_Library_Function_CallApp : public CWinApp
{
public:
	CC_Dynamic_Library_Function_CallApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CC_Dynamic_Library_Function_CallApp theApp;