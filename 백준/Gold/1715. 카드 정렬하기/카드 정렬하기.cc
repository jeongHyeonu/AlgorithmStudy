#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	if (N == 1) {
		cout << 0; return 0;
	}

	int card;
	for (int i = 0;i < N;i++) {
		cin >> card;
		pq.push(card);
	}

	int sum = 0;
	while(pq.size()>1){
		int temp = pq.top(); pq.pop();
		temp += pq.top(); pq.pop();

		sum += temp;
		pq.push(temp);
	}

	cout << sum;

	return 0;
}