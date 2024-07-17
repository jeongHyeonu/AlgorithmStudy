#include <iostream>
#include <vector>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))
#define INF 999999999
using namespace std;

int N;
int dp[501][501];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int temp;
    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= i;j++) { 
            cin >> temp; 
            dp[i][j] = MAX(temp + dp[i - 1][j - 1], temp + dp[i - 1][j]);
        }
    }

    int ans = 0;
    for (int i = 1;i <= N;i++) {
        ans = MAX(dp[N][i],ans);
    }
    cout << ans;

    return 0;
}