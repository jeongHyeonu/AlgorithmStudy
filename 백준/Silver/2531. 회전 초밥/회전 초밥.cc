#include <iostream>
#include <cstring>
using namespace std;

#define MAX(a,b)(((a)>(b))?(a):(b))

int N,d,k,c, num;
int ans = 0;
int arr[30001];
bool checkArr[30001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> d >> k >> c;
	for (int i = 0;i < N;i++) cin >> arr[i];
	for (int i = 0;i < N;i++) {
		int cnt = 1;
		checkArr[c] = true;
		for (int j = i;j < i + k;j++) {
			if (!checkArr[arr[j%N]]) {
				checkArr[arr[j%N]] = true;
				cnt++;
			}
		}
		//cout << "[" << i << "]" << cnt << '\n';
		memset(checkArr, false, sizeof(checkArr));
		ans = MAX(cnt, ans);
	}

	cout << ans;

	return 0;
}
