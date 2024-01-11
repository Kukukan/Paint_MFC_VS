#pragma once
#include "Figure.h"
// RectangleF command target

class RectangleF : public Figure
{
	DECLARE_SERIAL(RectangleF)   
public:
	RectangleF();
	RectangleF(CPoint p1, CPoint p2);
	virtual ~RectangleF();
};


