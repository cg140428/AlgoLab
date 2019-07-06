#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int num;
		fscanf(f, "%d", &num);

		int count = 0;

		for (int i = 0; i < num / 2; i++) {
			for (int j = 0; j < num; j++) {
				if (j < i || j > num - (i + 1))
					cout << "-";
				else {
					if (count % 2 == 0) {
						cout << "*";
						count++;
					}
					else {
						cout << "+";
						count++;
					}
				}

			}
			count = 0;
			cout << endl;
		}


		for (int i = 0; i < (num / 2) + 1; i++) {
			for (int j = 0; j < num; j++) {
				if (j < (num / 2) - (i) || j >(num / 2) + (i))
					cout << "-";
				else {
					if (count % 2 == 0) {
						cout << "*";
						count++;
					}
					else {
						cout << "+";
						count++;
					}
				}
			}
			count = 0;
			cout << endl;
		}
	}
	return 0;
}