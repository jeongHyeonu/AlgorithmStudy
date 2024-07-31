#include <iostream>
#include <vector>
#include <queue>
#define INF 99999999
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

int N, M, B;
int arr[501][501];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N >> M >> B;

	for (int i = 0;i < N;i++) 
		for (int j = 0;j < M;j++) 
			cin >> arr[i][j];


	int minTime = 99999999, maxHeight = -1;
	for (int h = 0;h <= 256;h++) {
		int build = 0 , remove = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < M;j++) {
				if (arr[i][j] > h) remove += (arr[i][j] - h);
				else build += (h - arr[i][j]);
			}
		}
		if (remove + B >= build) {
			int t = remove * 2 + build;
			if (t <= minTime) {
				minTime = t;
				maxHeight = h;
			}
		}
	}

	cout << minTime << ' ' << maxHeight;
}

