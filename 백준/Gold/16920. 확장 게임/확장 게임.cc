#include <iostream>
#include <queue>
#define INF 999999
using namespace std;

int N, M, P;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char mapArr[1001][1001] = { 0, };
int S[11];
int ans[11];
queue<pair<int,pair<int, int>>> q[10]; // 확장횟수, y,x

//void printArr() {
//    for (int i = 0;i < N;i++) {
//        for (int j = 0;j < M;j++) {
//            cout << mapArr[i][j];
//        }
//        cout << '\n';
//    }
//    cout << '\n';
//}

void input() {
    cin >> N >> M >> P;
    for(int i=0;i<P;i++) cin >> S[i];

    char temp;
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cin >> mapArr[i][j];
            if (mapArr[i][j] != '.' && mapArr[i][j] != '#') {
                ans[mapArr[i][j] - '1']++;
                q[mapArr[i][j] - '1'].push({0, {i,j}});
            }
        }
    }
}

void solve() {

    int roundCnt = 1;
    bool isGameOver = false;

    while (!isGameOver) {

        int gameoverCnt = 0;

        for (int i = 0;i < P;i++) {

            bool expanded = false;

            while (!q[i].empty()) {
                int cx = q[i].front().second.second;
                int cy = q[i].front().second.first;
                int cnt = q[i].front().first;
                if (cnt / S[i] >= roundCnt) break;
                q[i].pop();

                for (int j = 0;j < 4;j++) {
                    int nx = cx + dx[j];
                    int ny = cy + dy[j];
                    if (nx >= M || nx < 0 || ny >= N || ny < 0) continue;
                    if (mapArr[ny][nx] == '.') {
                        mapArr[ny][nx] = '1' + i;
                        ans[i]++;
                        expanded = true;
                        q[i].push({ cnt + 1, {ny,nx} });
                    }
                }
            }

            if (!expanded) gameoverCnt++;
        }
        // printArr();

        if (gameoverCnt == P) isGameOver = true;
        roundCnt++;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve();

    for (int i = 0;i < P;i++) cout << ans[i] << ' ';

    return 0;
}
