#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, num1;
priority_queue<int,vector<int>,greater<int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0;i < n*n;i++) {
		cin >> num1;
		pq.push(num1);
		if (pq.size() > n) pq.pop();
	}

	cout << pq.top();
}