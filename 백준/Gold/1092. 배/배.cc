#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 23 25 28 32
// 2 5 7 10 16 18 20 24 27 32


int N, M;
vector<int> cranes, boxes;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	int c;
	for (int i = 0;i < N;i++) {
		cin >> c;
		cranes.push_back(c);
	}

	cin >> M;

	int b;
	for (int i = 0;i < M;i++) {
		cin >> b;
		boxes.push_back(b);
	}

	sort(cranes.begin(), cranes.end(),cmp);
	sort(boxes.begin(), boxes.end(),cmp);

	int boxIdx = 0;

	if (boxes[0] > cranes[0]) {
		cout << -1;
		return 0;
	}

	int ans = 0;
	while (boxes.size()) {
		ans++;
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < boxes.size();j++) {
				if (boxes[j] <= cranes[i]) {
					boxes.erase(boxes.begin() + j);
					break;
				}
			}
		}
	}
	cout << ans;

	return 0;
}