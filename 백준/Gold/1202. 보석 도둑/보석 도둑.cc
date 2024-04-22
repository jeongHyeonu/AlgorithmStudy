#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

priority_queue<int> pq;
vector<pair<int,int>> v1;
vector<int> v2;
int N, K, M, V, c;
long long ans = 0;

int main() {
	cin >> N >> K;

	for (int i = 0;i < N;i++) {
		cin >> M >> V;
		v1.push_back({ M,V });
	}
	for (int i = 0;i < K;i++) {
		cin >> c;
		v2.push_back(c);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int idx = 0;
	for (int i = 0;i < K;i++) {
		while (idx < N && v2[i] >= v1[idx].first) {
			pq.push(v1[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}


	cout << ans;
}
