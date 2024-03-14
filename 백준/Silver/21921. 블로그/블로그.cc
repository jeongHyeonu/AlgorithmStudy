#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int arr[250001] = {};
int X,N,n,sum,ans,cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> X;
	cin >> N;
	
	for (int i = 0;i < X;i++) cin >> arr[i];

	for (int i = 0;i < N;i++) sum += arr[i];

	ans = sum;
	cnt = 1;

	for (int i = N;i < X;i++) {
		sum += arr[i];
		sum -= arr[i - N];
		if (sum > ans) {
			ans = sum;
			cnt = 1;
		}
		else if (sum == ans) {
			cnt++;
		}
	}


	if (ans == 0) cout << "SAD";
	else { 
		cout << ans << '\n';
		cout << cnt;
	}

	return 0;
}