#include <iostream>
#include <cstdio>

using namespace std;


int main(void) {
	FILE * f;
	f = fopen("input.txt", "r");
	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int height, width;
		fscanf(f, "%d", &height);
		width = height;

		for (int i = 0; i < height / 2; i++) {
			for (int k = 0; k < width; k++) {
				if (k < (width / 2) - i)
					cout << "*";
				else if (k >= (width / 2) - i && k <= (width / 2) + i)
					cout << "+";
				else
					cout << "*";
			}
			cout << endl;
		}


		for (int k = 0; k < width; k++)
			cout << "+";
		cout << endl;

		for (int i = 0; i < height / 2; i++) {
			for (int k = 0; k < width; k++) {
				if (k < i + 1)
					cout << "*";
				else if (k >= i && k < (width - 1) - i)
					cout << "+";
				else
					cout << "*";
			}
			cout << endl;
		}
	}
}