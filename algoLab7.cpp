#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	FILE * f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	for (int i = 0; i < turn; i++) {
		int num;
		fscanf(f, "%d", &num);

		int sum = 0;
		int element;

		for (int j = 0; j < num; j++) {
			fscanf(f, "%d", &element);
			sum += element;
		}

		cout << sum << endl;
	}
	return 0;
}