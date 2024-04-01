#include <iostream>
#include <algorithm>
using namespace std;

int N,ans1,ans2,res=2000000001;
int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N;i++) cin >> arr[i];
	
	int left = 0, right = N-1;
	res = abs(arr[left] + arr[right]);
	ans1 = left, ans2 = right;

	while (left < right-1) {
		if (arr[left] + arr[right] < 0) left++;
		else right--;
		if (res > abs(arr[left] + arr[right])) {
			res = abs(arr[left] + arr[right]);
			ans1 = left, ans2 = right;
		}
	}
	cout << arr[ans1] << ' ' << arr[ans2];

	return 0;
}
