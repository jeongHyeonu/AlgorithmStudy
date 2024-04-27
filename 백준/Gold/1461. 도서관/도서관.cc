#include <iostream>
#include <algorithm>
#include <vector>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int N, M, num,ans,idx;
vector<int> v1, v2, v3;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >>M;

	for (int i = 0;i < N;i++) {
		cin >> num;
		if (num < 0) v1.push_back(num);
		else v2.push_back(num);
	}
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	for (int i = 0;i < v1.size();i=i+M) {
		ans += abs(v1[i] * 2);
		v3.push_back(abs(v1[i]));
	}
	for (int i = v2.size()-1;i>=0;i=i-M) {
		ans += v2[i] * 2;
		v3.push_back(v2[i]);
	}

	sort(v3.begin(), v3.end());
	ans -= v3[v3.size()-1];

	cout << ans;
}
