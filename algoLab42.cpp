#include <iostream>
#include <cstdio>

using namespace std;
void checkNum(int** row, int** col, int* diagonal1, int* diagonal2, int* side, int num);
void checkBingo(int** row, int** col, int* diagonal1, int* diagonal2, int* side, int& bingoFlag);

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);
	while (turn--) {
		//빙고판에 숫자 넣기
		int bingo[5][5];

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				fscanf(f, "%d", &bingo[i][j]);
				//printf("%d ", bingo[i][j]);
			}
			//printf("\n");
		}

		//경우의 수
		int** row = new (int*[5]);
		for (int i = 0; i < 5; i++)
			row[i] = new int[5];

		int** col = new (int*[5]);
		for (int i = 0; i < 5; i++)
			col[i] = new int[5];

		int* diagonal1 = new int[5];

		int* diagonal2 = new int[5];

		int* side = new int[4];

		//경우의 수 초기화
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				row[i][j] = bingo[i][j];
			}
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				col[i][j] = bingo[j][i];
			}
		}

		for (int i = 0; i < 5; i++) {
			diagonal1[i] = bingo[i][i];
		}

		for (int i = 0; i < 5; i++) {
			diagonal2[i] = bingo[i][4 - i];
		}

		side[0] = bingo[0][0];
		side[1] = bingo[0][4];
		side[2] = bingo[4][0];
		side[3] = bingo[4][4];

		int bingoFlag = 1;
		int numIndex = 0;

		//해당 숫자 표기
		checkNum(row, col, diagonal1, diagonal2, side, 0);

		//숫자 받기
		while (bingoFlag) {
			int num;
			fscanf(f, "%d", &num);
			checkNum(row, col, diagonal1, diagonal2, side, num);
			checkBingo(row, col, diagonal1, diagonal2, side, bingoFlag);
			numIndex++;
		}

		cout << numIndex << endl;

		int trashNum;
		for (int i = 0; i < 75 - numIndex; i++) {
			fscanf(f, "%d", &trashNum);
		}

	}
	return 0;
}

void checkNum(int** row, int** col, int* diagonal1, int* diagonal2, int* side, int num) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (row[i][j] == num) {
				row[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (col[i][j] == num) {
				col[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		if (diagonal1[i] == num) {
			diagonal1[i] = -1;
		}
	}

	for (int i = 0; i < 5; i++) {
		if (diagonal2[i] == num) {
			diagonal2[i] = -1;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (side[i] == num) {
			side[i] = -1;
		}
	}
}

void checkBingo(int** row, int** col, int* diagonal1, int* diagonal2, int* side, int& bingoFlag) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (row[i][j] != -1) {
				break;
			}
			else if (j == 4 && row[i][j] == -1)
				bingoFlag = 0;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (col[i][j] != -1) {
				break;
			}
			else if (j == 4 && col[i][j] == -1)
				bingoFlag = 0;
		}
	}

	for (int i = 0; i < 5; i++) {
		if (diagonal1[i] != -1) {
			break;
		}
		else if (i == 4 && diagonal1[i] == -1)
			bingoFlag = 0;
	}

	for (int i = 0; i < 5; i++) {
		if (diagonal2[i] != -1) {
			break;
		}
		else if (i == 4 && diagonal2[i] == -1)
			bingoFlag = 0;
	}

	for (int i = 0; i < 4; i++) {
		if (side[i] != -1) {
			break;
		}
		else if (i == 3 && side[i] == -1)
			bingoFlag = 0;
	}
}