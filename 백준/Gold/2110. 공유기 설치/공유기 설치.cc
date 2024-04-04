#include <iostream>
#include <algorithm>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int N,C,router,ans=0;
int arr[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> C;

	for (int i = 0;i < N;i++) cin >> arr[i];

	sort(arr, arr + N);

	int start = 1;
	int end = arr[N - 1] - arr[0];
	int mid, temp;
	while (start <= end) {
		router = 1;
		mid = (start + end) / 2;
		temp = arr[0];
		for (int i = 1; i < N; i++)
		{
			if (arr[i] - temp >= mid)
			{
				router++;
				temp = arr[i];
			}
		}
		if (router >= C)
		{
			ans = MAX(ans, mid);
			start = mid + 1;
		}
		else end = mid - 1;
	}
	cout << ans;

	return 0;
}
