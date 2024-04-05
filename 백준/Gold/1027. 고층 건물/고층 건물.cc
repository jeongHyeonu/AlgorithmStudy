#include <iostream>
#include <algorithm>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int N,C,router,ans=0;
int buildings[51];
int results[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) cin >> buildings[i];

	for (int i = 0;i < N;i++) {
		double maxIncline = -9999999999;
		for (int j = i+1;j < N;j++) {
			double incline = (buildings[j] - buildings[i]) / (double)(j - i);
			if (incline > maxIncline) {
				maxIncline = incline;
				results[i]++;
				results[j]++;
			}
		}
	}

	int maxCnt = 0;
	for (int i = 0;i < N;i++) maxCnt = MAX(maxCnt, results[i]);
	cout << maxCnt;

	return 0;
}
