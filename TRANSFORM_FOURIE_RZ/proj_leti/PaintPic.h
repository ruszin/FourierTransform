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
	// ��� �������� ���-�� ����� 
	size_t m_Npt;
	//������� ���� ��� 1 �������
	COLORREF m_BackCol_1;
	//������� ���� ��� 2 �������
	//���� ��������� ��� 1 �������
	COLORREF m_GraphCol_1;
};


