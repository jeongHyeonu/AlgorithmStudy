#include <iostream>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

queue<int> q;
int cnt[10];
int fruit;
int N;
int ans = 0;
int fruitType = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> fruit;

		if (cnt[fruit] == 0) fruitType++;

		cnt[fruit]++;
		q.push(fruit);


		while (fruitType > 2) {
			int item = q.front();
			q.pop();
			cnt[item]--;
			if(cnt[item]==0) fruitType--;
		}

		ans = MAX(ans, q.size());
	} 

	cout << ans;
}