#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;
int N;
int dp[1500001] = { 0 };
int days[1500001], money[1500001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 1;i <= N;i++) {
        cin >> days[i] >> money[i];
    }

    int maxMoney = 0;
    for (int i = 1;i <= N+1;i++) {
        maxMoney = MAX(maxMoney, dp[i]);
        if(i+days[i] <= N+1) 
            dp[i + days[i]] = MAX(maxMoney + money[i], dp[i + days[i]]);
    }

    cout << maxMoney;
    return 0;
}