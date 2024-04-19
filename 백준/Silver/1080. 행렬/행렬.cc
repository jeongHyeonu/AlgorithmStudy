#include <iostream>
#define CHANGE(a)((a)=='0')?((a)='1'):((a)='0')
using namespace std;
char arr1[51][51];
char arr2[51][51];
int cnt;
int N, M;

void change(int x, int y) {
	cnt++;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			CHANGE(arr1[y+i][x+j]);
		}
	}
}

int solve() {
	for (int i = 0;i < N-2;i++) {
		for (int j = 0;j < M - 2;j++) {
			if (arr1[i][j] != arr2[i][j]) change(j, i);
		}
	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (arr1[i][j] != arr2[i][j]) return -1;
		}
	}
	return cnt;
}

int main() {
	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr1[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr2[i][j];
		}
	}

	cout << solve();
}
