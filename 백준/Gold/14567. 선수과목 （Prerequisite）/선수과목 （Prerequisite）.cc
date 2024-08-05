#include <iostream>
#include <vector>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int N, M;
int ans[1001] = {};
int indegree[1001];
vector<int> v[1001];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1;i <= N;i++) ans[i] = 1;

	int A, B;
	for (int i = 0;i < M;i++) {
		cin >> A >> B;
		v[A].push_back(B);
		indegree[B]++;
	}

	for (int i = 1;i <= N;i++) {
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int item = q.front();
		q.pop();

		for (int i = 0;i < v[item].size();i++) {
			int next = v[item][i];
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(next);
				ans[next] = MAX(ans[next], ans[item] + 1);
			}
		}
	}

	for (int i = 1;i <= N;i++) cout << ans[i] << ' ';

	return 0;
}

