// proj_letiDlg.cpp : файл реализации
#include "stdafx.h"
#include "proj_leti.h"
#include "proj_letiDlg.h"
#include "afxdialogex.h"
#include "Cproj_letiCalc.h"
#include "PaintPic.h"
#include <cstdlib>
#include <initguid.h>
#include<vector>
#include "math.h"
#define _USE_MATH_DEFINES
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//define
#define MY_TIMER1 1111
#define MY_TIMER2 2222
#define PI 3.14
//конфигурация дял сохранения Image
DEFINE_GUID(ImageFormatBMP, 0xb96b3cab, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatEMF, 0xb96b3cac, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatWMF, 0xb96b3cad, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatJPEG, 0xb96b3cae, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatPNG, 0xb96b3caf, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatGIF, 0xb96b3cb0, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatTIFF, 0xb96b3cb1, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
// Диалоговое окно CAboutDlg используется для описания сведений о приложении
CString strB;
double arg; // ввод аргумента в IDC EDIT 1 - m_Calc переменная привязанная к m_Calc
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnIdrMenuDop();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_COMMAND(IDR_MENU_DOP, &CAboutDlg::OnIdrMenuDop)
	ON_WM_RBUTTONUP()
	
END_MESSAGE_MAP()


// диалоговое окно Cproj_letiDlg



Cproj_letiDlg::Cproj_letiDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PROJ_LETI_DIALOG, pParent)
	, m_paintPic()
	, m_strF(_T(""))
	, m_HelpVal(_T(""))
	//, m_paintPicDPF()
	, m_MinMaxValCheck(0)
	,m_paintDPF()
{
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cproj_letiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_EDIT1, m_cEdit1);
	DDX_Control(pDX, IDC_EDIT1, m_Calc);
	DDX_Text(pDX, IDC_ANIMATE1, m_strF);
	DDX_Control(pDX, IDC_ST_SH, m_st_SH);
	DDX_Text(pDX, IDC_HELP, m_HelpVal);
	//DDX_Control(pDX, IDC_ANIMATE2, m_paintPicDPF);
	DDX_Control(pDX, IDC_ANIMATE2, m_paintDPF);
	DDX_Text(pDX, IDC_EDIT1, m_MinMaxValCheck);
	DDV_MinMaxFloat(pDX, m_MinMaxValCheck, 30, 70);
	DDX_Control(pDX, IDC_SPIN1, m_SpinPicSignal);
}

BEGIN_MESSAGE_MAP(Cproj_letiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_EDIT1, &Cproj_letiDlg::OnEnChangeEdit1)
	ON_ACN_START(IDC_ANIMATE1, &Cproj_letiDlg::OnAcnStartAnimate1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK3, &Cproj_letiDlg::OnBnClickedCheck3)
	ON_ACN_START(IDC_ANIMATE2, &Cproj_letiDlg::OnAcnStartAnimate2)
	ON_WM_TIMER()
	
	ON_BN_CLICKED(IDC_SAVE_PIC, &Cproj_letiDlg::OnBnClickedSavePic)
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_STN_CLICKED(IDC_ST_SH, &Cproj_letiDlg::OnStnClickedStSh)
	ON_STN_CLICKED(IDC_HELP, &Cproj_letiDlg::OnStnClickedStHelp)
	ON_BN_CLICKED(IDOK, &Cproj_letiDlg::OnBnClickedOk)
	ON_COMMAND(ID_32773, &Cproj_letiDlg::On32773)
	ON_COMMAND(ID_32772, &Cproj_letiDlg::On32772)
	ON_ACN_START(IDC_ANIMATE2, &Cproj_letiDlg::OnAcnStartAnimate2)
	ON_STN_CLICKED(IDC_ST_SH_DPF, &Cproj_letiDlg::OnStnClickedStatic5)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &Cproj_letiDlg::OnDeltaposSpin1)
	ON_BN_CLICKED(IDC_SAVE_PICDPF, &Cproj_letiDlg::OnBnClickedSavePicdpf)
	/*ON_WM_MOUSEHWHEEL()*/
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()


// обработчики сообщений Cproj_letiDlg

BOOL Cproj_letiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок
	
	// TODO: добавьте дополнительную инициализацию
	SetWindowText(L"RZ"); 
	m_paintPic.SubclassDlgItem(IDC_ANIMATE1, this);
	//CWnd *pWn = GetDlgItem(IDC_ANIMATE2);
	//m_paintDPF.SubclassDlgItem(IDC_ANIMATE2,this);
	//read config from registry 
	m_c.m_Param.Scale = AfxGetApp()->GetProfileInt(_T("Settings"),_T("Arg"),45);
	CString strA;
	strA.Format(_T("%.0f"), m_c.m_Param.Scale);
	CWnd* pE = GetDlgItem(IDC_EDIT1);
	if (pE) {
		pE->SetWindowText(strA);
	}
	m_SpinPicSignal.SetBuddy(&m_Calc);	////////////////////////////
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void Cproj_letiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void Cproj_letiDlg::OnPaint()
{
	CRect rc;
	m_paintDPF.GetClientRect(&rc);
	m_DPF.m_Param.Height = rc.Height();
	m_DPF.m_Param.Width = rc.Width();
	if (IsIconic())
	{
		CWnd *pWn = GetDlgItem(IDC_ANIMATE1);
		CPaintDC dc(pWn); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

void Cproj_letiDlg::OnPaint2()
{
	if (IsIconic())
	{
		CWnd *pWn1 = GetDlgItem(IDC_ANIMATE2);
		CPaintDC dc(pWn1); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	
	}
}
// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR Cproj_letiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cproj_letiDlg::OnAcnStartAnimate1()
{
	
}

CString sA;
int ArgChangeCopy;
void Cproj_letiDlg::OnEnChangeEdit1(){
	CWnd* pE = GetDlgItem(IDC_EDIT1);
	if (pE)
	{
		pE->GetWindowText(sA);
		MyParams_t par = m_Pt.m_Param;
		par.Scale = _wtof(sA);
		m_Pt.SetParams(par);
		m_paintPic.Invalidate();
		m_paintDPF.Invalidate();
	}
}

void Cproj_letiDlg::OnTimer(UINT_PTR nIDEvent)
{
	
	if (nIDEvent == MY_TIMER1) {
		OnEnChangeEdit1();
		m_paintPic.m_Npt++;
		m_paintPic.Invalidate();
	}
	if (nIDEvent == MY_TIMER2) {
		OnEnChangeEdit1();
		m_paintDPF.m_Npt++;
		m_paintDPF.Invalidate();
	}
	CDialogEx::OnTimer(nIDEvent);
}
void Cproj_letiDlg::OnBnClickedCheck3()//таймер для IDC_CHECK3
{

	CButton *pW = (CButton *)GetDlgItem(IDC_CHECK3);
	if (pW) {
		if (pW->GetCheck()) {
			m_Calc.EnableWindow(FALSE);
			SetTimer(MY_TIMER1, 0, NULL);
			SetTimer(MY_TIMER2, 0, NULL);
			
		}
		else {
			m_Calc.EnableWindow(TRUE);
			KillTimer(MY_TIMER1);
			KillTimer(MY_TIMER2);

		}
	}
}

void CAboutDlg::OnIdrMenuDop()//функция обработчика нового меню::OnIdrMenuDop()
{
	CMenu mn_up;
	mn_up.LoadMenuW(IDR_MENU_DOP);
}


void Cproj_letiDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	CMenu mn;
	mn.LoadMenuW(IDR_MENU_DOP); // загружаем из ресурсов меню
	CPoint pt = point; //берем точку нажатия
	ClientToScreen(&pt); // переводим в координаты экрана из коорд. диалога
	if (mn.GetSubMenu(0)) {// берем меню первое
		mn.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_TOPALIGN | TPM_LEFTBUTTON, pt.x, pt.y, this);// вызываем на экран меню и ждем реакцию пользователя
	}
	CDialogEx::OnRButtonUp(nFlags, point);
}


void Cproj_letiDlg::OnMouseMove(UINT nFlags, CPoint point)//функция обработчика WM_MOUSE_MOVE
{
	CPoint pt;
	GetCursorPos(&pt);
	m_paintPic.ScreenToClient(&pt);
	CRect rc;
	CStatic *pW = (CStatic *)GetDlgItem(IDC_ST_SH);//IDC_ST_SH-id статика в котором выводим значение "x"
	ASSERT(pW);
	m_paintPic.GetClientRect(&rc);
	if (rc.PtInRect(pt))
	{
		    
			m_strF.Format(_T("X = %d     Y=%d"), pt.x,pt.y ? -(pt.y-190):pt.y-190);//m_strF-переменная CString для формата координаты "x"
			pW->SetWindowText(m_strF);
	}
	else {
		pW->SetWindowText(_T("X=...     Y=..."));
	}
	//////////
	
	GetCursorPos(&pt);
	m_paintDPF.ScreenToClient(&pt);
	CStatic *pWDPF = (CStatic *)GetDlgItem(IDC_ST_SH_DPF);//IDC_ST_SH-id статика в котором выводим значение "x"
	ASSERT(pWDPF);
	m_paintDPF.GetClientRect(&rc);
	if (rc.PtInRect(pt))
	{

		m_strF.Format(_T("X = %d     Y=%d"), pt.x, pt.y ? -(pt.y - 190) : pt.y - 190);//m_strF-переменная CString для формата координаты "x"
		pWDPF->SetWindowText(m_strF);
	}
	else {
		pWDPF->SetWindowText(_T("X=...     Y=..."));
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void Cproj_letiDlg::OnStnClickedStSh()
{

}


void Cproj_letiDlg::OnStnClickedStHelp()
{
	
}


void Cproj_letiDlg::OnBnClickedOk()//Кнопка ОК 
{
	//save to registry
	AfxGetApp()->WriteProfileInt(_T("Settings"), _T("Arg"),m_c.m_Param.Scale);
	
	CDialogEx::OnOK();
}



void Cproj_letiDlg::On32773()//Пункт Выход в доп.меню
{
	ASSERT(AfxGetApp()->m_pMainWnd != NULL);
	AfxGetApp()->m_pMainWnd->PostMessage(WM_CLOSE, 0, 0);
}


void Cproj_letiDlg::On32772()//Пункт Помощь в доп.меню 
{
	CStatic *pW = (CStatic *)GetDlgItem(IDC_HELP);//Получаю указатель на Статик окно в котором выведу текст
	ASSERT(pW);
	pW->SetWindowTextW(L"1)Чтобы построить графики сигнальной функции и ДПФ введите аргумент значением от 30 до 70 и нажмите ПОСТРОИТЬ ГРАФИКИ на главной странице\n2)Чтобы узнать координату X на графике,просто наведите курсор на интересующую точку на графике");
}


void Cproj_letiDlg::OnAcnStartAnimate2()
{
	
}
void Cproj_letiDlg::OnStnClickedStatic5()
{
	
}


void Cproj_letiDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	if (pNMUpDown->iDelta > 0)
	{
		
	}
	if (pNMUpDown->iDelta < 0)
	{
		
	}
	*pResult = 0;
}


void Cproj_letiDlg::OnBnClickedSavePicdpf()
{
	CWnd *pWn = GetDlgItem(IDC_ANIMATE2);
	if (!pWn)
		return;
	CWindowDC winDC(pWn);
	CRect rc;
	pWn->GetClientRect(&rc);
	CDC memDC;
	memDC.CreateCompatibleDC(&winDC);
	CBitmap bitMap;
	bitMap.CreateCompatibleBitmap(&winDC, rc.Width(), rc.Height());
	HGDIOBJ pOld = memDC.SelectObject(&bitMap);
	memDC.FillSolidRect(&rc, RGB(100, 243, 255));
	memDC.BitBlt(0, 0, rc.Width(), rc.Height(), &winDC, 0, 0, SRCCOPY);
	memDC.SelectObject(pOld);
	static TCHAR szFilter[] = _T("BMP Files (*.bmp)|*.bmp|")
		_T("PNG Files (*.png)|*.png|GIF Files (*.gif)|*.gif|")
		_T("JPG Files (*.jpg)|*.jpg|All Files (*.*)|*.*||");
	CFileDialog dlg(FALSE, _T(".bmp"), NULL, 6UL, szFilter);
	if (IDOK == dlg.DoModal())
	{
		CImage image;
		image.Attach(HBITMAP(bitMap));
		CString strFull = dlg.GetOFN().lpstrFile;
		HRESULT hr;
		if (-1 != strFull.Find(_T(".png")))
			hr = image.Save(strFull, ImageFormatPNG);
		else if (-1 != strFull.Find(_T(".jpg")))
			hr = image.Save(strFull, ImageFormatJPEG);
		else if (-1 != strFull.Find(_T(".gif")))
			hr = image.Save(strFull, ImageFormatGIF);
		else if (-1 != strFull.Find(_T(".bmp")))
			hr = image.Save(strFull, ImageFormatBMP);
		else
		{
			strFull += _T(".bmp");
			hr = image.Save(strFull, ImageFormatBMP);
		}

		if (FAILED(hr))
		{
			CString strErr;
			strErr.Format(L" Couldn't Save File: %s, %x ", (LPCTSTR)strFull, hr);
			AfxMessageBox(strErr, MB_OK | MB_ICONERROR);
		}
	}
}
void Cproj_letiDlg::OnBnClickedSavePic()
{

	CWnd *pWn = GetDlgItem(IDC_ANIMATE1);
	if (!pWn)
		return;
	CWindowDC winDC(pWn);
	CRect rc;
	pWn->GetClientRect(&rc);
	CDC memDC;
	memDC.CreateCompatibleDC(&winDC);
	CBitmap bitMap;
	bitMap.CreateCompatibleBitmap(&winDC, rc.Width(), rc.Height());
	HGDIOBJ pOld = memDC.SelectObject(&bitMap);
	memDC.FillSolidRect(&rc, RGB(100, 243, 255));
	memDC.BitBlt(0, 0, rc.Width(), rc.Height(), &winDC, 0, 0, SRCCOPY);
	memDC.SelectObject(pOld);
	static TCHAR szFilter[] = _T("BMP Files (*.bmp)|*.bmp|")
		_T("PNG Files (*.png)|*.png|GIF Files (*.gif)|*.gif|")
		_T("JPG Files (*.jpg)|*.jpg|All Files (*.*)|*.*||");
	CFileDialog dlg(FALSE, _T(".bmp"), NULL, 6UL, szFilter);
	if (IDOK == dlg.DoModal())
	{
		CImage image;
		image.Attach(HBITMAP(bitMap));
		CString strFull = dlg.GetOFN().lpstrFile;
		HRESULT hr;
		if (-1 != strFull.Find(_T(".png")))
			hr = image.Save(strFull, ImageFormatPNG);
		else if (-1 != strFull.Find(_T(".jpg")))
			hr = image.Save(strFull, ImageFormatJPEG);
		else if (-1 != strFull.Find(_T(".gif")))
			hr = image.Save(strFull, ImageFormatGIF);
		else if (-1 != strFull.Find(_T(".bmp")))
			hr = image.Save(strFull, ImageFormatBMP);
		else
		{
			strFull += _T(".bmp");
			hr = image.Save(strFull, ImageFormatBMP);
		}

		if (FAILED(hr))
		{
			CString strErr;
			strErr.Format(L" Couldn't Save File: %s, %x ", (LPCTSTR)strFull, hr);
			AfxMessageBox(strErr, MB_OK | MB_ICONERROR);
		}
	}
}

BOOL Cproj_letiDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	GetCursorPos(&pt);
	CRect rc;
	m_paintPic.ScreenToClient(&pt);
	m_paintPic.GetClientRect(&rc);
	if (rc.PtInRect(pt)) {
		MyParams_t par = m_Pt.m_Param;
		par.Scale = par.Scale + zDelta / 50.;
		m_Pt.SetParams(par);
		m_paintPic.Invalidate();
	}
	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}
