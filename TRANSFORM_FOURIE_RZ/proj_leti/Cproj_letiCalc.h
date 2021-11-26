#pragma once
#include <vector>
#include <complex>
typedef struct
{
public:
	double Scale;
	double xMax; 
	size_t nPoints=100; 
	int yCenter;
	int xCenter;
	double dXRad;
	double t;
	double Fd = 1000000;
	double f_Fd[9] = { 0.1*Fd,0.14*Fd,0.18*Fd,0.22*Fd,0.26*Fd,0.3*Fd,0.32*Fd,0.34*Fd,0.4*Fd };
	double Fm[9] = { 0.01*Fd,0.02*Fd,0.03*Fd,0.04*Fd,0.05*Fd,0.06*Fd,0.07*Fd,0.08*Fd,0.09*Fd };
	double m[9] = { 0,f_Fd[0] / 2,f_Fd[1] / 3,f_Fd[2] / 4,f_Fd[3] / 5,f_Fd[4] / 6,f_Fd[5] / 7,f_Fd[6] / 8,f_Fd[7] / 9 };
	double amplitude[9] = { 0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9 };
}MyParams_t;

class dPoint {
public:
	dPoint();
public:
	MyParams_t m_Param;
	double x;
	double y;
	bool Calculate_dPoint();
	std::vector<POINT> m_vecPt;
	std::vector<POINT> *GetPoints_dPoint();
	bool SetParams(MyParams_t &par);
	double X;
	double Y;
public:
	bool Scale(CPoint & pt, double ScaleX, double ScaleY, double Arg, double Param, double f_Fd[], double Fm[], double m[], double amplitude[]);
	bool Shift(CPoint & pt);
	
};
class CMyFun
{
public:
	CMyFun() {};
	~CMyFun() {};
public:
	double X;
	double Y;
public:
	std::vector<POINT> m_vecComplexPt;
	bool Calc(double f, double k, double f_Fd[], double Fm[], double m[], double amplitude[]);
};


