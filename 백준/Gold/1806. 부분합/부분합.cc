#include <iostream>
#include <queue>
#define INF 111111111
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

queue<int> q;

int N, S, sum=0, minLen=INF;
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;
	for (int i = 0;i < N;i++) cin >> arr[i];

	int start=0, end=0;
	while (start <= end) {
		if (sum >= S) {
			minLen = MIN(minLen, end - start);
			sum -= arr[start++];
		}
		else if (end >= N) break;
		else sum += arr[end++];
	}

	if (minLen == INF) cout << 0;
	else cout << minLen;

	return 0;
}
