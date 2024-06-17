#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;
int n, m, sum = -1;
int arr[501][501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            // ㅡ ㅣ
            if (j + 3 <= m) sum = MAX(sum, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3]);
            if (i + 3 <= n) sum = MAX(sum, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j]);

            // ㅁ
            if (j + 1 <= m && i + 1 <= n) sum = MAX(sum, arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1]);

            // ┌- -┐ -┘└-
            if (i + 1 <= n && j + 2 <= m) sum = MAX(sum, arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i][j + 2]);
            if (i + 1 <= n && j + 2 <= m) sum = MAX(sum, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]);
            if (i + 1 <= n && j + 2 <= m) sum = MAX(sum, arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2] + arr[i][j + 2]);
            if (i + 1 <= n && j + 2 <= m) sum = MAX(sum, arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);
            // L _I I^ ^l
            if (i + 2 <= n && j + 1 <= m) sum = MAX(sum, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1]);
            if (i + 2 <= n && j + 1 <= m) sum = MAX(sum, arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 1][j + 1] + arr[i][j + 1]);
            if (i + 2 <= n && j + 1 <= m) sum = MAX(sum, arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j]);
            if (i + 2 <= n && j + 1 <= m) sum = MAX(sum, arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1]);
            
            // z
            if (i + 2 <= n && j + 1 <= m) sum = MAX(sum, arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1]);
            if (i + 1 <= n && j + 2 <= m) sum = MAX(sum, arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i][j + 2]);
            // z 대칭
            if (i + 2 <= n && j + 1 <= m) sum = MAX(sum, arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j] + arr[i + 2][j]);
            if (i + 1 <= n && j + 2 <= m) sum = MAX(sum, arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);

            // ㅜㅏㅓㅗ
            if (i + 1 <= n && j + 2 <= m) sum = MAX(sum, arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i][j + 2]);
            if (i + 2 <= n && j + 1 <= m) sum = MAX(sum, arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j]);
            if (i + 2 <= n && j + 1 <= m) sum = MAX(sum, arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j] + arr[i + 2][j + 1]);
            if (i + 1 <= n && j + 2 <= m) sum = MAX(sum, arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i + 1][j + 2]);
        }
    }

    cout << sum;
}