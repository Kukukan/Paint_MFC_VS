#include "pch.h"
#include "CircleF.h"
#include "stdafx.h"

IMPLEMENT_SERIAL(CircleF, CObject, 1)
CircleF::CircleF()
{
	shapeKind = 2;
}
CircleF::CircleF(CPoint p1, CPoint p2):EllipseF(p1, p2)
{
	shapeKind = 2;
}
void CircleF::Draw(CDC* dc)
{
	CPoint p1 = Figure::getP1();
	CPoint p2 = Figure::getP2();
	CPen pen(PS_SOLID, Thick ? 10 : 2, figureFrameColor);
	CPen* pOldPen = dc->SelectObject(&pen);
	CBrush brush(figureColor);
	CBrush* oldBrush = dc->SelectObject(&brush);

	int side, length, heigth;
	length = p1.x - p2.x;
	heigth = p1.y - p2.y;
	if (length < 0)
		length *= -1;
	if (heigth < 0)
		heigth *= -1;
	side = length > heigth ? length : heigth;
	if (p2.y > p1.y && p2.x > p1.x)
	{
		dc->Ellipse(p1.x, p1.y, p1.x + side, p1.y + side);
		p2.x = p1.x + side;
		p2.y = p1.y + side;
		Figure::Redefine(p1, p2);
	}
	else if (p2.y > p1.y && p2.x < p1.x)
	{
		dc->Ellipse(p1.x, p1.y, p1.x - side, p1.y + side);
		p2.x = p1.x - side;
		p2.y = p1.y + side;
		Figure::Redefine(p1, p2);
	}
	else if (p2.y<p1.y && p2.x>p1.x)
	{
		dc->Ellipse(p1.x, p1.y, p1.x + side, p1.y - side);
		p2.x = p1.x + side;
		p2.y = p1.y - side;
		Figure::Redefine(p1, p2);
	}
	else
	{
		dc->Ellipse(p1.x, p1.y, p1.x - side, p1.y - side);
		p2.x = p1.x - side;
		p2.y = p1.y - side;
		Figure::Redefine(p1, p2);
	}
}