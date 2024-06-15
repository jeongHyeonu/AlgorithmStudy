#include <iostream>
#include <vector>
#include <queue>
#define INF 999999
#define MAX 20002
using namespace std;

int V, k;
int dist[MAX];
vector<pair<int, int>> vec[MAX];

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	dist[k] = 0;
	pq.push({ 0,k });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (int i = 0;i < vec[node].size();i++) {
			int next_cost = vec[node][i].second + cost;
			int next_node = vec[node][i].first;
			if (dist[next_node] > next_cost) {
				dist[next_node] = next_cost;
				pq.push({ -next_cost, next_node });
			}
		}
	}
	for (int i = 1;i <= V;i++) { 
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int u, e, v, w;
	cin >> V >> e;
	cin >> k;

	for (int i = 0;i < e;i++) {
		cin >> u >> v >> w;
		vec[u].push_back({ v,w });
	}
	for (int i = 1;i <= V;i++) dist[i] = INF;

	dijkstra();
	return 0;
}