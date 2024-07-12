#include <iostream>
#include <cstring>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int N;
int ans;
char arr[101][101];
bool visited[101][101];

void dfs(int y, int x) {
    if (visited[y][x]) return;
    visited[y][x] = true;

    for (int i = 0;i < 4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (visited[ny][nx]) continue;
        if (arr[ny][nx]==arr[y][x]) dfs(ny, nx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0;i < N;i++) 
        for (int j = 0;j < N;j++) 
            cin >> arr[i][j];

    ans = 0;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            if (!visited[i][j]) { dfs(i, j), ans++; }

    cout << ans << ' ';

    for (int i = 0;i < N;i++) for (int j = 0;j < N;j++) if (arr[i][j] == 'G') arr[i][j] = 'R';
    memset(visited, false, sizeof(visited));
    ans = 0;

    for (int i = 0;i < N;i++) 
        for (int j = 0;j < N;j++) 
            if (!visited[i][j]) { dfs(i, j), ans++; }

    cout << ans;
}