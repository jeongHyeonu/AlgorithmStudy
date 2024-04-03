#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int N,L,H, max_height=0, max_length=0, ans=0, max_idx=0;
int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> L >> H;
		arr[L] = H;
		max_length = MAX(max_length, L);
		if (max_height < H) {
			max_idx = L;
			max_height = H;
		}
	}
	
	int leftMaxH = 0;
	for (int i = 0;i < max_idx;i++) {
		leftMaxH = MAX(leftMaxH, arr[i]);
		ans += leftMaxH;
	}

	int rightMaxH = 0;
	for (int i = max_length;i > max_idx;i--) {
		rightMaxH = MAX(rightMaxH, arr[i]);
		ans += rightMaxH;
	}

	cout << ans + max_height;

	return 0;
}
