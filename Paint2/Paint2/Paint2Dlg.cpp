
// Paint2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Paint2.h"
#include "Paint2Dlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include "Figure.h"
#include "RectangleF.h"
#include "stdafx.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	EnableActiveAccessibility();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPaint2Dlg dialog


IMPLEMENT_DYNAMIC(CPaint2Dlg, CDialogEx);

CPaint2Dlg::CPaint2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAINT2_DIALOG, pParent)
	, name(_T(""))
	, Thick(FALSE)
{
	EnableActiveAccessibility();
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = nullptr;
}

CPaint2Dlg::~CPaint2Dlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to null, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != nullptr)
		m_pAutoProxy->m_pDialog = nullptr;
}

void CPaint2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Check(pDX, IDC_CHECK1, Thick);
}

BEGIN_MESSAGE_MAP(CPaint2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON2, &CPaint2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &CPaint2Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_BUTTON3, &CPaint2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_RADIO2, &CPaint2Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CPaint2Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CPaint2Dlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CPaint2Dlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_CHECK1, &CPaint2Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON1, &CPaint2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CPaint2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CPaint2Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CPaint2Dlg message handlers

BOOL CPaint2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

void CPaint2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPaint2Dlg::OnPaint()
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
		CPaintDC dc(this); // device context for painting
		for (int i = 0; i < figs.GetSize(); i++) // Here we draw all the figures over and over again
			figs[i]->Draw(&dc);

		CDialogEx::OnPaint();
		if (Submit == true && name != "") // If we entered a name , we want this code to run
		{
			CRect rect;
			GetClientRect(&rect);  // Get screen rectangle
			CFont font;
			font.CreatePointFont(350, _T("Arial"));
			CFont* oldFont = dc.SelectObject(&font);
			dc.SetBkMode(TRANSPARENT); // Transparent so they hide other
			dc.SetTextColor(nameColor); //Set color according to user preference
			dc.DrawText(name, &rect, DT_SINGLELINE | DT_BOTTOM | DT_LEFT); // draw
			rect.OffsetRect(0, -50); // offset a little
			dc.DrawText(_T("Hello"), &rect, DT_SINGLELINE | DT_BOTTOM | DT_LEFT); // add hello
			CDialogEx::OnPaint();
		}
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPaint2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.
void CPaint2Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	isPressed = true;

	
	if (Delete) // If we are in delete state 
	{
		for (int i = figs.GetSize() - 1; i >= 0; i--) // We run from the end to the beginning , to delete the latest object (the front object)
		{
			if (figs[i]->isInside(point)) // If mouse cursor isInside
			{
				figs[i]->P1.x = NULL; // Delete all his values
				figs[i]->P1.y = NULL;
				figs[i]->P2.x = NULL;
				figs[i]->P2.y = NULL;
				Invalidate();
				break;
			}

		}
	}

	else if (Move) // If we are in a move state
	{
		int counter = 0; // Here we count how many objects our mouse isInside
		for (int i = 0; i < figs.GetSize(); i++)
		{
			if (figs[i]->isInside(point)) // If mouse cursor isInside
			{
				counter++;
				temp = i; // Save the latest index
			}
			else if (counter == 0)temp = -1; // Else we assign -1 to temp to indicate our mouse isn't pointing on any object
		}
	}

	else // If we are not in a move state , we are drawing
	{

		start = point;
		switch (futureFigureKind) // What shape ? add to figure array
		{
		case 1:
			figs.Add(new RectangleF(start, start));
			break;
		case 2:
			figs.Add(new CircleF(start, start));
			break;
		case 3:
			figs.Add(new SquareF(start, start));
			break;
		case 4:
			figs.Add(new EllipseF(start, start));
			break;
		case 5:
			figs.Add(new LineF(start, start));
			break;
		}
		CDialogEx::OnLButtonDown(nFlags, point);

	}
}
void CPaint2Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (isPressed && Draw) // If we're not in a "Move object" state and mouse is pressed , we wanna draw
	{
		end = point;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		Invalidate(); //simulates the WM_PAINT message to redraw window
		undo.RemoveAll(); // Cleaning the undo array
	}
	isPressed = false;
	flag = 0;

	CDialogEx::OnLButtonUp(nFlags, point);
}

void CPaint2Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (Move && temp != -1 && isPressed) // If we're in a "Move object" state and our mouse is inside atleast 1 object and mouse is pressed
	{
		if (flag == 0) // If it's the first mouse movement
		{
			lastPoint = point;
			flag = 1;
		}
		else // For any other mouse movements , calculate the new position by comparing with the last position and adjusting
		{
			figs[temp]->P1.x += (point.x - lastPoint.x);
			figs[temp]->P1.y += (point.y - lastPoint.y);
			figs[temp]->P2.x += (point.x - lastPoint.x);
			figs[temp]->P2.y += (point.y - lastPoint.y);
			lastPoint = point;
			Invalidate();
		}
	}

	else if (isPressed && Draw) // If we're not in a "Move object" and mouse is pressed we draw
	{
		end = point;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		figs[figs.GetSize() - 1]->figureColor = shapeColor;
		figs[figs.GetSize() - 1]->figureFrameColor = frameColor;
		figs[figs.GetSize() - 1]->Thick = Thick;
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

void CPaint2Dlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CPaint2Dlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CPaint2Dlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CPaint2Dlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != nullptr)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}



void CPaint2Dlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 1; // Rectangle
	OnBnClickedButton3(); // Call to draw button
}



void CPaint2Dlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 2;	//Circle
	OnBnClickedButton3();
}


void CPaint2Dlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 3;	//square
	OnBnClickedButton3();
}


void CPaint2Dlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 4;	//ellipse
	OnBnClickedButton3();
}


void CPaint2Dlg::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 5;	//Line
	OnBnClickedButton3();
}


void CPaint2Dlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	Thick = true;
}


void CPaint2Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		shapeColor = dlg.GetColor();
	}
}

void CPaint2Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		nameColor = dlg.GetColor();
	}
	Invalidate();
}

void CPaint2Dlg::OnBnClickedButton3()	//draw
{
	// TODO: Add your control notification handler code here
	Move = false; // Since draw is our default , we just need to disable Move
	Delete = false;
	Draw = true;
}


void CPaint2Dlg::OnBnClickedButton4()	//move
{
	// TODO: Add your control notification handler code here
	Move = true;
	Delete = false;
	Draw = false;
}


void CPaint2Dlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	Move = false;
	Delete = true;
	Draw = false;
}
