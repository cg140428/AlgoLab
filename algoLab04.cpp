/****************************************************************************
*Problem: 보드게임
*****************************************************************************
*
*국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
*20171661 이다은
*
*****************************************************************************/
#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		int sumA, sumB;
		int scoreA, scoreB;

		fscanf(f, "%d %d", &sumA, &sumB);
		scoreA = (2 * (sumA / 16)) + (sumA % 16);
		scoreB = (2 * (sumB / 16)) + (sumB % 16);

		if (scoreA > scoreB)
			cout << scoreA << endl;
		else
			cout << scoreB << endl;

	}
	return 0;
}