#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, L, R,nx,ny,diff,cx,cy,total,cnt=0,countryCnt=0;
int maps[51][51];
bool visited[51][51];
queue<pair<int,int>> q;
queue<pair<int, int>> check_q;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool isConnected;

void bfs(int y, int x){
	if (visited[y][x]) return;
	visited[y][x] = true;
	q.push({y,x});
	check_q.push({ y,x });
	total = maps[y][x];
	countryCnt = 1;

	while (!q.empty()) {
		cx = q.front().second;
		cy = q.front().first;
		q.pop();
		for (int i = 0;i < 4;i++) {
			nx = cx+dx[i];
			ny = cy+dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			diff = abs(maps[cy][cx] - maps[ny][nx]);
			if (!visited[ny][nx] && diff>=L && diff<=R) {
				visited[ny][nx] = true;
				total += maps[ny][nx];
				q.push({ ny,nx });
				check_q.push({ ny,nx });
				isConnected = true;
				countryCnt++;
			}
		}
	}

	while (!check_q.empty()) {
		maps[check_q.front().first][check_q.front().second] = total / countryCnt;
		check_q.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0;i < N;i++)for (int j = 0;j < N;j++)  cin >> maps[i][j];

	while (true) {
		isConnected = false;
		for (int i = 0;i < N;i++) for (int j = 0;j < N;j++) bfs(i,j);
		if (!isConnected) break;
		cnt++;
		memset(visited, false, sizeof(visited));
	}
	
	cout << cnt;

	return 0;
}
