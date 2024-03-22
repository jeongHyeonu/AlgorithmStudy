#include <iostream>
#include <queue>
#define INF -1
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int R,C,ans=INF;
char arr[21][21];

void dfs(int x, int y, int cnt, bool _alpha[]) {
	//cout << cnt << " : " << arr[y][x] << '\n';

	if (_alpha[arr[y][x] - 'A']) return;
	bool alphaList[26] = {};
	copy(_alpha, _alpha + 26, alphaList);
	alphaList[arr[y][x] - 'A'] = true;

	ans = MAX(ans, cnt+1);
	if (x + 1 < C) dfs(x + 1, y, cnt + 1, alphaList);
	if (x - 1 >= 0) dfs(x - 1, y, cnt + 1, alphaList);
	if (y + 1 < R) dfs(x, y + 1, cnt + 1, alphaList);
	if (y - 1 >= 0) dfs(x, y - 1, cnt + 1, alphaList);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0;i < R;i++) for (int j = 0;j < C;j++) cin >> arr[i][j];

	bool alphabets[26] = {};
	dfs(0,0,0,alphabets);
	cout << ans;

	return 0;
}
