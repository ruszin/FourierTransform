#pragma once


// CPaintPic2

class CPaintPic2 : public CWnd
{
	DECLARE_DYNAMIC(CPaintPic2)

public:
	CPaintPic2();
	virtual ~CPaintPic2();

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


