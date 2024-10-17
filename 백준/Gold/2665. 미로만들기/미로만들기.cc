#include <iostream>
#include <vector>
#include <queue>
#define INF 99999999

using namespace std;
bool arr[51][51];
int cnt[51][51] = { 0 };
int n;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    char temp;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            cnt[i][j] = INF, cin >> temp, arr[i][j] = (temp == '0') ? 0 : 1;

    queue<pair<int, int>> q;
    q.push({ 0,0 });
    cnt[0][0] = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0;i < 4;i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (!arr[ny][nx]) { // 다음 칸이 검은 방인 경우
                if (cnt[ny][nx] > cnt[cy][cx] + 1) {
                    cnt[ny][nx] = cnt[cy][cx] + 1;
                    q.push({ nx,ny });
                }
            }
            else { // 흰방인 경우
                if (cnt[ny][nx] > cnt[cy][cx]) {
                    cnt[ny][nx] = cnt[cy][cx];
                    q.push({ nx,ny });
                }
            }

        }
    }

    cout << cnt[n-1][n-1];

    return 0;
}