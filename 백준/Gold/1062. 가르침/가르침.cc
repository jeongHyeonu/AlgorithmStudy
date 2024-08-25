#include <iostream>
#include <vector>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

bool mask[27] = { 0, };
int ans = 0;
vector<string> v;
int N, K;

void dfs(int idx, int cnt) {
	if (cnt == K) {
		int res = N;
		for (int i = 0;i < v.size();i++) 
			for (int j = 0;j < v[i].size();j++) 
				if (!mask[v[i][j] - 'a']) { res--; break; }
		
		ans = MAX(ans, res);
		return;
	}
	for (int i = idx;i < 26;i++) {
		if (mask[i]) continue;
		mask[i] = true;
		dfs(i, cnt + 1);
		mask[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	if (K <= 4) {
		cout << 0;
		return 0;
	}

	mask['a' - 'a'] = mask['n' - 'a'] = mask['t' - 'a'] = mask['i' - 'a'] = mask['c' - 'a'] = true;
	K -= 5;

	string s;
	for (int i = 0;i < N;i++) {
		cin >> s;
		v.push_back(s);
	}

	dfs(0,0);
	cout << ans;

	return 0;
}