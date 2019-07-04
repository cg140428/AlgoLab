#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int tri_size;

		fscanf(f, "%d", &tri_size);

		for (int i = 1; i < tri_size + 1; i++) {
			int element = i;
			int gap = tri_size - 1;
			for (int j = 0; j < i; j++) {
				cout << element;

				if (j != i) {
					cout << " ";
					element += gap--;
				}
				else
					continue;
			}
			cout << endl;
		}
	}
	return 0;
}