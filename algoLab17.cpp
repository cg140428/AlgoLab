#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int absolSub(int& a, int& x);
double getEucDistance(int& x1, int& y1, int& x2, int& y2);
int getRecDistance(int& x1, int& y1, int& x2, int& y2);

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		//�簢��
		int x1, y1;
		int x2, y2;
		fscanf(f, "%d %d %d %d", &x1, &y1, &x2, &y2);

		//��ǥ
		int a, b;
		fscanf(f, "%d %d", &a, &b);

		//�簢���� ���� �����Ͽ� 9�������� ������. ���� ������ 1�����̶� Ī��
		if (a >= x1 && a <= x2) {
			//��ǥ�� �簢�� �ȿ� ���� ��� (5����)
			if (b >= y1 && b <= y2)
				cout << "0 0" << endl;
			else {
				//8����
				if (b < y1) {
					cout << getEucDistance(a, b, a, y1) << " ";
					cout << absolSub(b, y1) << endl;
				}
				//2����
				else {
					cout << getEucDistance(a, b, a, y2) << " ";
					cout << absolSub(b, y2) << endl;
				}
			}
		}
		else if (a < x1) {
			//4����
			if (b >= y1 && b <= y2) {
				cout << getEucDistance(a, b, x1, b) << " ";
				cout << absolSub(a, x1) << endl;
			}
			//7����
			else if (b < y1) {
				cout << getEucDistance(a, b, x1, y1) << " ";
				cout << getRecDistance(a, b, x1, y1) << endl;
			}
			//1����
			else {
				cout << getEucDistance(a, b, x1, y2) << " ";
				cout << getRecDistance(a, b, x1, y2) << endl;
			}

		}
		else {
			//6����
			if (b >= y1 && b <= y2) {
				cout << getEucDistance(a, b, x2, b) << " ";
				cout << absolSub(a, x2) << endl;
			}
			//9����
			else if (b < y1) {
				cout << getEucDistance(a, b, x2, y1) << " ";
				cout << getRecDistance(a, b, x2, y1) << endl;
			}
			//3����
			else {
				cout << getEucDistance(a, b, x2, y2) << " ";
				cout << getRecDistance(a, b, x2, y2) << endl;
			}
		}
	}
	return 0;
}

int absolSub(int& a, int& x) {
	int sub = a - x;
	if (sub < 0)
		return -sub;
	else
		return sub;
}

double getEucDistance(int& x1, int& y1, int& x2, int& y2) {
	return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

int getRecDistance(int& x1, int& y1, int& x2, int& y2) {
	int recDistance[2];
	recDistance[0] = x2 - x1;
	recDistance[1] = y2 - y1;
	int recDistanceSum = 0;

	for (int i = 0; i < sizeof(recDistance) / sizeof(int); i++) {
		if (recDistance[i] < 0) {
			recDistanceSum += -recDistance[i];
		}
		else
			recDistanceSum += recDistance[i];
	}

	return recDistanceSum;
}