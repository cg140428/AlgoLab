/****************************************************************************
*Problem: 두 번째 큰 수
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
		int max = 0;
		int maxSecond = 0;
		int number;
		fscanf(f, "%d", &howMany);

		for (int i = 0; i < howMany; i++) {
			fscanf(f, "%d", &number);
			if (max < number) {
				maxSecond = max;
				max = number;
			}
			else if (maxSecond < number)
				maxSecond = number;
		}
		cout << maxSecond << endl;
	}
	return 0;
}