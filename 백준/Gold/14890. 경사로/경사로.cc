#include <iostream>
#include <vector>
using namespace std;

int n, l, ans;


void solve(int _arr[][101]) {
    for (int i = 0;i < n;i++) { // 가로줄 체크
        bool isArrive = true;
        bool slope[101] = {};
        for (int j = 0;j < n-1;j++) {
            if (_arr[i][j] + 1 < _arr[i][j + 1] || _arr[i][j] - 1 > _arr[i][j + 1]) { // 다음칸 높이 2이상 or 높이 2이하
                isArrive = false;
                break;
            }
            if (_arr[i][j] == _arr[i][j + 1]+1) { // 다음 칸 높이 낮은경우
                // 다음 칸들 높이 다 똑같은지 체크
                for (int k = j + 2; k < j + 1 + l; k++) {
                    if (k>=n || _arr[i][k] != _arr[i][j + 1]) {
                        isArrive = false;
                        break;
                    }
                }
                if (isArrive) {
                    //경사로 설치하면 설치했다고 표시
                    slope[j + l] = true;
                }
                else {
                    break;
                }
            }
            if (_arr[i][j] == _arr[i][j + 1]-1) { // 다음 칸 높이 높은경우
                // 이전 칸들 높이 다 똑같은지 체크
                for (int k = j;k > j - l;k--) {
                    if (k < 0 || _arr[i][j] != _arr[i][k] || slope[k]) { isArrive = false; break; }
                }
                if (!isArrive) break;
            }
        }
        if (isArrive) ans++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr1[101][101];
    int arr2[101][101];

    cin >> n >> l;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> arr1[i][j];
            arr2[j][i] = arr1[i][j];
        }
    }

    solve(arr1);
    solve(arr2);
    cout << ans;
    return 0;
}
