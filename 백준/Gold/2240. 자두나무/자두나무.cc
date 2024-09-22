#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;

int dp[1002][2][31]; // 시간,위치,이동횟수
int arr[1002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, W;
    cin >> T >> W;

    for (int i = 1;i <= T;i++) cin >> arr[i];

    // 이동횟수/시간 에 따른 dp
    for (int i = 0;i <= W;i++) {
        for (int j = 1;j <= T;j++) { 

            // 자두가 처음 위치에서 가만히 자두 받는 경우
            if (i == 0) {
                dp[j][0][0] = dp[j - 1][0][0] + (arr[j] == 1);
            }

            // 그외 - 자두가 이동한 경우
            else {
                dp[j][0][i] = MAX(dp[j - 1][0][i] + (arr[j] == 1), dp[j - 1][1][i - 1] + (arr[j] == 1));
                dp[j][1][i] = MAX(dp[j - 1][1][i] + (arr[j] == 2), dp[j - 1][0][i - 1] + (arr[j] == 2));
            }
            
        }
    }

    int ans = 0;
    for (int i = 0;i <= W;i++) ans = MAX( MAX(dp[T][0][i], dp[T][1][i]), ans);
    cout << ans;

    return 0;
}
