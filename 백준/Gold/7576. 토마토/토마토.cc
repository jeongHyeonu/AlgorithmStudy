#include <iostream>
#include <queue>
#include <algorithm>
#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;

int N, M, ans = 0;
int arr[1001][1001];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
queue<pair<pair<int, int>, int>> q;

void bfs() {
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cnt = q.front().second;
		ans = MAX(cnt, ans);
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = 1;
				q.push({ {nx,ny},cnt + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) q.push({ {j,i}, 0 });
		}
	}

	bfs();

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			if (arr[i][j] == 0) { cout << "-1"; exit(0); }
		}
	}

	cout << ans;
}
