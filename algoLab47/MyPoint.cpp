#include <cstdlib>
#include "MyPoint.h"
// constructors
MyPoint::MyPoint()
	:x(0), y(0) // set default to origin (0,0)
{
}
MyPoint::MyPoint(int coordX, int coordY)
	: x(coordX), y(coordY)
{
}
MyPoint::MyPoint(const MyPoint& p)
	: x(p.x), y(p.y)
{
}
// accessor functions
int MyPoint::getX() const
{
	return x;
}
int MyPoint::getY() const
{
	return y;
}
// mutator functions
void MyPoint::setX(int coordX)
{
	x = coordX;
}
void MyPoint::setY(int coordY)
{
	y = coordY;
}
bool MyPoint::operator== (const MyPoint& p) const
{
	if (x == p.x && y == p.y)
		return true;
	else
		return false;
}
bool MyPoint::operator!= (const MyPoint& p) const
{
	return !operator==(p);
}
// �����Ÿ�(Euclidean distance)�� ������ ���
int MyPoint::dist2sqr(const MyPoint& p) const
{
	return (p.x - x)*(p.x - x) + (p.y - y)*(p.y - y);
}
// �����Ÿ�(rectilinear distance)�� ���
int MyPoint::dist1(const MyPoint& p) const
{
	return abs(p.x - x) + abs(p.y - y);
}