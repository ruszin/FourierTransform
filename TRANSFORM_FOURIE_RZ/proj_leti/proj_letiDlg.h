
// proj_letiDlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"
#include "PaintPic.h"
#include "afxcmn.h"
#include<vector>
#include "Cproj_letiCalc.h"
#include "PaintPic2.h"
#include "Cproj_letiCalcDPF.h"
using namespace std;



// ���������� ���� Cproj_letiDlg
class Cproj_letiDlg : public CDialogEx
{
// ��������
public:
	Cproj_letiDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJ_LETI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnPaint2();
	afx_msg void OnBnClickedOk();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:	
	afx_msg void OnEnChangeEdit1();
	CEdit m_cEdit1;
	// static drawing
	CPaintPic m_paintPic;
	afx_msg void OnAcnStartAnimate1();
	// ���� ������ ��� �������(� ���� �������)
	CEdit m_Calc;
	afx_msg void OnBnClickedCheck3();
	bool pr;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedSavePic();
	float m_freq[10];
	float m_phase[10];
	float m_amp[10];
	//PainPic control
	dPoint m_Pt;
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	// ���������� ���������� ����.����� ��� WM_MOUSE_MOVE(������ ���������)
	CString m_strF;
	CStatic m_st_SH;
	afx_msg void OnStnClickedStSh();
	afx_msg void OnStnClickedStHelp();

	CString m_HelpVal;
	afx_msg void On32773();
	afx_msg void On32772();
	// ���������� control ��� �������� ������� ����
	//CPaintPic;
	afx_msg void OnAcnStartAnimate2();

	afx_msg void OnStnClickedStatic5();
	// ���������� ��� �������� ����� ���������
	float m_MinMaxValCheck;
	enum DocumentType{Value};
	DocumentType m_Doc;
	CPaintPic2 m_paintDPF;
	dPoint m_c;
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_SpinPicSignal;
	afx_msg void OnBnClickedSavePicdpf();
	Cproj_letiCalcDPF m_DPF;
	afx_msg void OnMouseHWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};
