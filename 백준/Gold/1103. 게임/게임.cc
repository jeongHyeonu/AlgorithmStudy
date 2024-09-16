#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int mapArr[51][51] = { 0, };
int ans[51][51] = { 0 };
bool visited[51][51] = { 0 };

void input() {
    cin >> N >> M;

    char temp;
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cin >> temp;
            if (temp == 'H') mapArr[i][j] = 0;
            else mapArr[i][j] = temp - '0';
        }
    }
}

int moveCoin(int x, int y) {
    // cout << "current : " << x << ", " << y << '\n';
    if (x < 0 || x >= M || y < 0 || y >= N || mapArr[y][x] == 0) return 0;

    // loop 체크
    if (visited[y][x]) {
        cout << -1;
        exit(0);
    }

    // 메모이제이션
    if (ans[y][x]) return ans[y][x];

    // dfs
    visited[y][x] = true;
    for (int i = 0;i < 4;i++) {
        int nx = x + dx[i] * mapArr[y][x];
        int ny = y + dy[i] * mapArr[y][x];
        ans[y][x] = MAX(ans[y][x], moveCoin(nx, ny) + 1);
    }
    visited[y][x] = false;
    return ans[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    cout << moveCoin(0,0);

    return 0;
}