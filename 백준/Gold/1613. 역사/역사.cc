#include <iostream>
using namespace std;

int n, k;
int dists[402][402] = { 0 };

void input() {
    cin >> n >> k;
    int a, b;

    for (int i = 0;i < k;i++) {
        cin >> a >> b;
        dists[a][b] = -1;
        dists[b][a] = 1;
    }
}

void solve() {
    for (int i = 1;i <= n;i++) { // 중간점 i
        for (int j = 1;j <= n;j++) { // 시작점 j
            for (int k = 1;k <= n;k++) { // 도착점 k
                if (dists[j][k] == 0) {
                    if (dists[j][i] == 1 && dists[i][k] == 1) {
                        dists[j][k] = 1;
                    }
                    else if (dists[j][i] == -1 && dists[i][k] == -1) {
                        dists[j][k] = -1;
                    }
                }
            }
        }
    }

    int s,a,b;
    cin >> s;
    while (s--) {
        cin >> a >> b;
        cout << dists[a][b] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve();

    return 0;
}
