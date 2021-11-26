#include "stdafx.h"
#include "proj_leti.h"
#include "proj_letiDlg.h"
#define _USE_MATH_DEFINES
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cproj_letiApp

BEGIN_MESSAGE_MAP(Cproj_letiApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// �������� Cproj_letiApp


Cproj_letiApp::Cproj_letiApp()
{
	// ��������� ���������� ������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
	// ��������� ���� ������ ��� ������������� � InitInstance
}


// ������������ ������ Cproj_letiApp

Cproj_letiApp theApp;


// ������������� Cproj_letiApp

BOOL Cproj_letiApp::InitInstance()
{
	// InitCommonControlsEx() ��������� ��� Windows XP, ���� ��������
	// ���������� ���������� ComCtl32.dll ������ 6 ��� ����� ������� ������ ��� ���������
	// ������ �����������.  � ��������� ������ ����� ��������� ���� ��� �������� ������ ����.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �������� ���� �������� ��� ��������� ���� ����� ������� ����������, ������� ���������� ������������
	// � ����� ����������.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ������� ��������� ��������, � ������, ���� ���������� ���� ��������
	// ������������� ������ �������� ��� �����-���� ��� �������� ����������.
	CShellManager *pShellManager = new CShellManager;

	// ��������� ����������� ���������� "������������ Windows" ��� ��������� ��������� ���������� MFC
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	
	SetRegistryKey(_T("RZ"));
	Cproj_letiDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		//������� ��� ��� ��������� �������� ����������� ����
		//� ������� ������ "��"
	}
	else if (nResponse == IDCANCEL)
	{
		//  � ������� ������ "������"
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "��������������. �� ������� ������� ���������� ����, ������� ������ ���������� ���������� ���������.\n");
		TRACE(traceAppMsg, 0, "��������������. ��� ������������� ��������� ���������� MFC ��� ����������� ���� ���������� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// ������� ��������� ��������, ��������� ����.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// ��������� ���������� ���� �������, ���������� �������� FALSE, ����� ����� ���� ����� ��
	//  ���������� ������ ������� ���������� ��������� ����������.
	return FALSE;
}

