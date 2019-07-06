#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
void display(unsigned int arr[], int num);

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		unsigned int A[132] = { 0, };
		unsigned int B[132] = { 0, };
		unsigned int mul[132] = { 0, };
		unsigned int sum[132] = { 0, };

		int num;
		int bit;
		int max = 0;

		fscanf(f, "%d", &num);
		for (int i = 0; i < num; i++) {
			fscanf(f, "%d", &bit);
			A[bit] = 1;
			if (bit > max)
				max = bit;
		}

		fscanf(f, "%d", &num);
		for (int i = 0; i < num; i++) {
			fscanf(f, "%d", &bit);
			B[bit] = 1;
			if (bit > max)
				max = bit;
		}

		//교집합, 합집합, 차집합 연산
		for (int i = 0; i < max + 1; i++) {
			mul[i] = A[i] & B[i];
			sum[i] = A[i] | B[i];
			if (A[i] == 1 && B[i] == 1)
				A[i] = 0;
		}

		display(mul, max + 1);
		display(sum, max + 1);
		display(A, max + 1);
	}
	return 0;
}

//집합원소 보여주는 함수
void display(unsigned int arr[], int num) {
	unsigned int numbers[132];
	int numbersIndex = 0;
	for (int i = 0; i < num; i++) {
		if (arr[i] == 1)
			numbers[numbersIndex++] = i;
	}
	sort(numbers, &numbers[numbersIndex]);

	cout << numbersIndex << " ";
	for (int i = 0; i < numbersIndex; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;
}