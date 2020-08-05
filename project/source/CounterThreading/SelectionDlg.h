#pragma once


// CSelectionDlg dialog

class CSelectionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectionDlg)

public:
	CSelectionDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSelectionDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString strSelectedItem;
	afx_msg void OnBnClickedOk();
};
