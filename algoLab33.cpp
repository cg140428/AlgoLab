#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);
	while (turn--) {
		int sequence;
		fscanf(f, "%d", &sequence);

		int sequArray[256];
		int tempNum;
		for (int i = 0; i < sequence; i++) {
			fscanf(f, "%d", &tempNum);
			sequArray[i] = tempNum;
		}

		int k;
		fscanf(f, "%d", &k);
		int sum = 0;
		cout << sequence - k + 1 << " ";
		for (int i = 0; i < sequence - k + 1; i++) {
			for (int j = i; j < i + k; j++) {
				sum += sequArray[j];
			}
			cout << sum / k << " ";
			sum = 0;
		}
		cout << endl;
	}
	return 0;
}