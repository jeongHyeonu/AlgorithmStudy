#include <iostream>
#include <set>
#define MAX(a,b)(((a)>(b))?(a):(b))
#define INF 9999999
using namespace std;

int dp[110][100010];
int N, K;
int W[101], V[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

	for (int i = 1;i <= N;i++) {
		cin >> W[i] >> V[i];
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= K;j++) {
			if (j >= W[i]) {
				dp[i][j] = MAX(dp[i-1][j],dp[i-1][j-W[i]]+V[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];
}
