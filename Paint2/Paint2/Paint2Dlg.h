
// Paint2Dlg.h : header file
//

#pragma once
#include "Figure.h"
#include "RectangleF.h"
#include "EllipseF.h"
#include "SquareF.h"
#include "CircleF.h"
#include "LineF.h"

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
	CPoint start, end;
	bool isPressed = false;

	// Our Variables
	bool Move = false; // Indicates a "Move object" state
	bool Delete = false; // Indicates a "Delete object" state
	bool Draw = true; //Indicates a "Draw object" state
	int temp = -1; // Here we save the position of the object we want to interact with
	CPoint lastPoint; // We use this point to be able to move the object by comparing current point with the last point
	int flag = 0; // An indication for the first mouse movement when we move an object
	bool Submit = false;// Indicates a "Write your name" state
	COLORREF nameColor; // Color used for name
	COLORREF frameColor = (0, 0, 0); // Color used for the frame of the shapes || Default color is black
	COLORREF shapeColor; // Color used for shapes


	CTypedPtrArray< CObArray, Figure*> figs; // Array of figures
	CTypedPtrArray< CObArray, Figure*> undo; // Array of undo figures


	int futureFigureKind = 1; // 1 - 5 all our shapes

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	CPaint2DlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	CString name;
	BOOL Thick;
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
