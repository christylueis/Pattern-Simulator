// SelectionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CounterThreading.h"
#include "SelectionDlg.h"
#include "afxdialogex.h"


// CSelectionDlg dialog

IMPLEMENT_DYNAMIC(CSelectionDlg, CDialogEx)

CSelectionDlg::CSelectionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, strSelectedItem(_T(""))
{

}

CSelectionDlg::~CSelectionDlg()
{
}

void CSelectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, strSelectedItem);
}


BEGIN_MESSAGE_MAP(CSelectionDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSelectionDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSelectionDlg message handlers


void CSelectionDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CDialogEx::OnOK();
}
