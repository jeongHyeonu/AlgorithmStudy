#include <iostream>
#include <vector>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

vector<pair<int, int>> v;
int ans = 0;
int N;

void dfs(int curIdx) {

	// 가장 오른쪽 계란이면 종료
	if (curIdx >= N) {
		int cnt = 0;
		for (int i = 0;i < N;i++)
			if (v[i].first <= 0) cnt++;
		ans = MAX(cnt, ans);
		return;
	}

	// 이미 깨진 계란인 경우
	if (v[curIdx].first <= 0) {
		dfs(curIdx + 1);
		return;
	}

	// 깨뜨릴 계란이 더이상 없는경우 체크 변수
	bool flag = false;

	for (int i = 0;i < N;i++) { 

		// 현재 계란인 경우 or 깨진 경우 dfs 하지 않음
		if (i==curIdx || v[i].first <= 0) continue;

		flag = true;
		v[curIdx].first -= v[i].second;		// 현재 달걀 내구도
		v[i].first -= v[curIdx].second;		// 깨트릴 달걀 내구도

		dfs(curIdx+1);

		v[curIdx].first += v[i].second;
		v[i].first += v[curIdx].second;
	}

	// 깨뜨릴 계란이 더이상 없는경우
	if (!flag) dfs(N);
}

int main() {
	int s,w;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> s >> w;
		v.push_back({ s,w });
	}

	dfs(0);
	cout << ans;
}