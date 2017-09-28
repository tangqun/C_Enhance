
// C_Dynamic_Library_Function_Call.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CC_Dynamic_Library_Function_CallApp: 
// 有关此类的实现，请参阅 C_Dynamic_Library_Function_Call.cpp
//

class CC_Dynamic_Library_Function_CallApp : public CWinApp
{
public:
	CC_Dynamic_Library_Function_CallApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CC_Dynamic_Library_Function_CallApp theApp;