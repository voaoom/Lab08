
// Lab08.h : главный файл заголовка для приложения Lab08
//
#pragma once

#ifndef __AFXWIN_H__
#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CLab08App:
// О реализации данного класса см. Lab08.cpp
//

class CLab08App : public CWinApp
{
public:
	CLab08App();

	// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	// Реализация
	DECLARE_MESSAGE_MAP()
};

extern CLab08App theApp;
