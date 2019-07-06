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

		bool primeNumberFlag = 1;

		//num의 제곱근 까지 나누어 떨어지는 수가 없으면 소수
		for (int i = 2; i * i <= num; i++) {
			if (num % i == 0) {
				cout << "0" << endl;
				primeNumberFlag = 0;
				break;
			}
		}

		if (primeNumberFlag)
			cout << "1" << endl;
	}
	return 0;
}