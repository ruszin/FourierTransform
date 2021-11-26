// PaintPic2.cpp: файл реализации
//

#include "stdafx.h"
#include "proj_leti.h"
#include "PaintPic2.h"
#include "stdafx.h"
#include "proj_letiDlg.h"
#include "Cproj_letiCalc.h"
#include <string>
#define _USE_MATH_DEFINES
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPaintPic2
IMPLEMENT_DYNAMIC(CPaintPic2, CWnd)
CPaintPic2::CPaintPic2()
{
	m_BackCol_1 = RGB(255, 255, 255);
	m_GraphCol_1 = RGB(0, 0, 255);
	m_Npt = 0;
}

CPaintPic2::~CPaintPic2()
{
}

BEGIN_MESSAGE_MAP(CPaintPic2, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

extern  vector<POINT> *GetPointsDPF;
void CPaintPic2::OnPaint()
{
	CPaintDC dc(this);
	CRect rc;
	GetClientRect(&rc);
	CRgn rgn;
	rgn.CreateRectRgn(rc.left, rc.top, rc.right, rc.bottom);
	dc.SelectClipRgn(&rgn);

	dc.FillSolidRect(rc, m_BackCol_1);
	CPoint pt;
	CPen pAxes(PS_SOLID, 2, RGB(0, 0, 0));
	HGDIOBJ old_Axes = dc.SelectObject(pAxes);

	Cproj_letiDlg *pDlg= (Cproj_letiDlg *)AfxGetMainWnd();
	if (!pDlg) {
		return;
	}
	//Рисование осей//
	dc.MoveTo(-1, 182);
	dc.LineTo(rc.right, 182);
	dc.SelectObject(old_Axes);
	/////////////////Переопредление карандаша под график
	CPen pV(PS_SOLID, 1.5, m_GraphCol_1);
	HGDIOBJ old = dc.SelectObject(pV);
	/////////////////
	std::vector<POINT> *vec = pDlg->m_DPF.GetPoints_DPF();
	if (vec->size())
	{
		std::vector<POINT>::iterator it = vec->begin();
		dc.MoveTo(*it);
		size_t nCur = 0;
		for (it++; it != vec->end(); it++)
		{
			dc.LineTo(*it);
			if (nCur++ >= m_Npt)
				break;
		}
		if (m_Npt >= vec->size())
			AfxGetMainWnd()->SendMessage(WM_USER + 1, m_Npt, vec->size());
	}


	dc.SelectObject(old);
}







