#include "stdafx.h"
#include "Cproj_letiCalcDPF.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "proj_letiDlg.h"

Cproj_letiCalcDPF::Cproj_letiCalcDPF()
{
}


Cproj_letiCalcDPF::~Cproj_letiCalcDPF()
{

}

bool Cproj_letiCalcDPF::Calc(std::vector<POINT> *vec, size_t k, double yShift)
{

	double A = 0.;
	double B = 0.;
	size_t N = vec->size();
	X = 2.*k / double(N - 1);
	int Xn = 0;
	for (size_t n = 0; n < N; n++) {
		Xn = (vec->begin() + n)->y - yShift;
		A += Xn*cos(2 * M_PI*n*k / N);
		B += Xn*sin(2 * M_PI*n*k / N);
	}
	Y = sqrt(A*A + B*B) / N;
	return true;
}

bool Cproj_letiCalcDPF::Shift(CPoint &pt)
{
	pt.Offset(0, m_Param.Height);
	return true;
}


bool Cproj_letiCalcDPF::SetParams(MyParams_DPF &par)
{
	m_Param = par;
	Calculate();
	return true;
}

bool Cproj_letiCalcDPF::Scale(CPoint & pt, double ScaleX, double ScaleY, double yShift, std::vector<POINT> *vec, size_t k)
{

	Cproj_letiCalcDPF fn;

	if (fn.Calc(vec, k, yShift))
	{
		pt.x = (int)floor(ScaleX * fn.X);
		pt.y = -(int)floor(ScaleY * fn.Y);
		return true;
	}
	return false;
}

int Cproj_letiCalcDPF::GetNumPoints()
{
	return m_vecDPF.size();
}

std::vector<POINT> *Cproj_letiCalcDPF::GetPoints_DPF()
{
	return &m_vecDPF;
}

bool Cproj_letiCalcDPF::Calculate()
{
	m_vecDPF.clear();
	Cproj_letiDlg *pDlg = (Cproj_letiDlg *)AfxGetMainWnd();//ѕолучаем указатель на текущий диалог
	if (!pDlg) {
		return false;
	}
	std::vector<POINT> *vec = pDlg->m_Pt.GetPoints_dPoint();
	size_t N = vec->size();
	for (size_t k = 0; k <= N / 2; k++)
	{
		double xScale = m_Param.Width;
		CPoint pt;
		if (Scale(pt, xScale, m_Param.Scale, m_Param.yShift, vec, k))
		{
			if (Shift(pt))
				m_vecDPF.push_back(POINT(pt));
		}
	}
	return m_vecDPF.size() > 0;
}