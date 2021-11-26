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
CPaintPic::CPaintPic()//����������� CPaintPic()
{
	//������������� m_BackCol_1,m_Npt,m_GraphCol_1
	m_BackCol_1 = RGB(255, 255, 255);
	m_GraphCol_1 = RGB(0, 0, 255);
	m_Npt = 0;
}

CPaintPic::~CPaintPic()//���������� CpaintPic()
{
}

// ����������� ��������� CPaintPic
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
	//��������� ����//
	dc.MoveTo(-1,182);
	dc.LineTo(rc.right, 182);
	dc.SelectObject(old_Axes);
	/////////////////�������������� ��������� ��� ������
	CPen pV(PS_SOLID, 1.5, m_GraphCol_1);
	HGDIOBJ old = dc.SelectObject(pV);
	/////////////////
	std::vector<POINT> *vec = pDlg->m_Pt.GetPoints_dPoint();//� vec ������ �� ��������� �������� Get_Points_d_Point ������������ �������� ����� x,y
	if (vec->size())//��������� �� ������ �� ������ �����
	{
		std::vector<POINT>::iterator it = vec->begin();//������� ��������-��������� �� ������ ���� ����� x,y �� vec
		dc.MoveTo(*it);//������������� ����� �� ���������� �� ������ �����
		size_t nCur = 0;//������������� ���������� ��� �������� ���-�� �����
		for (it++; it != vec->end(); it++)//������ ���������� ����� vec ��������� �������� it(��������� �� ���������)
		{
			dc.LineTo(*it);//������ ������� �� ���������� ����� �� ����� �� vec ��������� �������� 
			if (nCur++ >= m_Npt) {//��������� ����� �� �������(�������� ���������� �����)
				break;//���� ������� ������� �� ������� �� �����
			}
		}
	}
	pDlg->m_DPF.Calculate();
	pDlg->m_paintDPF.Invalidate();
	dc.SelectObject(old);
}


