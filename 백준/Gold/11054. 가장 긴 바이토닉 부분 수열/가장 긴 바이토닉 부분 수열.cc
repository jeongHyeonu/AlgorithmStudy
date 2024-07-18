#include <iostream>
#include <vector>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))
#define INF 999999999
using namespace std;

int N;
int dp1[1002];
int dp2[1002];
int arr[1002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1;i <= N;i++) {
        cin >> arr[i];
        dp1[i] = 1;
        dp2[i] = 1;
    }

    for (int i = 1;i <= N;i++) {
        for (int j = 1;j < i;j++) {
            if (arr[j] < arr[i] && dp1[j] >= dp1[i] ) dp1[i] += 1;
        }
    }

    for (int i = N;i >= 1;i--) {
        for (int j = N;j > i;j--) {
            if (arr[j] < arr[i] && dp2[j] >= dp2[i]) dp2[i] += 1;
        }
    }

    int ans = 0;
    for (int i = 1;i <= N;i++) ans = MAX(ans, dp1[i] + dp2[i]);

    cout << ans - 1;
    
    return 0;
}