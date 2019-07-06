#include <iostream>
#include <cstdio>

using namespace std;

int getSameOff(int a, int b, int c, int d);

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int x1, y1;
		int x2, y2;
		int x3, y3;
		int x4, y4;
		int result1;
		int result2;

		fscanf(f, "%d %d %d %d", &x1, &y1, &x2, &y2);
		fscanf(f, "%d %d %d %d", &x3, &y3, &x4, &y4);

		int vert_horiz = getSameOff(x1, y1, x2, y2);

		if (x1 == vert_horiz && x2 == vert_horiz)
			if ((x1 > x3 && x1 < x4) || (x1 > x4 && x1 < x3))
				result1 = 1;
			else if (x1 == x3 || x1 == x4)
				result1 = 2;
			else
				result1 = 0;
		else if (y1 == vert_horiz && y2 == vert_horiz)
			if ((y1 > y3 && y1 < y4) || (y1 > y4 && y1 < y3))
				result1 = 1;
			else if (y1 == y3 || y1 == y4)
				result1 = 2;
			else
				result1 = 0;

		int vert_horiz2 = getSameOff(x3, y3, x4, y4);
		if (x3 == vert_horiz2 && x4 == vert_horiz2)
			if ((x3 > x1 && x3 < x2) || (x3 > x2 && x3 < x1))
				result2 = 1;
			else if (x3 == x1 || x3 == x2)
				result2 = 2;
			else
				result2 = 0;
		else if (y3 == vert_horiz2 && y4 == vert_horiz2)
			if ((y3 > y1 && y3 < y2) || (y3 > y2 && y3 < y1))
				result2 = 1;
			else if (y3 == y1 || y3 == y2)
				result2 = 2;
			else
				result2 = 0;

		if (result1 == 1 && result2 == 1)
			cout << "1" << endl;
		else if (result1 == 0 || result2 == 0)
			cout << "0" << endl;
		else
			cout << "2" << endl;
	}
	return 0;
}

int getSameOff(int a, int b, int c, int d) {
	if (a == c)
		return a;
	else if (b == d)
		return b;
}