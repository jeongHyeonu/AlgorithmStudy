#include <iostream>
#include <cstring>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;

int N, M, ans = 0;
int arr[51][51];
int dx[] = {-1,-1,-1, 0,0, 1,1,1};
int dy[] = {-1, 0, 1,-1,1,-1,0,1};
bool visited[51][51];

queue<pair<int,int>> sharks;

int bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> shark_bfs;
	memset(visited, false, sizeof(visited));
	visited[y][x] = true;
	shark_bfs.push({ { x,y },0 });

	while (!shark_bfs.empty()) {
		int cy = shark_bfs.front().first.second;
		int cx = shark_bfs.front().first.first;
		int dist = shark_bfs.front().second;
		if (arr[cy][cx] == 1) { return dist; }
		shark_bfs.pop();

		//cout << "cy, cx, dist : " << cy << " " << cx << " " << dist << '\n';
		for (int i = 0;i < 8;i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (visited[ny][nx] == true) continue;

			visited[ny][nx] = true;
			shark_bfs.push({{ nx,ny }, dist + 1});
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) sharks.push({ i,j });
		}
	}

	while (!sharks.empty()) {
		ans = MAX(ans,bfs(sharks.front().second, sharks.front().first));
		sharks.pop();
	}

	cout << ans;
}
