#ifndef MAIN_CPP
#define MAIN_CPP
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyTriangle.h"
using namespace std;
int main(void)
{
	ifstream inStream;
	int numTestCases;
	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	inStream >> numTestCases;
	for (int i = 0; i < numTestCases; i++)
	{
		int p1x, p1y, p2x, p2y, p3x, p3y;
		int qx, qy;
		inStream >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
		inStream >> qx >> qy;
		MyPoint p1(p1x, p1y), p2(p2x, p2y), p3(p3x, p3y);
		MyPoint q(qx, qy);
		MyTriangle tri(p1, p2, p3);
		if (tri.getArea2() == 0)
			cout << "0" << endl;
		else
		{
			cout << tri.getArea2() << " ";
			cout << tri.getType1() << " " << tri.getType2() << " ";
			if (tri.isInside(q))
				cout << "1" << endl;
			else if (tri.isOnBoundary(q))
				cout << "2" << endl;
			else if (tri.isOutside(q))
				cout << "3" << endl;
		}
	}
	inStream.close();
	return 0;
}

#endif