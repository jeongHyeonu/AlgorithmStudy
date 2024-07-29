#include <iostream>
#include <vector>
#include <queue>
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

int N, M, X;
char arr[1001][1001];
int dists[1001][1001][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs() {
	queue<pair<pair<int, int>, bool>> q; // x, y, 벽뚫유무
	q.push({ {0,0}, 0 });
	dists[0][0][0] = dists[0][0][1] = 1;

	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		bool breakWall = q.front().second;
		q.pop();

		if (cx == M - 1 && cy == N - 1)	{
			cout << dists[cy][cx][breakWall];
			return;
		}

		for (int i = 0;i < 4;i++) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

			int n_dist = dists[cy][cx][breakWall] + 1;

			// 벽 부수고 이동
			if (arr[ny][nx] == '1' && !breakWall) {
				q.push({ {nx,ny},1 });
				dists[ny][nx][1] = n_dist;
			}

			// 칸 지나기
			if (arr[ny][nx] == '0' && dists[ny][nx][breakWall]==0) {
				q.push({ {nx,ny},breakWall });
				dists[ny][nx][breakWall] = n_dist;
			}
		}
	}

	// 도착 못함
	cout << -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++) 
			cin >> arr[i][j];

	bfs();
}

