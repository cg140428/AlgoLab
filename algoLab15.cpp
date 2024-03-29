#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double getLength(int& x1, int& y1, int& x2, int& y2);
void getMax(int arr[]);
void triangle(int a, int b, int c);

int main(void) {
	FILE* f;
	f = fopen("input.txt", "r");

	int turn;
	fscanf(f, "%d", &turn);

	while (turn--) {
		//파일 읽어서 좌표를 배열에 저장
		int off[6];
		for (int i = 0; i < sizeof(off) / sizeof(int); i++) {
			fscanf(f, "%d", &off[i]);
		}

		//삼각형이 아닌 경우: 세 점이 모두 같은 선분 선상에 있을 때
		double m1, m2;
		bool vert1 = false, vert2 = false;
		//분모가 0일 때 런타임에러 방지
		if (off[2] - off[0] == 0)
			vert1 = true;
		else
			m1 = double(off[3] - off[1]) / (off[2] - off[0]);

		if (off[4] - off[2] == 0)
			vert2 = true;
		else
			m2 = double(off[5] - off[3]) / (off[4] - off[2]);
		if (m1 == m2 || (vert1 && vert2 == true))
			cout << "0" << endl;

		//삼각형인 경우
		else {

			int len[3];
			//선분의 길이의 제곱 구하기
			len[0] = getLength(off[0], off[1], off[2], off[3]);
			len[1] = getLength(off[2], off[3], off[4], off[5]);
			len[2] = getLength(off[4], off[5], off[0], off[1]);

			//오름차순으로 정렬
			getMax(len);

			//직각 둔각 예각 삼각형 판별
			triangle(len[0], len[1], len[2]);


		}
	}

	return 0;
}

//getLength() _ 두 좌표로 선분 길이를 구하는 함수
double getLength(int& x1, int& y1, int& x2, int& y2) {
	return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

//getMax()_세 변중 가장 길이가 긴 변 칮기
void getMax(int arr[]) {
	int temp;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//직각, 둔각, 예각 삼각형 판별
void triangle(int a, int b, int c) {
	if (a + b == c)
		cout << "1" << endl;
	else if (a + b < c)
		cout << "2" << endl;
	else
		cout << "3" << endl;
}
