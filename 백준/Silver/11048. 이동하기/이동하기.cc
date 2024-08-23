#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int arr[1002][1002];
int N, M;
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 1;i <= N;i++) 
		for (int j = 1;j <= M;j++) 
			cin >> arr[i][j];

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			int sum = MAX(arr[i - 1][j], MAX(arr[i][j - 1], arr[i - 1][j - 1])) + arr[i][j];
			arr[i][j] = sum;
		}
	}

	cout << arr[N][M];

	return 0;
}