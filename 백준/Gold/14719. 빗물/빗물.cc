#include <iostream>
#define MIN(a,b)(((a)<(b))?(a):(b))
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int H, W, leftIdx, rightIdx, minHeight;
int arr[501] = { };
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> H >> W;

	for (int i = 0;i < W;i++) cin >> arr[i];

	for (int i = 1;i < W-1;i++) {
		leftIdx = rightIdx = i;
		for (int j = leftIdx-1;j >= 0;j--) if (arr[j] > arr[leftIdx]) leftIdx = j;
		for (int j = rightIdx+1;j < W;j++) if (arr[j] > arr[rightIdx]) rightIdx = j;
		minHeight = MIN(arr[leftIdx], arr[rightIdx]);
		if (minHeight > arr[i]) ans += minHeight - arr[i];
	}

	cout << ans;

	return 0;
}
