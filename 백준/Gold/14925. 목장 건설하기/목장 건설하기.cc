#include <iostream>
#define MIN(a,b)(((a)<(b))?(a):(b))
#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;
int dp[1001][1001] = { 0 };
int N, M;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> M >> N;

    int temp;
    for (int i = 0;i < M;i++) {
        for (int j = 0;j < N;j++) {
            cin >> temp;
            if (!temp) dp[i][j] = 1;
        }
    }

    int ans = 0;
    for (int i = 1;i < M;i++) {
        for (int j = 1;j < N;j++) {
            if (dp[i][j] == 0) continue;
            int minValue = MIN(dp[i - 1][j], MIN(dp[i][j - 1], dp[i - 1][j - 1]));
            if (minValue == 0) continue;
            dp[i][j] = minValue+1;
        }
    }

    for (int i = 0;i < M;i++) 
        for (int j = 0;j < N;j++)
            ans = MAX(dp[i][j], ans);

    cout << ans;
    return 0;
}