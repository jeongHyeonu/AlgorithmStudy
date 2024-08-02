#include <iostream>
#include <queue>
#define Max 200001
using namespace std;

int N,K;
bool visited[Max];

void bfs() {
	queue<pair<int,int>> q;
	q.push({ N,0 });
	visited[N] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cx == K) {
			cout << cnt;
			return;
		}

		if (cx + 1 < 100001 && !visited[cx + 1]) {
			visited[cx + 1] = true;
			q.push({ cx + 1,cnt + 1 });
		}
		if (cx - 1 >= 0 && !visited[cx - 1]) {
			visited[cx - 1] = true;
			q.push({ cx - 1,cnt + 1 });
		}
		if (cx * 2 < 100001 && !visited[cx * 2]) {
			visited[cx * 2] = true;
			q.push({ cx * 2,cnt + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N >> K;

	bfs();
}

