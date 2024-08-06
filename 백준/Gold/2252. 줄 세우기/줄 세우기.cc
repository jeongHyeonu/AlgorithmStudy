#include <iostream>
#include <vector>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int N, M;
vector<int> v[32001];
vector<int> ans;
int indegree[32001] = {};
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	
	int A, B;
	for (int i = 0;i < M;i++) {
		cin >> A >> B;
		v[A].push_back(B);
		indegree[B]++;
	}

	for (int i = 1;i <= N;i++) 
		if (indegree[i] == 0) {
			q.push(i);
			ans.push_back(i);
		}

	while (!q.empty()) {
		int item = q.front();
		q.pop();

		for (int i = 0;i < v[item].size();i++) {
			int next = v[item][i];
			indegree[next]--;
			if (indegree[next] == 0) { 
				q.push(next); 
				ans.push_back(next);
			}
		}
	}

	for (int i = 0;i < N;i++) cout << ans[i] << ' ';

	return 0;
}

