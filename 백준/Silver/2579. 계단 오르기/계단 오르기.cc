#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int N,arr[10004], results[10004], ans = 0;

int main() {
	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	results[0] = arr[0];
	results[1] = arr[0] + arr[1];
	results[2] = MAX(arr[0] + arr[2], arr[1] + arr[2]);

	for (int i = 3;i <= N;i++) {
		results[i] = MAX(results[i - 3] + arr[i-1]+arr[i] , results[i - 2] + arr[i]);
	}

	cout << results[N-1];
}
