#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int num;
		fscanf(f, "%d", &num);

		int hammingNum[1351];
		int hammingNumIndex = 0;
		int hammingCandidate1, hammingCandidate2, hammingCandidate3;

		hammingNum[hammingNumIndex++] = 1;

		if (num == 1)
			cout << hammingNum[num - 1] << endl;
		else {
			for (int i = 0; i < num; i++) {
				for (int j = 0; j < hammingNumIndex; j++) {
					if (hammingNum[j] * 2 > hammingNum[hammingNumIndex - 1]) {
						hammingCandidate1 = hammingNum[j] * 2;
						break;
					}
				}

				for (int j = 0; j < hammingNumIndex; j++) {
					if (hammingNum[j] * 3 > hammingNum[hammingNumIndex - 1]) {
						hammingCandidate2 = hammingNum[j] * 3;
						break;
					}
				}

				for (int j = 0; j < hammingNumIndex; j++) {
					if (hammingNum[j] * 5 > hammingNum[hammingNumIndex - 1]) {
						hammingCandidate3 = hammingNum[j] * 5;
						break;
					}
				}

				if (hammingCandidate1 <= hammingCandidate2 && hammingCandidate1 <= hammingCandidate3)
					hammingNum[hammingNumIndex++] = hammingCandidate1;
				else if (hammingCandidate2 <= hammingCandidate1 && hammingCandidate2 <= hammingCandidate3)
					hammingNum[hammingNumIndex++] = hammingCandidate2;
				else
					hammingNum[hammingNumIndex++] = hammingCandidate3;
			}

			cout << hammingNum[num - 1] << endl;
		}

	}
	return 0;
}