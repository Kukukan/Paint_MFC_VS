#include "pch.h"
#include "LineF.h"
#include "stdafx.h"
IMPLEMENT_SERIAL(LineF, CObject, 1)
LineF::LineF()
{
	shapeKind = 5;
}
LineF::LineF(CPoint p1, CPoint p2)
	:Figure(p1, p2)
{
	shapeKind = 5;
}
void LineF::Draw(CDC* dc)
{
	CPen pen(PS_SOLID, Thick ? 10 : 2, figureColor);
	CPen* pOldPen = dc->SelectObject(&pen);
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->MoveTo(p1.x, p1.y);
	dc->LineTo(p2.x, p2.y);

}