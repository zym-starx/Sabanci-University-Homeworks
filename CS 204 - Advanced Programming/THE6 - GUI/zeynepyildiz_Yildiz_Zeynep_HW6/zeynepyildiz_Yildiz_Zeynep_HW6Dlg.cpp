
// zeynepyildiz_Yildiz_Zeynep_HW6Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "zeynepyildiz_Yildiz_Zeynep_HW6.h"
#include "zeynepyildiz_Yildiz_Zeynep_HW6Dlg.h"
#include "afxdialogex.h"
#include <string>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Czeynepyildiz_Yildiz_Zeynep_HW6Dlg dialog



Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::Czeynepyildiz_Yildiz_Zeynep_HW6Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::IDD, pParent)
	, groupOperator(0)
	, GroupOperator(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, input1);
	DDX_Control(pDX, IDC_EDIT2, input2);
	DDX_Control(pDX, IDC_LIST1, listresult);
	DDX_Control(pDX, IDC_CHECK1, shiftcheck);
	DDX_Control(pDX, IDC_COMBO1, combo1);
	DDX_Control(pDX, IDC_EDIT3, shiftnum);
	DDX_Radio(pDX, IDC_RADIO1, GroupOperator);
}

BEGIN_MESSAGE_MAP(Czeynepyildiz_Yildiz_Zeynep_HW6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_CHECK1, &Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnBnClickedCheck1)
	ON_LBN_SELCHANGE(IDC_LIST1, &Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// Czeynepyildiz_Yildiz_Zeynep_HW6Dlg message handlers

BOOL Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	/*if (combo1.GetCurSel() != NULL)
	{
		combo1.SetCurSel(combo1.FindStringExact(0, _T("Left")));
	}*/
	/*combo1.SetCurSel(1);
	combo1.SelectString(0, _T("Left"));*/
}


CString operatorPressed;

void Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	static int maxSize = 0;
	CString operand1, operand2, advancedText, resultstr, shiftdir, shiftsaystr;
	unsigned int num1, num2, result, shiftsay;
	CDC *pDC = GetDC();
	CFont *pOldFont = pDC->SelectObject(GetFont());
	CSize cz;

	input1.GetWindowTextW(operand1);
	input2.GetWindowTextW(operand2);
	shiftnum.GetWindowTextW(shiftsaystr);
	shiftsay = _ttof(shiftsaystr);
	num1 = _ttof(operand1);
	num2 = _ttof(operand2);
	result = 100;

	if(shiftcheck.GetCheck() == 1)
	{
		combo1.GetWindowTextW(shiftdir);

		if(shiftdir == "Left")
		{
			num1 = num1 << shiftsay;
			num2 = num2 << shiftsay;
		}
		else
		{
			num1 = num1 >> shiftsay;
			num2 = num2 >> shiftsay;
		}
	}

	if (IsDlgButtonChecked(IDC_RADIO1))
	{
		operatorPressed = _T("AND");
		result = (num1 & num2);
	}
	else if (IsDlgButtonChecked(IDC_RADIO2))
	{
		operatorPressed = _T("OR");
		result = (num1 | num2);
	}
	else if (IsDlgButtonChecked(IDC_RADIO3))
	{
		operatorPressed = _T("XOR");
		result = (num1 ^ num2);
	}
	//dont know why but these didn't work
	/*
	//if (GroupOperator == 0)
	//{
	//	operatorPressed = _T("AND");
	//	result = (num1 & num2);
	//}
	//else if (GroupOperator == 1)
	//{
	//	operatorPressed = _T("OR");
	//	result = (num1 | num2);
	//}
	//else if (GroupOperator == 2)
	//{
	//	operatorPressed = _T("XOR");
	//	result = (num1 ^ num2);
	//}

	if (operatorPressed == _T("&"))
	{
		result = num1 & num2;
	}
	else if (operatorPressed == _T("|"))
	{
		result = num1 | num2;
	}
	else if (operatorPressed == _T("^"))
	{
		result = num1 ^ num2;
	}*/

	resultstr.Format(L"%d", result);
	operand1.Format(L"%d", num1);
	operand2.Format(L"%d", num2);
	advancedText = operand1 + _T(" ") + operatorPressed + _T(" ") + operand2 + _T(" = ") + resultstr;
	
	cz = pDC ->GetTextExtent(advancedText);
	if(cz.cx > maxSize)// cz.cx keeps the horizontal length of the string. We compare 
		maxSize = cz.cx + 4;
	listresult.AddString(advancedText);
	listresult.SetHorizontalExtent(maxSize);

}


void Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	operatorPressed = _T("AND");
}


void Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	operatorPressed = _T("OR");
}


void Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	operatorPressed = _T("XOR");
}


void Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	combo1.SetCurSel(0);
	if(shiftcheck.GetCheck() == 1)
	{
		combo1.EnableWindow(TRUE);
		shiftnum.EnableWindow(TRUE);
	}
	else
	{
		combo1.EnableWindow(FALSE);
		shiftnum.EnableWindow(FALSE);
	}
	
}


void Czeynepyildiz_Yildiz_Zeynep_HW6Dlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}
