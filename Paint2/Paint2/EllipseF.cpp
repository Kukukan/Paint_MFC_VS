#include "pch.h"
#include "EllipseF.h"
#include "stdafx.h"
IMPLEMENT_SERIAL(EllipseF, CObject, 1)
EllipseF::EllipseF()
{
	shapeKind = 4;
}
EllipseF::EllipseF(CPoint p1, CPoint p2)
	:Figure(p1, p2)
{
	shapeKind = 4;
}
void EllipseF::Draw(CDC* dc)
{
	CPen pen(PS_SOLID, Thick ? 10 : 2, figureFrameColor);
	CPen* pOldPen = dc->SelectObject(&pen);
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	CBrush brush(figureColor);
	CBrush* oldBrush = dc->SelectObject(&brush);
	CRect rect(P1.x, P1.y, P2.x, P2.y);
	dc->Ellipse(rect);

}