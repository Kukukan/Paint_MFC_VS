
// DlgProxy.h: header file
//

#pragma once

class CPaint2Dlg;


// CPaint2DlgAutoProxy command target

class CPaint2DlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CPaint2DlgAutoProxy)

	CPaint2DlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CPaint2Dlg* m_pDialog;

// Operations
public:

// Overrides
	public:
	virtual void OnFinalRelease();

// Implementation
protected:
	virtual ~CPaint2DlgAutoProxy();

	// Generated message map functions

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CPaint2DlgAutoProxy)

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

