#include <iostream>
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    string arr[20001];
    cin >> N;

    for (int i = 0;i < N;i++) cin >> arr[i];
    //sort(arr, arr + N);

    int idxS=-1, idxT=-1;
    int maxPreStr = 0;

    for (int i = 0;i < N-1;i++) {
        for (int j = i+1;j < N;j++) {
            int minLen = MIN(arr[i].length(), arr[j].length());
            int temp = 0;
            for (int k = 0;k < minLen;k++) {
                if (arr[i][k] != arr[j][k]) break;
                temp++;
            }
            if (temp > maxPreStr) {
                maxPreStr = temp;
                idxS = i;
                idxT = j;
            }
        }
    }

    if (maxPreStr != 0) {
        cout << arr[idxS] << '\n' << arr[idxT];
    }

    return 0;
}