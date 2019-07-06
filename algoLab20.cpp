#include <iostream>
#include <cstdio>

using namespace std;
int getArea(int arr[], int num);

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int off[200];
		int num;
		fscanf(f, "%d", &num);

		for (int i = 0; i < 2 * num; i++) {
			fscanf(f, "%d", &off[i]);
		}

		//반시계
		if (getArea(off, num) > 0)
			cout << getArea(off, num) << " 1" << endl;
		//시계
		else if (getArea(off, num) < 0)
			cout << (-1) * getArea(off, num) << " -1" << endl;

	}
	return 0;
}


int getArea(int arr[], int num) {
	int sum = 0;
	for (int i = 0; i < (2 * num); i += 2) {
		if (i < (2 * num) - 3)
			sum += (arr[i] + arr[i + 2]) * (arr[i + 3] - arr[i + 1]);
		else
			sum += (arr[i] + arr[0]) * (arr[1] - arr[i + 1]);
	}
	return sum;
}