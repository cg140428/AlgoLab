#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Score {
	int score, times;
};


int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int num;
		fscanf(f, "%d", &num);

		int studentScore[100];
		//int studentScoreIndex = 0;

		//studentScore배열에 오름차순으로 모든 성적 저장
		for (int i = 0; i < num; i++) {
			fscanf(f, "%d", &studentScore[i]);
		}
		sort(studentScore, &studentScore[num]);

		struct Score s[100];
		int sIndex = 0;
		for (int i = 0; i < num; i++) {
			if (i == 0) {
				s[sIndex].score = studentScore[i];
				s[sIndex].times = 0;
				s[sIndex].times++;
			}
			else
				if (studentScore[i - 1] == studentScore[i])
					s[sIndex].times++;
				else {
					s[++sIndex].score = studentScore[i];
					s[sIndex].times = 0;
					s[sIndex].times++;
				}
		}

		for (int i = 0; i < sIndex + 1; i++) {
			cout << s[i].score << " " << s[i].times << " ";
		}
		cout << endl;
	}
	return 0;
}