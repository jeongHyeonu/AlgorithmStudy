#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int N, K;
bool visited[100001];

int dijkstra() {

	pq.push({ 0,N });

	while (!pq.empty()) {
		int curTime = pq.top().first;
		int curPoint = pq.top().second;
		pq.pop();

		if (curPoint == K) return curTime;

		if (visited[curPoint]) continue;
		visited[curPoint] = true;

		if (curPoint + 1 <= 100000) pq.push({ curTime + 1,curPoint + 1 });
		if (curPoint - 1 >= 0) pq.push({ curTime + 1,curPoint - 1 });
		if (curPoint * 2 <= 100000) pq.push({ curTime, curPoint * 2 });
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	cout << dijkstra();

	return 0;
}
