#include <iostream>
#include <vector>
using namespace std;

long long arr[501][501];
int dp[501][501];
int M,N;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

int dfs(int x, int y) {
	if (x == N - 1 && y == M - 1) return 1;
	if (dp[y][x] == -1) {
		dp[y][x] = 0;
		for (int i = 0;i < 4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (arr[y][x] <= arr[ny][nx]) continue;
			dp[y][x] = dfs(nx, ny) + dp[y][x];
		}
	}
	return dp[y][x];
}

int main() {
	cin >> M>>N;

	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0,0);
}