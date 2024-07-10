#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;

int dp[1001][1001];
string s1 = "-", s2 = "-", temp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> temp;
    s1 += temp;
    cin >> temp;
    s2 += temp;

    for (int i = 1;i < s1.size();i++) {
        for (int j = 1;j < s2.size();j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[s1.size()-1][s2.size()-1];

    return 0;
}