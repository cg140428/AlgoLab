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

		int divisorSum = 0;
		int divisorCount = 0;

		//약수이면 더하기
		for (int i = 1; i * i <= num; i++) {
			if (i == 1) {
				divisorCount++;
				divisorSum += i;
			}
			else {
				if (num % i == 0) {
					divisorCount += 2;
					divisorSum += i;
					divisorSum += (num / i);
				}
				else
					continue;
			}
		}
		cout << divisorCount << " " << divisorSum << endl;
	}
	return 0;
}