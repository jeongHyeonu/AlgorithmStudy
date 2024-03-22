#include <iostream>
#include <queue>
using namespace std;
#define MIN(a,b)(((a)<(b))?(a)<(b))
#define INF 999999
queue<pair<int,int>> q;

int N, K, minValue = INF, cnt=0;
bool visited[100001] = {};
vector<int> path = {};
int parent[100001] = {};

void bfs() {
	q.push({N,0});

	while (!q.empty()) {
		int curX = q.front().first;
		int curTime = q.front().second;
		q.pop();

		if (curX == K) {
			cout << curTime << '\n';
			int idx = curX;
			while (idx != N) {
				path.push_back(idx);
				idx = parent[idx];
			}
			path.push_back(N);
			return;
		}
		if (curX - 1 >= 0 && !visited[curX - 1]) {
			q.push({ curX - 1, curTime + 1 });
			parent[curX - 1] = curX;
			visited[curX - 1] = true;
		};
		if (curX + 1 < 100001 && !visited[curX + 1]) {
			q.push({ curX + 1, curTime + 1 });
			parent[curX + 1] = curX;
			visited[curX + 1] = true;
		};
		if (curX * 2 < 100001 && !visited[curX * 2]) {
			q.push({ curX * 2, curTime + 1 });
			parent[curX * 2] = curX;
			visited[curX * 2] = true;
		};
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	bfs();
	for (int i = path.size()-1;i >= 0 ;i--) cout << path[i] << ' ';

	return 0;
}
