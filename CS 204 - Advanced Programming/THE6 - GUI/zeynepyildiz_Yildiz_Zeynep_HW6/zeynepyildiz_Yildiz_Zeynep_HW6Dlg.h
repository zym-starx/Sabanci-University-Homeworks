
// zeynepyildiz_Yildiz_Zeynep_HW6Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// Czeynepyildiz_Yildiz_Zeynep_HW6Dlg dialog
class Czeynepyildiz_Yildiz_Zeynep_HW6Dlg : public CDialogEx
{
// Construction
public:
	Czeynepyildiz_Yildiz_Zeynep_HW6Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_ZEYNEPYILDIZ_YILDIZ_ZEYNEP_HW6_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int groupOperator;
	afx_msg void OnCbnSelchangeCombo1();
	CEdit input1;
	CEdit input2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio1();
	CListBox listresult;
	CButton shiftcheck;
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	CComboBox combo1;
	afx_msg void OnBnClickedCheck1();
	CEdit shiftnum;
	afx_msg void OnLbnSelchangeList1();
	int GroupOperator;
};
