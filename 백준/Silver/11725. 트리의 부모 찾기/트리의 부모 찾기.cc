#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int parents[100001];
bool visited[100001] = { 0, };
vector<int> edges[100001];

void bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0;i < edges[node].size();i++) {
			int n_node = edges[node][i];

			if (visited[n_node]) continue;
			visited[n_node] = true;
			parents[n_node] = node;
			q.push( n_node );
		}
	}
}

int main() {
	int N, s,e;
	cin >> N;
	for (int i = 0;i < N - 1;i++) {
		cin >> s >> e;
		edges[s].push_back(e);
		edges[e].push_back(s);
	}

	bfs();

	for (int i = 2;i <= N;i++) cout << parents[i] << '\n';
}