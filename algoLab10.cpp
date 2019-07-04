#include <iostream>
#include <cstdio>

using namespace std;


int main(void) {
	FILE * f;
	f = fopen("input.txt", "r");
	int turn;
	fscanf(f, "%d", &turn);
	while (turn--) {
		int num;
		int element;
		int mul = 1;
		fscanf(f, "%d", &num);
		for (int i = 0; i < num; i++) {
			fscanf(f, "%d", &element);
			element %= 10;
			mul *= element;
			mul %= 10;
		}

		cout << mul << endl;
	}
}