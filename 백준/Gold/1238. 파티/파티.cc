#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 9999999
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int N, M, X;
int dists[1002];
vector <pair<int,int>> v[1002];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start) {
	memset(dists, INF, sizeof(dists));
	pq.push({ 0, start });
	dists[start] = 0;

	while (!pq.empty()) {
		int c_node = pq.top().second;
		int c_cost = pq.top().first;
		pq.pop();

		if (c_cost > dists[c_node]) continue;

		for (int i = 0;i < v[c_node].size();i++) {
			int n_node = v[c_node][i].first;
			int n_cost = v[c_node][i].second + c_cost;
			if (dists[n_node] > n_cost) {
				dists[n_node] = n_cost;
				pq.push({ n_cost , n_node });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> X;

	int s1, s2, t;
	for (int i = 0;i < M;i++) {
		cin >> s1 >> s2 >> t;
		v[s1].push_back({ s2,t });
	}

	int result = 0;
	int ans = 0;
	for (int i = 1;i <= N;i++) {
		dijkstra(i);
		result = dists[X];
		dijkstra(X);
		result += dists[i];
		ans = MAX(result, ans);
	}

	cout << ans;
}

