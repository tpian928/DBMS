
// ���ݿ�ϵͳ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C���ݿ�ϵͳApp:
// �йش����ʵ�֣������ ���ݿ�ϵͳ.cpp
//

class C���ݿ�ϵͳApp : public CWinApp
{
public:
	C���ݿ�ϵͳApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C���ݿ�ϵͳApp theApp;