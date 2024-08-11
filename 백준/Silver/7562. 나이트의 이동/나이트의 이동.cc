#include <iostream>
#include <cstring>
#include <queue>
#define MIN(a,b)(((a)<(b))?(a):(b))
#define INF 999999999
using namespace std;

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};
bool visited[301][301];

int main() {
    int T, l;
    int now_x, now_y, tx, ty;

    cin >> T;
    while (T--) {
        queue<pair<int,pair<int, int>>> q;
        cin >> l;
        cin >> now_x >> now_y;
        cin >> tx >> ty;
        q.push({ 0,{ now_x,now_y } });
        memset(visited, false, sizeof(visited));

        while (!q.empty()) {
            int dist = q.front().first;
            int cx = q.front().second.first;
            int cy = q.front().second.second;

            if (cx == tx && cy == ty) {
                cout << dist << '\n';
                break;
            }
            q.pop();

            for (int i = 0;i < 8;i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if (visited[nx][ny]) continue;

                visited[nx][ny] = true;
                q.push({ dist + 1,{nx,ny} });
            }
        }
    }
} 