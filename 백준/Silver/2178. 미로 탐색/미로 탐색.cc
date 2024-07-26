#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int arr[101][101];
bool visited[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs() {
	queue<pair<int, pair<int, int>>> q;
	q.push({ 1,{0,0} });
	visited[0][0] = true;

	while (!q.empty()) {
		int cost = q.front().first;
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		q.pop();
		if (cx == M - 1 && cy == N - 1) { cout << cost; return; }

		for (int i = 0;i < 4;i++) {
			int n_cost = cost + 1;
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (visited[ny][nx] || arr[ny][nx]==0) continue;

			visited[ny][nx] = true;
			q.push({ n_cost, {nx,ny} });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	
	char temp;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> temp;
			arr[i][j] = temp - '0';
		}
	}
	bfs();
}

