#include <iostream>
#define DIV 9901

using namespace std;

int dp[100001][3];

int N;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	dp[0][0] = dp[0][1] = dp[0][2] = 1;

	for (int i = 1;i < N;i++) {
		dp[i][0] += (dp[i - 1][1] + dp[i - 1][2]) % DIV;
		dp[i][1] += (dp[i - 1][0] + dp[i - 1][2]) % DIV;
		dp[i][2] += (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % DIV;
	}

	cout << (dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2]) % DIV;
}