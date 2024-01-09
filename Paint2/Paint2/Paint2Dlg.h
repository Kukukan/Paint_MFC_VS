
// Paint2Dlg.h : header file
//

#pragma once

class CPaint2DlgAutoProxy;


// CPaint2Dlg dialog
class CPaint2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPaint2Dlg);
	friend class CPaint2DlgAutoProxy;

// Construction
public:
	CPaint2Dlg(CWnd* pParent = nullptr);	// standard constructor
	virtual ~CPaint2Dlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAINT2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	CPaint2DlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
};
