#pragma once
#include <vector>
typedef struct
{
	double Scale = 8.; //signal scale
	size_t nPoints=360;
	int yCenter;
	int xCenter;
	int Width=300;
	int Height=300;
	double yShift;
}MyParams_DPF;
class Cproj_letiCalcDPF
{
public:
	double X;
	double Y;
public:
	bool Calc(std::vector<POINT> *vec, size_t k, double yShift);
public:
	Cproj_letiCalcDPF();
	~Cproj_letiCalcDPF();
public:
	bool Shift(CPoint &pt);
	bool Scale(CPoint & pt, double ScaleX, double ScaleY, double yShift, std::vector<POINT> *vec, size_t k);
public:
	bool Calculate();
	MyParams_DPF m_Param;//param set
	bool SetParams(MyParams_DPF &par);
	int GetNumPoints();
	std::vector<POINT>* GetPoints_DPF();
	std::vector<POINT> m_vecDPF;
};

