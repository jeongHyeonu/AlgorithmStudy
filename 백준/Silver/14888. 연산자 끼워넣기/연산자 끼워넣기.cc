#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

int N;
int arr[12], operArr[4];
int maxValue = -1234567890, minValue = 1234567890;

void dfs(int idx, int sum) {
    if (idx+1 == N) {
        maxValue = MAX(sum, maxValue);
        minValue = MIN(sum, minValue);
        return;
    }
    for (int i = 0;i < 4;i++) {
        if (operArr[i] == 0) continue;
        operArr[i]--;
        if (i == 0) dfs(idx + 1, sum + arr[idx+1]);
        else if (i == 1) dfs(idx + 1, sum - arr[idx+1]);
        else if (i == 2) dfs(idx + 1, sum * arr[idx+1]);
        else if (i == 3) dfs(idx + 1, sum / arr[idx+1]);
        operArr[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0;i < N;i++) cin >> arr[i];
    for (int i = 0;i < 4;i++) cin >> operArr[i];

    dfs(0, arr[0]);

    cout << maxValue << '\n' << minValue;

    return 0;
}