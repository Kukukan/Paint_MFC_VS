// RectangleF.cpp : implementation file
//

#include "pch.h"
#include "Paint2.h"
#include "RectangleF.h"
#include "stdafx.h" 
IMPLEMENT_SERIAL(RectangleF, CObject, 1)

// RectangleF


RectangleF::~RectangleF()
{
}

RectangleF::RectangleF()
{
	shapeKind = 1;
}
RectangleF::RectangleF(CPoint p1, CPoint p2)
	:Figure(p1, p2)
{
	shapeKind = 1;
}

// RectangleF member functions
