#include <iostream>
#include <vector>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))
#define MIN(a,b)(((a)<(b))?(a):(b))
#define INF 999999999

using namespace std;
int N, M, ans = INF, emptyCnt = 0;
int arr[51][51];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };
bool isSelected[11];
vector<pair<int, int>> selected;
vector<pair<int, int>> virus;

int simulate() {
	queue<pair<int, pair<int, int>>> q;
	bool visited[51][51] = { false, };
	int newArr[51][51];
	int totalCnt = 0;
	int infectedCnt = 0;

	for (int i = 0;i < N;i++) 
		for (int j = 0;j < N;j++) 
			newArr[i][j] = arr[i][j];

	for (int i = 0;i < M;i++) {
		int cy = selected[i].first;
		int cx = selected[i].second;
		visited[cy][cx] = true;
		infectedCnt++;

		q.push({ 1, { cy,cx } });
	}

	while (!q.empty()) {
		int cnt = q.front().first;
		int cx = q.front().second.second;
		int cy = q.front().second.first;
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			else if(visited[ny][nx] || newArr[ny][nx] == -1) continue;

			infectedCnt++;
			visited[ny][nx] = true;
			newArr[ny][nx] = cnt;
			q.push({ cnt + 1,{ny,nx} });

			totalCnt = MAX(cnt, totalCnt);
		}
	}

	if (infectedCnt != emptyCnt) return -1;
	return totalCnt;

}

void select_virus(int cnt, int idx) {
	if (cnt == M) {
		int total = simulate();
		if(total != -1) ans = MIN(total, ans);

		return;
	}
	for (int i = idx;i < virus.size();i++) {
		if (!isSelected[i]) {
			isSelected[i] = true;
			selected.push_back(virus[i]);
			select_virus(cnt + 1,i);
			isSelected[i] = false;
			selected.pop_back();
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)	arr[i][j] = -1;
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
				arr[i][j] = 0;
			}
			if (arr[i][j] == 0) emptyCnt++;
		}
	}

	select_virus(0,0);

	if (ans == INF) cout << "-1";
	else cout << ans;
}