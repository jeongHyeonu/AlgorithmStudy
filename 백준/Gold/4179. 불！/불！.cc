#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C;
int cx, cy, nx, ny, c_time, n_time,cnt=0;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char arr[1001][1001];
int fire_dist[1001][1001];
int jihun_dist[1001][1001];
bool isPossible;
queue<pair<int, int>> jihun_q;
queue<pair<int, int>> fire_q;

void bfs() {
	while (!fire_q.empty()) {
		cx = fire_q.front().first;
		cy = fire_q.front().second;
		fire_q.pop();

		for (int i = 0;i < 4;i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= C || nx < 0 || ny >= R || ny < 0) continue;
			if (fire_dist[ny][nx] >= 0) continue;
			if (arr[ny][nx] == '#') continue;
			fire_q.push({ nx,ny });
			fire_dist[ny][nx] = fire_dist[cy][cx] + 1;
		}
	}
	while (!jihun_q.empty()) {
		cx = jihun_q.front().first;
		cy = jihun_q.front().second;
		jihun_q.pop();

		for (int i = 0;i < 4;i++) {
			nx = cx + dx[i];
			ny = cy + dy[i];
			if (nx >= C || nx < 0 || ny >= R || ny < 0) {
				cout << jihun_dist[cy][cx] + 1;
				return;
			}
			if (fire_dist[ny][nx] != -1 && fire_dist[ny][nx] <= jihun_dist[cy][cx]+1) continue;
			if (jihun_dist[ny][nx] >= 0) continue;
			if (arr[ny][nx] == '#') continue;
			jihun_q.push({ nx,ny });
			jihun_dist[ny][nx] = jihun_dist[cy][cx] + 1;
		}
	}
	cout << "IMPOSSIBLE";
	return;
}

int main() {
	cin >> R >> C;

	memset(jihun_dist, -1, sizeof(jihun_dist));
	memset(fire_dist, -1, sizeof(fire_dist));

	for (int i = 0;i < R;i++) for (int j = 0;j < C;j++) {
		cin >> arr[i][j];
		if (arr[i][j] == 'J') {
			jihun_q.push({ j,i });
			jihun_dist[i][j] = 0;
		}
		else if (arr[i][j] == 'F') {
			fire_q.push({ j,i });
			fire_dist[i][j] = 0;
		}
	}
	
	bfs();
}
