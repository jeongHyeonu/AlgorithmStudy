#include <iostream>
#include <set>
#include <cstring>
using namespace std;

int N;
int arr[101];
set<int> ans;
bool visited[101];

void dfs(int start, int dest) {
	if (start == dest) {
		ans.insert(start);
		ans.insert(arr[start]);
	}
	else {
		if (visited[dest]) return;
		visited[dest] = true;
		dfs(start, arr[dest]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1;i <= N;i++) cin >> arr[i];

	for (int i = 1;i <= N;i++) {
		dfs(i,arr[i]);
		memset(visited, false, sizeof(visited));
	}

	cout << ans.size() << '\n';
	for (auto num : ans) cout << num << '\n';

	return 0;
}
