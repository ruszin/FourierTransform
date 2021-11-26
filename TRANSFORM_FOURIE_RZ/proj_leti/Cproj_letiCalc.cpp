#include "stdafx.h"
#include "proj_leti.h"
#include "Cproj_letiCalc.h"
#include "proj_letiDlg.h"
#include "cmath"
#define _USE_MATH_DEFINES
#include "math.h"
dPoint::dPoint()
{
	m_Param.Scale = 50;
	m_Param.xMax = 6 * M_PI;
	m_Param.nPoints = 360;
	m_Param.yCenter = 182;
	m_Param.dXRad = 0;
}

bool dPoint::Calculate_dPoint() {

	m_vecPt.clear();
	double DeltaArg = m_Param.nPoints ? m_Param.xMax / m_Param.nPoints : 0.017;
	for (size_t ni = 0; ni < m_Param.nPoints; ni++)
	{
		double Arg = ni * DeltaArg;
		CPoint pt;
		if (Scale(pt, m_Param.Scale, m_Param.Scale, Arg, m_Param.dXRad, m_Param.f_Fd, m_Param.Fm, m_Param.m, m_Param.amplitude))
		{
			if (Shift(pt))
				m_vecPt.push_back(POINT(pt));
		}
	}
	return m_vecPt.size() > 0;

}
std::vector<POINT> *dPoint::GetPoints_dPoint()
{
	return &m_vecPt;
}

bool dPoint::Scale(CPoint & pt, double ScaleX, double ScaleY, double Arg, double Param, double f_Fd[], double Fm[], double m[], double amplitude[])
{

	CMyFun fn;
	if (fn.Calc(Arg, Param, f_Fd, Fm, m, amplitude))
	{
		pt.x = (int)floor(ScaleX * fn.X);
		pt.y = -(int)floor(ScaleY * fn.Y);
		return true;
	}
	return false;
}

bool dPoint::Shift(CPoint & pt)
{
	pt.Offset(m_Param.xCenter, m_Param.yCenter);
	return true;
}

bool dPoint::SetParams(MyParams_t &par)
{
	m_Param = par;
	Calculate_dPoint();
	return true;
}
bool CMyFun::Calc(double f, double k, double f_Fd[], double Fm[], double m[], double amplitude[])
{

	X = f;
	Y = 0;
	//a*sin(2*PI*(f +m*sin(2*PI*Fm*t)*t)-график сигнальной функции
	for (int i = 0; i < 9; i++) {
		Y += amplitude[i] * sin(2 * M_PI*(f_Fd[i] + m[i] * sin(2 * M_PI*Fm[i] * f)*f));
	}
	return true;
}


//double dPoint::function_dpf(double x){
//	double Fd = 1000000;
//	double Fm[9] = { 0.01*Fd,0.02*Fd,0.03*Fd,0.04*Fd,0.05*Fd,0.06*Fd,0.07*Fd,0.08*Fd,0.09*Fd };
//	double amplitude[9] = { 0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9 };
//	double f_Fd[9] = { 0.1*Fd,0.14*Fd,0.18*Fd,0.22*Fd,0.26*Fd,0.3*Fd,0.32*Fd,0.34*Fd,0.4*Fd };
//	double m[9] = { 0,f_Fd[0] / 2,f_Fd[1] / 3,f_Fd[2] / 4,f_Fd[3] / 5,f_Fd[4] / 6,f_Fd[5] / 7,f_Fd[6] / 8,f_Fd[7] / 9 };
//	double f_x = 0;
//	
//	for (int i = 0; i < 9; i++) {
//		f_x += amplitude[i] * sin(2 * M_PI*(f_Fd[i] + m[i] * sin(2 * M_PI*Fm[i] * i)*i));
//	}
//	return f_x*pow(2.72,-2*sqrt(cos(f_x)+sin(f_x)*M_PI/9));
//}
//double dPoint::trapecii(double left_gr, double right_gr, int n) {
//	double ksi = 0.0;
//	double delta_x = 0.0;
//
//	double trapecii_integral = (function_dpf(left_gr) + function_dpf(right_gr)) / 2.0;
//	ksi = left_gr;
//	delta_x = (right_gr - left_gr) / n;
//
//	for (int k = 1; k < n; ++k) {
//		ksi += delta_x;
//		trapecii_integral += function_dpf(ksi);
//	}
//	return trapecii_integral * delta_x;
//}

