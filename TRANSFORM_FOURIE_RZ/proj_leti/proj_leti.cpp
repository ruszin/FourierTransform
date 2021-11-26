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


// создание Cproj_letiApp


Cproj_letiApp::Cproj_letiApp()
{
	// поддержка диспетчера перезагрузки
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект Cproj_letiApp

Cproj_letiApp theApp;


// инициализация Cproj_letiApp

BOOL Cproj_letiApp::InitInstance()
{
	// InitCommonControlsEx() требуется для Windows XP, если манифест
	// приложения использует ComCtl32.dll версии 6 или более поздней версии для включения
	// стилей отображения.  В противном случае будет возникать сбой при создании любого окна.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Выберите этот параметр для включения всех общих классов управления, которые необходимо использовать
	// в вашем приложении.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Создать диспетчер оболочки, в случае, если диалоговое окно содержит
	// представление дерева оболочки или какие-либо его элементы управления.
	CShellManager *pShellManager = new CShellManager;

	// Активация визуального диспетчера "Классический Windows" для включения элементов управления MFC
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	
	SetRegistryKey(_T("RZ"));
	Cproj_letiDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		//Введите код для обработки закрытия диалогового окна
		//с помощью кнопки "ОК"
	}
	else if (nResponse == IDCANCEL)
	{
		//  с помощью кнопки "Отмена"
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Предупреждение. Не удалось создать диалоговое окно, поэтому работа приложения неожиданно завершена.\n");
		TRACE(traceAppMsg, 0, "Предупреждение. При использовании элементов управления MFC для диалогового окна невозможно #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Удалить диспетчер оболочки, созданный выше.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// Поскольку диалоговое окно закрыто, возвратите значение FALSE, чтобы можно было выйти из
	//  приложения вместо запуска генератора сообщений приложения.
	return FALSE;
}

