#include <iostream>
#define MIN(a,b)(((a)<(b))?(a):(b))
#define INF 9999999
using namespace std;

int N, M, start,dest,weight;
int cities[102][102];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) cities[i][j] = 0;
			else cities[i][j] = INF;
		}
	}

	for (int i = 0;i < M;i++) {
		cin >> start >> dest >> weight;
		cities[start][dest] = MIN(cities[start][dest], weight);
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			for (int k = 1;k <= N;k++) {
				cities[j][k] = MIN(cities[j][k], cities[j][i] + cities[i][k]);
			}
		}
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			if (cities[i][j] == INF) cout << 0 << ' ';
			else cout << cities[i][j] << ' ';
		}
		cout << '\n';
	}

}
