#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int N;
long long B;
int arr[5][5];
int ans[5][5];

void multi_mat(int a[5][5], int b[5][5]) {
	int temp[5][5] = {};
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			for (int k = 0;k < N;k++) temp[i][j] += (a[i][k] * b[k][j]);
			temp[i][j] %= 1000;
		}
	}

	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			a[i][j] = temp[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> B;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
		ans[i][i] = 1;
	}

	while (B>0) {
		if (B % 2 == 1) multi_mat(ans,arr);
		multi_mat(arr,arr);
		B /= 2;
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}