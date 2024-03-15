#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define INF 99999
#define MIN(a,b)(((a)<(b))?(a):(b))

using namespace std;
int dp[10002] = {};
vector<pair<int,int>> dist_v[10002];
int N, D, from, to, dist;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> D;
	
	for (int i = 0;i < N;i++) {
		dp[i] = INF;
		cin >> from >> to >> dist;
		if (to > D || to - from < dist) continue;
		dist_v[to].push_back({ from,dist });
	}

	dp[0] = 0;

	for (int i = 1;i < D + 1;i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 0;j < dist_v[i].size();j++) {
			dp[i] = MIN(dp[i], dp[dist_v[i][j].first] + dist_v[i][j].second);
		}
	}

	cout << dp[D];

	return 0;
}