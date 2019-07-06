#include <iostream>
#include <cstdio>

using namespace std;
int elementC(int arr1[][100], int arr2[][100], int i, int j, int colA);

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);
	while (turn--) {
		int A[100][100];
		int B[100][100];
		//int C[100][100];
		int rowA, colA;
		int rowB, colB;
		//int rowC, colC;
		fscanf(f, "%d %d %d", &rowA, &colA, &colB);
		rowB = colA;
		//rowC = rowA;
		//colC = colB;

		int tempNum;
		for (int i = 0; i < rowA; i++) {
			for (int j = 0; j < colA; j++) {
				fscanf(f, "%d", &tempNum);
				A[i][j] = tempNum;
			}
		}
		for (int i = 0; i < rowB; i++) {
			for (int j = 0; j < colB; j++) {
				fscanf(f, "%d", &tempNum);
				B[i][j] = tempNum;
			}
		}
		for (int i = 0; i < rowA; i++) {
			for (int j = 0; j < colB; j++) {
				cout << elementC(A, B, i, j, colA) << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

int elementC(int arr1[][100], int arr2[][100], int i, int j, int colA) {
	int C = 0;
	for (int num = 0; num < colA; num++) {
		C += arr1[i][num] * arr2[num][j];
	}
	return C;
}