#include <iostream>
#include <queue>
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
using namespace std;

int N, M;
bool arr[101][101];
int visited[101][101];

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    int cnt = 1;
    visited[y][x] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0;i < 4;i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[ny][nx]) continue;
            if (arr[y][x] != arr[ny][nx]) continue;
            visited[ny][nx] = true;
            cnt++;
            q.push({ nx,ny });
        }
    }

    return cnt * cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    char temp;
    for (int i = 0;i < M;i++) {
        for (int j = 0;j < N;j++) {
            cin >> temp;
            if (temp == 'B') arr[i][j] = true; // 적군인 경우 true
        }
    }

    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0;i < M;i++)
        for (int j = 0;j < N;j++)
            if (!visited[i][j]) {
                if (!arr[i][j]) sum1 += bfs(j, i);
                else sum2 += bfs(j, i);
            }

    cout << sum1 << ' ' << sum2;
    return 0;
}
