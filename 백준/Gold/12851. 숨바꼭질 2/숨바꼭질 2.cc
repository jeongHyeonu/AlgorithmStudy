#include <iostream>
#include <queue>
using namespace std;
#define MIN(a,b)(((a)<(b))?(a)<(b))
#define INF 999999
queue<pair<int,int>> q;

int N, K, minValue = INF, cnt=0;
bool visited[100001];

void bfs() {

	q.push({0,N});

	while (!q.empty()) {
		int curTime = q.front().first;
		int curX = q.front().second;
		q.pop();
		visited[curX] = true;

		if (curX == K && minValue == curTime) {
			cnt++;
		}
		if (curX == K && minValue == INF) {
			minValue = curTime;
			cnt++;
		}

		if (curX - 1 >= 0 && !visited[curX - 1]) q.push({ curTime + 1, curX - 1 });
		if (curX + 1 < 100001 && !visited[curX + 1]) q.push({ curTime + 1, curX + 1 });
		if (curX * 2 < 100001 && !visited[curX * 2]) q.push({ curTime + 1, curX * 2 });
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	bfs();
	cout << minValue << '\n' << cnt;

	return 0;
}
