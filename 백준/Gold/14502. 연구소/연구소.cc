#include <iostream>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int n, m, maxCnt;
int arr[8][8];
int temp[8][8];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void solve() {
    int cnt = 0;
    queue<pair<int, int>> q;

    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++) {
            temp[i][j] = arr[i][j];
            if (arr[i][j] == 2) q.push({ i,j });
        }

    while (!q.empty()) {
        int cx = q.front().second;
        int cy = q.front().first;
        q.pop();

        for (int i = 0;i < 4;i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx<0 || nx>=m || ny<0 || ny>=n) continue;
            if (temp[ny][nx] == 0) {
                q.push({ ny,nx });
                temp[ny][nx] = 2;
            }
        }
    }

    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            if (temp[i][j] == 0) cnt++;
    
    maxCnt = MAX(cnt, maxCnt);
}

void wall(int cnt) {
    if (cnt == 3) {
        solve();
        return;
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                wall(cnt+1);
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m;

    for (int i = 0;i < n;i++) 
        for (int j = 0;j < m;j++) 
            cin >> arr[i][j];

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1;
                wall(1);
                arr[i][j] = 0;
            }
        }
    }

    cout << maxCnt;
    return 0;
}
