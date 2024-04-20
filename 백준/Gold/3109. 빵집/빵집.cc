#include <iostream>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;
char arr[10001][501];
int R, C, ans=0;
int dir[] = {-1,0,1};
int nx,ny;

bool dfs(int x, int y) {
	arr[ny][nx] = 'x';
	if (x == C - 1) { ans++; return true; }

	for (int i = 0;i < 3;i++) {
		nx = x + 1;
		ny = y + dir[i];
		if (ny < 0 || ny >= R) continue;
		if (arr[ny][nx] == 'x') continue;
		if (dfs(nx, ny)) return true;
	}

	return false;
}

int main() {
	cin >> R >> C;

	for (int i = 0;i < R;i++) for (int j = 0;j < C;j++) cin >> arr[i][j];

	for (int i = 0;i < R;i++) dfs(0, i);

	cout << ans;
}
