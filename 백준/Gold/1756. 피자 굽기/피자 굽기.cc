#include <iostream>
using namespace std;

int M, N;
int total;
int ovenHeights[300001];
int doughs[300001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int D, N;
    cin >> D >> N;

    int ovenSize=1234567890;
    int temp;
    for (int i = 0;i < D;i++) {
        cin >> temp;
        ovenSize = (ovenSize > temp) ? temp : ovenSize;
        ovenHeights[i] = ovenSize;
    }

    for (int i = 0;i < N;i++) {
        cin >> temp;
        doughs[i] = temp;
    }

    int curDoughIdx = 0;
    int maxHeight = 0;
    for (int i = D - 1;i >= 0;i--) {
        if (ovenHeights[i] >= doughs[curDoughIdx]) {
            curDoughIdx++;
            if (curDoughIdx == N) {
                cout << i + 1;
                return 0;
            }
        }
    }

    cout << 0;

    return 0;
}