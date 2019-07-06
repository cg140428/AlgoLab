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

		for (int i = 0; i < num / 2; i++) {
			for (int j = 0; j < num; j++) {
				if (j == num / 2)
					cout << "I";
				else if (j == (num - 1) - i)
					cout << "*";
				else
					cout << ".";

			}
			cout << endl;
		}

		for (int j = 0; j < num; j++) {
			if (j == num / 2)
				cout << "O";
			else
				cout << "+";
		}
		cout << endl;

		for (int i = 0; i < num / 2; i++) {
			for (int j = 0; j < num; j++) {
				if (j == num / 2)
					cout << "I";
				else if (j == num / 2 - (i + 1))
					cout << "*";
				else
					cout << ".";
			}
			cout << endl;
		}
	}

	return 0;
}