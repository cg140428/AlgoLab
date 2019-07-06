#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int S[10000];
		//S���տ��� ������ �ֱ�
		for (int i = 0; i < 10000; i++) {
			S[i] = i;
		}

		//�׽�Ʈ���̽� ������
		int gameTurn;
		fscanf(f, "%d", &gameTurn);
		int question, strike, ball;
		for (int g = 0; g < gameTurn; g++) {
			fscanf(f, "%d %d %d", &question, &strike, &ball);

			//S ���տ��Ұ� ���̶�� ���� ���� �� ��Ʈ����ũ �� �� �� ���ϱ�
			//�̹� -1�̸� �״��� ���տ��ҷ� �Ѿ�� -1�� �ƴϸ� ����
			for (int i = 0; i < 10000; i++) {
				if (S[i] == -1)
					continue;
				else {
					//S ���տ��� �ɰ��� 0 -> 0,0,0,0
					int a_digit[4];
					a_digit[3] = i % 10;
					a_digit[2] = (i % 100) / 10;
					a_digit[1] = (i % 1000) / 100;
					a_digit[0] = i / 1000;

					//�������� �ɰ��� 1133 -> 1,1,3,3
					int q_digit[4];
					q_digit[3] = question % 10;
					q_digit[2] = (question % 100) / 10;
					q_digit[1] = (question % 1000) / 100;
					q_digit[0] = question / 1000;

					int cmp_strike = 0, cmp_ball = 0;
					//cmp_strike üũ
					for (int j = 0; j < 4; j++) {
						if (q_digit[j] == a_digit[j]) {
							cmp_strike++;
							q_digit[j] = -1;
							a_digit[j] = -1;
						}
					}

					//cmp_ball üũ
					for (int j = 0; j < 4; j++) {
						for (int k = 0; k < 4; k++) {
							if (q_digit[j] == -1)
								break;
							else if (j == k || a_digit[k] == -1)
								continue;
							else {
								if (q_digit[j] == a_digit[k]) {
									cmp_ball++;
									a_digit[k] = -1;
									break;
								}
							}
						}
					}
					//���� ���� strike ���� ���� ���� cmp_strike ����
					//���� ball ���� ���� ���� ball ���� �ٸ���
					//S ���տ��� ���Ұ� ��� -1����
					if (strike != cmp_strike || ball != cmp_ball)
						S[i] = -1;
				}
			}
		}

		int numCount = 0;
		int number[1];
		int numberIndex = 0;
		//S���տ��� -1�� �ƴ� �� ���ϱ�
		for (int i = 0; i < 10000; i++) {
			if (S[i] != -1) {
				numCount++;
				if (numberIndex == 0)
					number[numberIndex++] = S[i];
			}
		}

		//S���տ��� -1�� �ƴ� ���� �Ѱ� �������� �װ� ��
		// 0���� -2 ���
		// �������� -1 ���
		if (numCount == 1)
			cout << number[0] << endl;
		else if (numCount == 0)
			cout << "-2" << endl;
		else
			cout << "-1" << endl;

	}
	return 0;
}

