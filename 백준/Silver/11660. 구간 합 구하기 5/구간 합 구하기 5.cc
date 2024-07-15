#include <iostream>
using namespace std;

int N, M;
int dp[1025][1025];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    
    int temp;
    for(int i=1;i<=N;i++){
        for (int j = 1;j <= N;j++) {
            cin >> temp;
            dp[i][j] = temp + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
    }

    int x1, x2, y1, y2;
    for (int i = 0;i <M;i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << dp[y2][x2] - dp[y2][x1-1] - dp[y1-1][x2] + dp[y1-1][x1-1] << '\n';
    }

}