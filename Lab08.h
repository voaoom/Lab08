
// Lab08.h : ������� ���� ��������� ��� ���������� Lab08
//
#pragma once

#ifndef __AFXWIN_H__
#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CLab08App:
// � ���������� ������� ������ ��. Lab08.cpp
//

class CLab08App : public CWinApp
{
public:
	CLab08App();

	// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	// ����������
	DECLARE_MESSAGE_MAP()
};

extern CLab08App theApp;
