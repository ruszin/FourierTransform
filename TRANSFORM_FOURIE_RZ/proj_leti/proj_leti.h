
// proj_leti.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// Cproj_letiApp:
// � ���������� ������� ������ ��. proj_leti.cpp
//


class Cproj_letiApp : public CWinApp
{
public:
	Cproj_letiApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};
