#include <iostream>
#include <stack>
#define INF -1
using namespace std;

int N, height;
int arr[500001], ans[500001];
stack<pair<int,int>> s;

// 5
// 1 2 3 4 5
// 0 0 0 0 0

// 5
// 5 4 3 2 1
// 0 1 2 3 4

// 6
// 10 9 10 9 10 9
// 0  1 1  3 3  5

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	s.push({ 0,100000001 });
	cin >> N;

	for (int i = 1;i <= N;i++) {
		cin >> height;
		while (s.top().second < height) {
			s.pop();
		}
		cout << s.top().first << ' ';
		s.push({ i, height });
	}

	return 0;
}
