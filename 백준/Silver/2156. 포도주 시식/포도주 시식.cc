#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;
int N;

int dp[10003];
int a[10003];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1;i <= N;i++) cin >> a[i];

	a[0] = 0;
	dp[0] = a[0]; // 2+3
	dp[1] = a[1]; // 1+2
	dp[2] = a[1] + a[2]; // 1+3

	for (int i = 3;i <= N;i++) {
		dp[i] = MAX(dp[i - 3] + a[i - 1] + a[i], MAX(dp[i - 2] + a[i], dp[i - 1]));
	}

	int ans = dp[N];
	cout << ans;
}