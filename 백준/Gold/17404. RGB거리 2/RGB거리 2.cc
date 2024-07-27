#include <iostream>
#include <vector>
#include <queue>
#define MIN(a,b)(((a)<(b))?(a):(b))
#define INF 9999999
using namespace std;

int N;
int arr[1001][3];
int ans = INF;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	
	for (int i = 0;i < N;i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

	for (int color = 0; color < 3; color++) {

		int dp[1001][3];

		for (int c = 0;c < 3;c++) {
			if (c == color) dp[0][c] = arr[0][c];
			else dp[0][c] = INF;
		}

		for (int i = 1;i < N;i++) {
			dp[i][0] = MIN(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
			dp[i][1] = MIN(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
			dp[i][2] = MIN(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
		}

		for (int i = 0;i < 3;i++) {
			if (color != i) ans = MIN(ans, dp[N - 1][i]);
		}
	}


	cout << ans;

}

