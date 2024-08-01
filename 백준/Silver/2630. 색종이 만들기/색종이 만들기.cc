#include <iostream>
#include <vector>
#include <queue>
#define INF 99999999
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

int N;
int blueCnt=0, whiteCnt=0;
int arr[130][130];

bool checkArr(int size, int x, int y) {
	int temp = arr[y][x];

	for (int i = y;i < y+size;i++)
		for (int j = x;j < x+size;j++)
			if (arr[i][j] != temp) return false;

	return true;
}

void dc(int size, int x, int y) {
	int temp = arr[y][x];

	for (int i = y;i < y+size;i++)
		for (int j = x;j < x+size;j++)
			if (arr[i][j] != temp) {
				dc(size / 2, x, y);
				dc(size / 2, x, y + size / 2);
				dc(size / 2, x + size / 2, y);
				dc(size / 2, x + size / 2, y + size / 2);
				return;
			}

	if (temp == 1) blueCnt++;
	else whiteCnt++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N;

	for (int i = 0;i < N;i++) 
		for (int j = 0;j < N;j++) 
			cin >> arr[i][j];

	dc(N,0,0);

	cout << whiteCnt << '\n' << blueCnt;
}

