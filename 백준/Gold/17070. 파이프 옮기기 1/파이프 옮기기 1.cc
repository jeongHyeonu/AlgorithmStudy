#include <iostream>
#include <vector>
#include <queue>
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

int N;
int arr[17][17];
int ans = 0;

bool checkArr(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N) return false;
	else return true;
}

void dfs(int x, int y, int dir) {
	if (x == N - 1 && y == N - 1) {
		ans++;
		return;
	}

	if(checkArr(x+1,y))
		if(dir!=2 && arr[y][x+1]==0) 
			dfs(x + 1, y, 0); // 가로

	if(checkArr(x,y+1))
		if(dir!=0 && arr[y+1][x]==0) 
			dfs(x, y + 1, 2); // 세로

	if(checkArr(x+1,y+1))
		if (arr[y + 1][x] == 0 && arr[y][x + 1] == 0 && arr[y + 1][x + 1] == 0)
			dfs(x + 1, y + 1, 1); // 대각선
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++) 
			cin >> arr[i][j];

	dfs(1,0,0);
	cout << ans;
}

