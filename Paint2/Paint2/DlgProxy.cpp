
// DlgProxy.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Paint2.h"
#include "DlgProxy.h"
#include "Paint2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPaint2DlgAutoProxy

IMPLEMENT_DYNCREATE(CPaint2DlgAutoProxy, CCmdTarget)

CPaint2DlgAutoProxy::CPaint2DlgAutoProxy()
{
	EnableAutomation();

	// To keep the application running as long as an automation
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CPaint2Dlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CPaint2Dlg)))
		{
			m_pDialog = reinterpret_cast<CPaint2Dlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CPaint2DlgAutoProxy::~CPaint2DlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}

void CPaint2DlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CPaint2DlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPaint2DlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// Note: we add support for IID_IPaint2 to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the
//  dispinterface in the .IDL file.

// {442a4113-7cbf-4716-be3d-66fbe1205778}
static const IID IID_IPaint2 =
{0x442a4113,0x7cbf,0x4716,{0xbe,0x3d,0x66,0xfb,0xe1,0x20,0x57,0x78}};

BEGIN_INTERFACE_MAP(CPaint2DlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CPaint2DlgAutoProxy, IID_IPaint2, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in pch.h of this project
// {2cfaa8b7-7152-435f-98e3-df1cf8117ddc}
IMPLEMENT_OLECREATE2(CPaint2DlgAutoProxy, "Paint2.Application", 0x2cfaa8b7,0x7152,0x435f,0x98,0xe3,0xdf,0x1c,0xf8,0x11,0x7d,0xdc)


// CPaint2DlgAutoProxy message handlers
