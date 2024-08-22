#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	long long card;
	for (int i = 0;i < N;i++) {
		cin >> card;
		pq.push(card);
	}

	for (int i = 0;i < M;i++) {
		long long temp = pq.top(); pq.pop();
		temp += pq.top(); pq.pop();

		pq.push(temp);
		pq.push(temp);
	}

	long long sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}

	cout << sum;

	return 0;
}