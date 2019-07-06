#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int a, b, c;
		fscanf(f, "%d %d %d", &a, &b, &c);

		if (a + b <= c)
			cout << "0" << endl;
		else if (a * a + b * b == c * c)
			cout << "2" << endl;
		else if (a == b) {
			if (b == c)
				cout << "1" << endl;
			else
				cout << "3" << endl;
		}
		else if (b == c) {
			if (c == a)
				cout << "1" << endl;
			else
				cout << "3" << endl;
		}
		else if (c == a) {
			if (a == b)
				cout << "1" << endl;
			else
				cout << "3" << endl;
		}
		else
			cout << "4" << endl;
	}
	return 0;
}