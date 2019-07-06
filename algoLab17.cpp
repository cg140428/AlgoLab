#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int absolSub(int& a, int& x);
double getEucDistance(int& x1, int& y1, int& x2, int& y2);
int getRecDistance(int& x1, int& y1, int& x2, int& y2);

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		//사각형
		int x1, y1;
		int x2, y2;
		fscanf(f, "%d %d %d %d", &x1, &y1, &x2, &y2);

		//좌표
		int a, b;
		fscanf(f, "%d %d", &a, &b);

		//사각형의 변을 연장하여 9영역으로 나눈다. 왼쪽 위부터 1영역이라 칭함
		if (a >= x1 && a <= x2) {
			//좌표가 사각형 안에 있을 경우 (5영역)
			if (b >= y1 && b <= y2)
				cout << "0 0" << endl;
			else {
				//8영역
				if (b < y1) {
					cout << getEucDistance(a, b, a, y1) << " ";
					cout << absolSub(b, y1) << endl;
				}
				//2영역
				else {
					cout << getEucDistance(a, b, a, y2) << " ";
					cout << absolSub(b, y2) << endl;
				}
			}
		}
		else if (a < x1) {
			//4영역
			if (b >= y1 && b <= y2) {
				cout << getEucDistance(a, b, x1, b) << " ";
				cout << absolSub(a, x1) << endl;
			}
			//7영역
			else if (b < y1) {
				cout << getEucDistance(a, b, x1, y1) << " ";
				cout << getRecDistance(a, b, x1, y1) << endl;
			}
			//1영역
			else {
				cout << getEucDistance(a, b, x1, y2) << " ";
				cout << getRecDistance(a, b, x1, y2) << endl;
			}

		}
		else {
			//6영역
			if (b >= y1 && b <= y2) {
				cout << getEucDistance(a, b, x2, b) << " ";
				cout << absolSub(a, x2) << endl;
			}
			//9영역
			else if (b < y1) {
				cout << getEucDistance(a, b, x2, y1) << " ";
				cout << getRecDistance(a, b, x2, y1) << endl;
			}
			//3영역
			else {
				cout << getEucDistance(a, b, x2, y2) << " ";
				cout << getRecDistance(a, b, x2, y2) << endl;
			}
		}
	}
	return 0;
}

int absolSub(int& a, int& x) {
	int sub = a - x;
	if (sub < 0)
		return -sub;
	else
		return sub;
}

double getEucDistance(int& x1, int& y1, int& x2, int& y2) {
	return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

int getRecDistance(int& x1, int& y1, int& x2, int& y2) {
	int recDistance[2];
	recDistance[0] = x2 - x1;
	recDistance[1] = y2 - y1;
	int recDistanceSum = 0;

	for (int i = 0; i < sizeof(recDistance) / sizeof(int); i++) {
		if (recDistance[i] < 0) {
			recDistanceSum += -recDistance[i];
		}
		else
			recDistanceSum += recDistance[i];
	}

	return recDistanceSum;
}