#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int mul = 1;
		int num;
		int element;
		int twoNum = 0;
		int fiveNum = 0;
		int tenNum;
		fscanf(f, "%d", &num);
		for (int i = 0; i < num; i++) {
			fscanf(f, "%d", &element);
			while (element % 2 == 0 || element % 5 == 0) {
				if (element % 2 == 0) {
					twoNum++;
					element /= 2;
				}
				else {
					fiveNum++;
					element /= 5;
				}

			}
			mul *= element % 10;
			mul %= 10;
		}

		if (twoNum == fiveNum)
			tenNum = twoNum;
		else {
			int sub = twoNum - fiveNum;
			if (sub < 0) {
				for (int i = 0; i < -sub; i++) {
					mul *= 5;
					mul %= 10;
				}
				tenNum = twoNum;
			}
			else {
				for (int i = 0; i < sub; i++) {
					mul *= 2;
					mul %= 10;
				}
				tenNum = fiveNum;
			}
		}
		cout << mul << " " << tenNum << endl;
	}
	return 0;
}