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
		//S집합원소 데이터 넣기
		for (int i = 0; i < 10000; i++) {
			S[i] = i;
		}

		//테스트케이스 데이터
		int gameTurn;
		fscanf(f, "%d", &gameTurn);
		int question, strike, ball;
		for (int g = 0; g < gameTurn; g++) {
			fscanf(f, "%d %d %d", &question, &strike, &ball);

			//S 집합원소가 답이라고 가정 했을 때 스트라이크 수 볼 수 구하기
			//이미 -1이면 그다음 집합원소로 넘어가고 -1이 아니면 실행
			for (int i = 0; i < 10000; i++) {
				if (S[i] == -1)
					continue;
				else {
					//S 집합원소 쪼개기 0 -> 0,0,0,0
					int a_digit[4];
					a_digit[3] = i % 10;
					a_digit[2] = (i % 100) / 10;
					a_digit[1] = (i % 1000) / 100;
					a_digit[0] = i / 1000;

					//질문숫자 쪼개기 1133 -> 1,1,3,3
					int q_digit[4];
					q_digit[3] = question % 10;
					q_digit[2] = (question % 100) / 10;
					q_digit[1] = (question % 1000) / 100;
					q_digit[0] = question / 1000;

					int cmp_strike = 0, cmp_ball = 0;
					//cmp_strike 체크
					for (int j = 0; j < 4; j++) {
						if (q_digit[j] == a_digit[j]) {
							cmp_strike++;
							q_digit[j] = -1;
							a_digit[j] = -1;
						}
					}

					//cmp_ball 체크
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
					//만약 받은 strike 수와 직접 구한 cmp_strike 수나
					//받은 ball 수와 직접 구한 ball 수가 다르면
					//S 집합원소 원소값 대신 -1저장
					if (strike != cmp_strike || ball != cmp_ball)
						S[i] = -1;
				}
			}
		}

		int numCount = 0;
		int number[1];
		int numberIndex = 0;
		//S집합에서 -1이 아닌 수 구하기
		for (int i = 0; i < 10000; i++) {
			if (S[i] != -1) {
				numCount++;
				if (numberIndex == 0)
					number[numberIndex++] = S[i];
			}
		}

		//S집합에서 -1이 아닌 수가 한개 남았으면 그게 답
		// 0개면 -2 출력
		// 여러개면 -1 출력
		if (numCount == 1)
			cout << number[0] << endl;
		else if (numCount == 0)
			cout << "-2" << endl;
		else
			cout << "-1" << endl;

	}
	return 0;
}

