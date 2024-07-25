#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ans[10];
vector<int> v;
bool checked[10] = {};

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0;i < M;i++) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	int temp = 0;
	for (int i = 0;i < N;i++) {
		if (!checked[i] && temp != v[i]) {
			ans[cnt] = v[i];
			temp = v[i];
			checked[i] = true;
			dfs(cnt + 1);
			checked[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	
	int temp;
	for (int i = 0;i < N;i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	dfs(0);
}

