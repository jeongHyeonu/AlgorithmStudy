#include <iostream>
#include <queue>
#include <cstring>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;
char arr[51][51];
int ans=0;
int col, row, cx,cy,nx,ny,c_cost,n_cost;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
bool visited[51][51];

vector<pair<int, int>> v;
queue<pair<pair<int, int>,int>> q;

int main() {
	cin >> col >> row;

	for (int i = 0;i < col;i++) {
		for (int j = 0;j < row;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'L') v.push_back({ j,i });
		}
	}

	for (int i = 0;i < v.size();i++) {
		visited[v[i].second][v[i].first] = true;
		q.push({ { v[i].first,v[i].second } ,0 });
		
		while (!q.empty()) {
			cx = q.front().first.first;
			cy = q.front().first.second;
			c_cost = q.front().second;
			q.pop();
			
			for (int i = 0;i < 4;i++) {
				nx = cx + dx[i];
				ny = cy + dy[i];
				if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
				if (visited[ny][nx] || arr[ny][nx]=='W') continue;

				visited[ny][nx] = true;
				ans = MAX(ans, c_cost+1);
				q.push({ {nx,ny},c_cost + 1 });
			}
		}
		memset(visited, false, sizeof(visited));
	}
	cout << ans;
}
