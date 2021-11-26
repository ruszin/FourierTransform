#include "stdafx.h"
#include "proj_letiDlg.h"
#include "proj_leti.h"
#include "PaintPic.h"
#include "Cproj_letiCalc.h"
#include <string>
#define _USE_MATH_DEFINES
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
IMPLEMENT_DYNAMIC(CPaintPic, CWnd)
CPaintPic::CPaintPic()//конструктор CPaintPic()
{
	//Инициализация m_BackCol_1,m_Npt,m_GraphCol_1
	m_BackCol_1 = RGB(255, 255, 255);
	m_GraphCol_1 = RGB(0, 0, 255);
	m_Npt = 0;
}

CPaintPic::~CPaintPic()//Деструктор CpaintPic()
{
}

// обработчики сообщений CPaintPic
BEGIN_MESSAGE_MAP(CPaintPic, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_MOUSEHWHEEL()
END_MESSAGE_MAP()


void CPaintPic::OnPaint()
{
	CPaintDC dc(this); 
	CRect rc;
	GetClientRect(&rc);
	CRgn rgn;
	rgn.CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom);
	dc.SelectClipRgn(&rgn);

	dc.FillSolidRect(rc, m_BackCol_1);
	CPoint pt;
	CPen pAxes(PS_SOLID, 2, RGB(0,0,0));
	HGDIOBJ old_Axes = dc.SelectObject(pAxes);

	Cproj_letiDlg *pDlg = (Cproj_letiDlg *)AfxGetMainWnd();
	if (!pDlg) {
		return;
	}
	//Рисование осей//
	dc.MoveTo(-1,182);
	dc.LineTo(rc.right, 182);
	dc.SelectObject(old_Axes);
	/////////////////Переопредление карандаша под график
	CPen pV(PS_SOLID, 1.5, m_GraphCol_1);
	HGDIOBJ old = dc.SelectObject(pV);
	/////////////////
	std::vector<POINT> *vec = pDlg->m_Pt.GetPoints_dPoint();//В vec кладем по указателю функцией Get_Points_d_Point рассчитанные значения точек x,y
	if (vec->size())//Проверяем не пустой ли вектор точек
	{
		std::vector<POINT>::iterator it = vec->begin();//создаем итератор-указатель на каждую пару точек x,y из vec
		dc.MoveTo(*it);//устанавливаем кисть на координаты на первую точку
		size_t nCur = 0;//иницилизируем переменную для проверки кол-ва точек
		for (it++; it != vec->end(); it++)//циклом перебираем точки vec используя итератор it(обращаясь по указателю)
		{
			dc.LineTo(*it);//Рисуем отрезок от предыдущей точки до точки из vec используя итератор 
			if (nCur++ >= m_Npt) {//проверяем выход из вектора(проверка количества точек)
				break;//если условие истинно то выходим из цикла
			}
		}
	}
	pDlg->m_DPF.Calculate();
	pDlg->m_paintDPF.Invalidate();
	dc.SelectObject(old);
}


