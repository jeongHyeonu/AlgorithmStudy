#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,num,l,r,sum,cnt=0;
int arr[2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	if (N <= 2) {
		cout << 0; return 0;
	}

	sort(arr,arr+N);

	for (int i = 0;i < N;i++) {
		l = 0;
		r = N - 1;
		while (l < r) {
			sum = arr[l] + arr[r];
			if (sum == arr[i]) { 
				if (l != i && r != i) { cnt++; break; }
				else if (l == i) l++;
				else if (r == i) r--;
			}
			else if (sum < arr[i]) l++;
			else r--;
		}
	}

	cout << cnt;

	return 0;
}
