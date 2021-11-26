#pragma once


// CPaintPic

class CPaintPic : public CWnd
{
	DECLARE_DYNAMIC(CPaintPic)

public:
	CPaintPic();
	virtual ~CPaintPic();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	// Для передачи кол-ва точек 
	size_t m_Npt;
	//Заливка фона для 1 графика
	COLORREF m_BackCol_1;
	//Заливка фона для 2 графика
	//Цвет карандаша для 1 графика
	COLORREF m_GraphCol_1;
};


