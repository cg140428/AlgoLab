/****************************************************************************
*Problem: 개수구하기
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
		int howMany;
		int targetNumber;
		int number;
		int count = 0;

		fscanf(f, "%d %d", &howMany, &targetNumber);


		for (int i = 0; i < howMany; i++) {
			fscanf(f, "%d", &number);
			if (number == targetNumber)
				count++;
		}

		cout << count << endl;
	}
	return 0;
}