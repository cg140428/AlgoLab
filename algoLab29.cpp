#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);
	while (turn--) {
		int num;
		fscanf(f, "%d", &num);
		int i = 2;
		int prime[10000];
		int ep[10000] = { 0, };
		int index = 0;
		while (num != 1) {
			if (num % i == 0) {
				if (prime[index] != i && ep[0] != 0)
					index++;
				prime[index] = i;
				ep[index]++;
				num /= i;
			}
			else {
				i++;
			}
		}

		cout << index + 1 << " ";
		for (int j = 0; j < index + 1; j++) {
			cout << prime[j] << " " << ep[j] << " ";
		}
		cout << endl;
	}
	return 0;
}