#ifndef MYPOINT_H
#define MYPOINT_H
#include "MyLineSegment.h"
#include <iostream>
#include <cstdio>

using namespace std;

class MyPoint {
private:
	int x;
	int y;
public:
	MyPoint() {}
	MyPoint(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void setX(int x) {
		this->x = x;
	}
	int getX() const {
		return x;
	}
	void setY(int y) {
		this->y = y;
	}
	int getY() const {
		return y;
	}
	int dist2sqr(const MyPoint& a) const {
		return (a.x - a.y) * (a.x - a.y);
	}
};

#endif