#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;
int N;
int arr[1001];
int dp[1001];
int ans=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> arr[i];
        dp[i] = 1;
    }
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < i;j++) {
            if(arr[i]>arr[j]) dp[i] = MAX(dp[i], dp[j] + 1);
        }
        ans = MAX(ans, dp[i]);
    }

    cout << ans;

    return 0;
}