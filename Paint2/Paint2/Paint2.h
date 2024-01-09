
// Paint2.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPaint2App:
// See Paint2.cpp for the implementation of this class
//

class CPaint2App : public CWinApp
{
public:
	CPaint2App();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPaint2App theApp;
