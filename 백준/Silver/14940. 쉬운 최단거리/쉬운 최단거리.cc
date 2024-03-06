#include <iostream>
#include <queue>
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

struct coord {
    int x;
    int y;
    int cnt;
};

int n, m, dest_x, dest_y;
int arr[1002][1002];
int ans[1002][1002];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

queue<pair<int,int>> q;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[i][j] = -1;
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				q.push({i,j});
				ans[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.second + dx[i];
			int ny = cur.first + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (ans[ny][nx] != -1) continue;
			if (arr[ny][nx] == 0) continue;
			ans[ny][nx] = ans[cur.first][cur.second] + 1;
			q.push({ ny,nx });
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) cout << 0 << ' ';
			else cout << ans[i][j] << ' ';
		}
		cout << "\n";
	}
}