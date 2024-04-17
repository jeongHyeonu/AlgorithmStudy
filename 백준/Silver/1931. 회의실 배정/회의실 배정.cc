#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int,int> v[100001];

int main() {
	int a, b, ans=0;
	int N; cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> v[i].second >> v[i].first;
	}

	sort(v,v+N);

	int temp = -1;
	for (int i = 0;i < N;i++) {
		if (temp <= v[i].second) {
			ans++;
			temp = v[i].first;
		}
	}

	cout << ans;
}
