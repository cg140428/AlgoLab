#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	FILE * f;
	f = fopen("input.txt", "r");

	int turn;

	fscanf(f, "%d", &turn);

	int start, end, sum = 0;

	for (int i = 0; i < turn; i++) {
		fscanf(f, "%d %d", &start, &end);
		for (int j = start; j <= end; j++)
			sum += j;
		cout << sum << endl;
		sum = 0;
	}

	
	return 0;
}