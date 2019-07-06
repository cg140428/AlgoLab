#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);
	while (turn--) {
		int row, col;
		fscanf(f, "%d %d", &row, &col);
		int A[100][100];
		int tempNum;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				fscanf(f, "%d", &tempNum);
				A[i][j] = tempNum;
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				fscanf(f, "%d", &tempNum);
				cout << A[i][j] + tempNum << " ";

			}
			cout << endl;
		}
	}
	return 0;
}