#ifndhttps://algolab.kookmin.ac.kr/submission_code%3FcourseIndex%3D90%26memberIdIndex%3D2940%26organizationIndex%3D1%26problemIndex%3D129%26status%3DSOLVED%26teamIndex%3D0#0ef MYLINESEGMENT_H
#define MYLINESEGMENT_H
#include "MyPoint.h"

class MyLineSegment
{
public:
	// constructors
	MyLineSegment();
	MyLineSegment(const MyPoint& p, const MyPoint& q);
	MyLineSegment(const MyLineSegment& seg);
	// intersection test functions
	bool isEndOfSegment(const MyPoint & p) const;
	bool isOnSegment(const MyPoint& p) const;
	bool properIntersection(const MyLineSegment &s) const;
	bool improperIntersection(const MyLineSegment &s) const;
	bool isLeftSide(const MyPoint &p) const; // test whether p is to the left side of the direction from p1 to p2
	bool isCollinear(const MyPoint &p) const; // test whether p1, p2, p3 is collinear utility functions
	int length2sqr() const; // square of (Euclidean) length
private:
	MyPoint p1, p2;
	int getArea2(const MyPoint &p) const; // signed area of triangle p1, p2, p
};
#endif // _MY_LINE_SEGMENT_H_ 