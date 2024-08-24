#include <iostream>
#define INF 99999999
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

int N, M;
int arr[402][402];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = INF;
		}
	}

	int s, e, w;
	for (int i = 0;i < M;i++) {
		cin >> s >> e >> w;
		arr[s][e] = w;
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			for (int k = 1;k <= N;k++) {
				arr[j][k] = MIN(arr[j][k],(arr[j][i]+arr[i][k]));
			}
		}
	}

	int ans = INF;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (i == j) continue;
			ans = MIN(ans, arr[i][j] + arr[j][i]);
		}
	}

	if (ans >= INF) cout << -1;
	else cout << ans;

	return 0;
}