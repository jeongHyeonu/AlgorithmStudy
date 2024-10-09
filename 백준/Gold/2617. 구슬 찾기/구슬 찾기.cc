#include <iostream>
using namespace std;

int arr[101][101] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    int a, b;



    for (int i = 0;i < M;i++) {
        cin >> a >> b;
        arr[a][b] = 1;
    }


    for (int i = 1;i <= N;i++) {
        for (int j = 1;j <= N;j++) {
            for (int k = 1;k <= N;k++) {
                arr[j][k] = (arr[j][i] + arr[i][k] == 2) ? 1 : arr[j][k];
            }
        }
    }

    int sum = 0;
    int weight = (N + 1) / 2;
    for (int i = 1;i <= N;i++) {
        int cnt1, cnt2;
        cnt1 = cnt2 = 0;
        for (int j = 1;j <= N;j++) {
            if (arr[i][j] == 1) cnt1++;
            if (arr[j][i] == 1) cnt2++;
        }
        if (cnt1 >= weight || cnt2 >= weight) sum++;
    }

    cout << sum;
    return 0;
}