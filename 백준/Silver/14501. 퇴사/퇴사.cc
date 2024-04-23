#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int tArr[16];
int pArr[16];
int res[16];
int N, T, P;
int ans = 0;

int main() {
	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> tArr[i] >> pArr[i];
	}

	for (int i = 0;i <= N;i++) {
		ans = MAX(ans, res[i]);
		res[i] = MAX(ans, res[i]);
		if (tArr[i] + i > N) continue;
		res[tArr[i]+i] = MAX(res[tArr[i]+i], pArr[i]+res[i]);
	}

	cout << ans;
}
