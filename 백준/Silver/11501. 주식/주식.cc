#include <iostream>
#include <vector>
#define MAX(a,b)(((a)>(b))?(a):(b))
#define ABS(a)(((a)<0)?-(a):(a))
using namespace std;

int T,N, mx,arr[1000001];
long long ans=0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;
		mx = -1;
		ans = 0;

		for (int i = 0;i < N;i++) cin >> arr[i];
		for (int i = N - 1;i >= 0;i--) {
			mx = MAX(mx, arr[i]);
			ans += mx - arr[i];
		}
		cout << ans << '\n';
	}
}
