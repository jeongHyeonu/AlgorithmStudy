#include <iostream>
#include <cstring>
using namespace std;

int T, N, M;
int arr[21];
int dp[10001] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	
	while (T--) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;

		cin >> N;
		for (int i = 0;i < N;i++) cin >> arr[i];

		cin >> M;

		// arr[i] 의 동전으로, 금액 j를 만들 수 있는 방법 카운트
		for (int i = 0;i < N;i++) {
			for (int j = arr[i];j <= M;j++) {
				dp[j] += dp[j - arr[i]];
			}
		}

		cout << dp[M] << '\n';
	}
	return 0;
}

