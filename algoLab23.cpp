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

		//�迭 ���� �� ��� ���� ����, �������� ����
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

		//�ֺ��� ����
		int maxCount = 0;
		//�ֺ��� ��Ÿ�� Ƚ��(�ֺ�)
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