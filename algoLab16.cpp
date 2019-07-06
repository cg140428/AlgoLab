#include <iostream>
#include <cstdio>

using namespace std;

int getTriArea(int arr[]);

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int off[6];
		for (int i = 0; i < sizeof(off) / sizeof(int); i++) {
			fscanf(f, "%d", &off[i]);
		}

		//반시계
		if (getTriArea(off) > 0)
			cout << getTriArea(off) << " 1" << endl;
		//삼각형 성립x
		else if (getTriArea(off) == 0)
			cout << getTriArea(off) << " 0" << endl;
		//시계
		else
			cout << (-1) * getTriArea(off) << " -1" << endl;
	}
	return 0;
}

int getTriArea(int arr[]) {
	int area;
	return area = (arr[2] - arr[0]) * (arr[5] - arr[1]) - (arr[4] - arr[0]) * (arr[3] - arr[1]);
}