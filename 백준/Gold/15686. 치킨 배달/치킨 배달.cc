#include <iostream>
#include <vector>
#define MIN(a,b)(((a)<(b))?(a):(b))
#define ABS(a)(((a)<0)?-(a):(a))
using namespace std;

int N, M, num,ans=99999999,x,y,sum,d;
int arr[51][51];
vector<pair<int, int>> house, chicken, v;
bool isSelected[13];

int calcul() {
	sum = 0;
	for (int i = 0;i < house.size();i++) {
		d = 99999999;
		for (int j = 0;j < v.size();j++) {
			x = ABS(house[i].first - v[j].first);
			y = ABS(house[i].second - v[j].second);
			d = MIN(d, x + y);
		}
		sum += d;
	}
	return sum;
}

void dfs(int idx,int cnt) {
	if (cnt == M) {
		ans = MIN(ans, calcul());
		return;
	}
	for(int i=idx;i<chicken.size();i++) {
		if (isSelected[i] == true) continue;
		isSelected[i] = true;
		v.push_back(chicken[i]);
		dfs(i, cnt + 1);
		isSelected[i] = false;
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	for (int i = 0;i < N;i++) for (int j = 0;j < N;j++) {
		cin >> num;
		if (num == 1) house.push_back({ i,j });
		else if (num == 2) chicken.push_back({ i,j });
	}

	dfs(0,0);
	cout << ans;
}
