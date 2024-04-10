#include <iostream>
#include <cstring>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;

int N, ans = 0;
int arr[21][21];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int curX, curY;
int visited[21][21];
int sharkSize = 2;
int eatCount = 0;
bool stop = true;

queue<pair<int,int>> sharks;

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	visited[curY][curX] = 1;
	q.push({ { curX,curY },0 });

	while (!q.empty()) {
		int cy = q.front().first.second;
		int cx = q.front().first.first;
		int dist = q.front().second;

		if (arr[cy][cx] > 0 && sharkSize > arr[cy][cx] && dist==visited[curY][curX]) {
			//cout << "생선 냠냠 " << cy << cx << '\n';
			if (curY > cy || (cy == curY && cx < curX)) {
				curY = cy;
				curX = cx;
				continue;
			}
		}
		q.pop();
		//cout << "cy, cx, visited : " << cy << " " << cx << " " << visited[cy][cx] << '\n';


		for (int i = 0;i < 4;i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (visited[ny][nx] != 0) continue;
			if (arr[ny][nx] <= sharkSize) { // 자신의 크기와 작거나 같은 물고기의 경우
				if (arr[ny][nx] > 0 && arr[ny][nx] < sharkSize && stop) { // 먹을 수 있거나 지나갈 수 있는 경우
					//cout << "생선 냠냠 " << ny << nx << '\n';
					stop = false;
					curX = nx;
					curY = ny;
					visited[ny][nx] = dist + 1;
				}
				else { // 물고기 못먹을 경우
					q.push({ { nx,ny }, dist + 1 });
					visited[ny][nx] = dist + 1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) { curX = j, curY = i, arr[i][j] = 0; }
		}
	}

	while (true) {
		memset(visited, 0, sizeof(visited));
		bfs();
		int res = visited[curY][curX];
		if (!stop) {
			stop = true;
			eatCount += 1;
			arr[curY][curX] = 0; // 먹은 물고기 삭제
			if (eatCount == sharkSize) { sharkSize++, eatCount = 0; }
			ans += res;
		}
		else break;
	}

	cout << ans;
}
