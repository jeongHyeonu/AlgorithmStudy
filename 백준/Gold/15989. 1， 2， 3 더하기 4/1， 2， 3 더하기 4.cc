#include <iostream>
using namespace std;

int n, T;
int arr[10003][5];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    arr[1][1] = arr[2][1] = arr[2][2] = arr[3][1] = arr[3][2] = arr[3][3] = 1;

    for (int i = 4;i <= 10000;i++) {
        arr[i][1] = arr[i - 1][1];
        arr[i][2] = arr[i - 2][1] + arr[i - 2][2];
        arr[i][3] = arr[i - 3][1] + arr[i - 3][2] + arr[i - 3][3];
    }

    while (T--) {
        cin >> n;
        cout << arr[n][1] + arr[n][2] + arr[n][3] << '\n';
    }

    return 0;
}