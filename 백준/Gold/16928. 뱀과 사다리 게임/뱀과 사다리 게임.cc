#include <iostream>
#include <queue>
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

int N, M;
int arr[102] = { 0, };
int visited[102] = { 0, };

void bfs() {
	queue<pair<int,int>> q;
	q.push({1,0});

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == 100) {
			cout << cnt << '\n';
			exit(0);
		}

		for (int i = 1;i <= 6;i++) {
			int next = cur + i;
			if (next > 100 || visited[next]) continue;

			if (arr[next] > 0) next = arr[next];
			q.push({ next, cnt + 1 });
			visited[next] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int x, y, u, v;
	for (int i = 0;i < N;i++) {
		cin >> x >> y;
		arr[x] = y;
	}
	for (int i = 0;i < M;i++) {
		cin >> u >> v;
		arr[u] = v;
	}

	bfs();
}