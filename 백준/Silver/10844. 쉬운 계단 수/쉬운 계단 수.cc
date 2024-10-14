#include <iostream>
#define DIV 1000000000
using namespace std;

int dp[101][10] = { 0 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for (int i = 1;i < 10;i++) {
        dp[1][i] = 1;
    }

    for (int i = 2;i <= N;i++) {
        dp[i][0] = dp[i - 1][1];
        for (int j = 1;j < 9;j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % DIV;
        }
        dp[i][9] = dp[i - 1][8];
    }

    int ans = 0;
    for (int i = 0;i < 10;i++) {
        ans = (ans + dp[N][i]) % DIV;
    }
    cout << ans;

    return 0;
}