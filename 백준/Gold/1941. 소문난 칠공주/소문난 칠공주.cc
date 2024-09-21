#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 5;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char arr[5][5];
bool selected[25] ;
int ans = 0;

void input() {
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            cin >> arr[i][j];
        }
    }
}

void printArr() {
    for (int i = 0;i < 25;i++) {
        cout << selected[i] << ' ';
        if ((i+1) % 5 == 0) cout << '\n';
    }
    cout << '\n';
}

bool isValid() {
    queue<pair<int,int>> q;
    bool visited[5][5] = { 0 };

    // 선택된 조합 중 일부 찾고 queue에 push
    int idx,x,y;
    for (idx = 0;idx < 25;idx++) {
        if (selected[idx]) {
            x = idx % N;
            y = idx / N;
            visited[y][x] = true;
            q.push({ x,y });
            break;
        }
    }

    // bfs
    int cnt = 1;
    while (!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();

        for (int i = 0;i < 4;i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = true;
            if (selected[ny*N + nx]) {
                cnt++;
                q.push({ nx,ny });
            }
        }
    }

    if (cnt == 7) return true;
    else return false;
}

bool chk_seven() {
    int cnt = 0;

    for (int i = 0;i < 25;i++) {
        if (selected[i]) {
            int x = i % N;
            int y = i / N;
            if (arr[y][x] == 'S') cnt++;
        }
    }

    if (cnt >= 4) return true;
    else return false;
}

void dfs(int cnt, int idx) {
    if (cnt == 7) {
        if (chk_seven()) {
            if (isValid()) ans++;
        }
        return;
    }
    for (int i = idx;i < 25;i++) {
        if (selected[i]) continue;
        selected[i] = true;
        dfs(cnt + 1, i);
        selected[i] = false;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    dfs(0, 0);
    cout << ans;

    return 0;
}