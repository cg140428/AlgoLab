/****************************************************************************
*Problem: �� ��° ū ��
*****************************************************************************
*
*���δ��б� ����Ʈ�������մ��� ����Ʈ�����к� 2�г�
*20171661 �̴���
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