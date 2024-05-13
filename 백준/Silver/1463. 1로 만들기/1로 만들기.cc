#include <iostream>
#define MIN(a,b)((a)<(b))?(a):(b)
using namespace std;

string temp;
int X;
int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> X;
    
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 2;i <= X;i++) {
        dp[i] = dp[i-1] + 1;
        if (!(i % 3)) dp[i] = MIN(dp[i/3] + 1, dp[i]);
        if (!(i % 2)) dp[i] = MIN(dp[i/2] + 1, dp[i]);
    }

    cout << dp[X];
}