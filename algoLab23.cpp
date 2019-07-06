#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Number {
	int number, times;
};

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int num;
		fscanf(f, "%d", &num);

		//배열 생성 후 모든 숫자 저장, 오름차순 정렬
		int numbers[100];
		for (int i = 0; i < num; i++) {
			fscanf(f, "%d", &numbers[i]);
		}
		sort(numbers, &numbers[num]);

		struct Number n[100];

		int nIndex = 0;
		for (int i = 0; i < num; i++) {
			if (i == 0) {
				n[nIndex].number = numbers[i];
				n[nIndex].times = 0;
				n[nIndex].times++;
			}
			else {
				if (numbers[i - 1] == numbers[i])
					n[nIndex].times++;
				else {
					n[++nIndex].number = numbers[i];
					n[nIndex].times = 0;
					n[nIndex].times++;
				}
			}
		}

		//최빈값의 개수
		int maxCount = 0;
		//최빈값이 나타난 횟수(최빈값)
		int mode = 0;
		for (int i = 0; i < nIndex + 1; i++) {
			if (n[i].times > mode)
				mode = n[i].times;
		}

		for (int i = 0; i < nIndex + 1; i++) {
			if (n[i].times == mode)
				maxCount++;
		}

		cout << maxCount << " " << mode << " ";
		for (int i = 0; i < nIndex + 1; i++) {
			if (n[i].times == mode) {
				cout << n[i].number << " ";
			}
		}

		cout << endl;
	}
	return 0;
}