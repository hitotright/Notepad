
// Nodepad.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CNodepadApp: 
// �йش����ʵ�֣������ Nodepad.cpp
//

class CNodepadApp : public CWinApp
{
public:
	CNodepadApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CNodepadApp theApp;
