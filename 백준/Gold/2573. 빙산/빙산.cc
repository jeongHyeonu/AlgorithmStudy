#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M, cx, cy, nx, ny, cnt = 0, timeCnt = 0,meltCnt;
int arr[301][301];
int newArr[301][301];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool isVisited[301][301];
queue<pair<int, int>> q;

void CheckBFS(int y, int x) {
    isVisited[y][x] = true;
    q.push({ x,y });

    while (!q.empty()) {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();
        for (int i = 0;i < 4;i++) {
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (nx >= M || nx < 0 || ny >= N || ny < 0) continue;
            if (isVisited[ny][nx]) continue;
            if (arr[ny][nx] > 0) {
                isVisited[ny][nx] = true;
                q.push({ nx,ny });
            }
        }
    }
}
void MeltIce() {
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            if(arr[i][j] != 0) {
                meltCnt = 0;
                for (int k = 0;k < 4;k++) {
                    nx = j + dx[k];
                    ny = i + dy[k];
                    if (arr[ny][nx] == 0) meltCnt++;
                }
                newArr[i][j] = arr[i][j] - meltCnt;
                if (newArr[i][j] < 0) newArr[i][j] = 0;
            }
        }
    }
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            arr[i][j] = newArr[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cin >> arr[i][j];
        }
    }

    while (true) {
        cnt = 0;
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < M;j++) {
                if (arr[i][j] != 0 && !isVisited[i][j]) {
                    CheckBFS(i,j);
                    cnt++;
                }
            }
        }
        if (cnt == 0) {
            cout << 0;
            break;
        }
        if (cnt >= 2) {
            cout << timeCnt;
            break;
        }
        MeltIce();
        timeCnt++;
        memset(isVisited, false, sizeof(isVisited));
    }

}