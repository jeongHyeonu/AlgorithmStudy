#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int N;
int dp[22][102] = { 0 }; // 사람수, 체력

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    int health[21], joy[21];
    for (int i = 0;i < N;i++) cin >> health[i];
    for (int i = 0;i < N;i++) cin >> joy[i];

    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= 100;j++) {
            if (j > health[i - 1] ) dp[i][j] = MAX(dp[i - 1][j - health[i - 1]] + joy[i - 1], dp[i - 1][j]);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][100];

    return 0;
}
