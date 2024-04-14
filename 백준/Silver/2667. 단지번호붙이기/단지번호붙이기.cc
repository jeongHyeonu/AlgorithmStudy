#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, r,c,d, ans = 0;
char arr[26][26];
vector<int> ansCounts;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};


void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({x,y});
	ans++;
	int danjiCount = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		arr[cy][cx] = '0';
		q.pop();
		//cout << "cx , cy : " << cx << cy << '\n';

		for (int i = 0;i < 4;i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (arr[ny][nx] == '1') {
				q.push({ nx,ny });
				arr[ny][nx] = '0';
				danjiCount++;
			}
		}
	}

	ansCounts.push_back(danjiCount);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;


	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			if (arr[i][j] == '0') continue;
			else bfs(i, j);
		}
	}

	sort(ansCounts.begin(), ansCounts.end());

	cout << ans;
	for (int i = 0;i < ansCounts.size();i++) {
		cout << '\n';
		cout << ansCounts[i];
	}
}
