#ifndef MAIN_CPP
#define MAIN_CPP
#include "MyLineSegment.h"
#include "MyPoint.h"

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);
	while (turn--) {
		int x1, y1, x2, y2;
		fscanf(f, "%d %d %d %d", &x1, &y1, &x2, &y2);
		MyPoint p1(x1, y1), p2(x2, y2);
		MyLineSegment l1(p1, p2);

		fscanf(f, "%d %d %d %d", &x1, &y1, &x2, &y2);
		MyPoint p3(x1, y1), p4(x2, y2);
		MyLineSegment l2(p3, p4);

		if (l1.properIntersection(l2))
			cout << 1 << endl;
		else if (l1.improperIntersection(l2))
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}

#endif 