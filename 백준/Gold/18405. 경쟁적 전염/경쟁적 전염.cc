#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[201][201];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N, K, S, X, Y;
vector<pair<int,pair<int, int>>> virus;

void bfs() {

	sort(virus.begin(), virus.end());

	while (S--) {
		int virusCnt = virus.size();
		for (int i = 0;i < virusCnt;i++) {
			int types = virus[i].first;
			int cy = virus[i].second.first;
			int cx = virus[i].second.second;

			for (int j = 0;j < 4;j++) {
				int nx = cx + dx[j], ny = cy + dy[j];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if (arr[ny][nx]) continue;

				arr[ny][nx] = types;
				virus.push_back({ types,{ny,nx} });
			}
		}
		if(arr[X - 1][Y - 1]) break;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) 
				virus.push_back({ arr[i][j],{i,j}});
		}
	}
	cin >> S >> X >> Y;

	bfs();

	cout << arr[X-1][Y-1];
}