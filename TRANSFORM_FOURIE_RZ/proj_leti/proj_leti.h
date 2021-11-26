
// proj_leti.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// Cproj_letiApp:
// О реализации данного класса см. proj_leti.cpp
//


class Cproj_letiApp : public CWinApp
{
public:
	Cproj_letiApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};
