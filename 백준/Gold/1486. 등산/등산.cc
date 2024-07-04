#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MIN(a,b)(((a)<(b))?(a):(b))
#define MAX(a,b)(((a)>(b))?(a):(b))
#define INF 999999
using namespace std;

int N,M,T,D, ans = -0;
int map_arr[26][26];
int visited[26][26];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int dists[26][26] = { 0, };

void dijkstra(bool way) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    memset(dists, INF, sizeof(dists));
    dists[0][0] = 0;
    pq.push({ 0, {0,0}});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int x = pq.top().second.second;
        int y = pq.top().second.first;
        pq.pop();

        if (dist > D) continue;
        if (dists[y][x] < dist) continue;

        for (int i = 0;i < 4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int n_dist = dist;

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            int diff = abs(map_arr[ny][nx] - map_arr[y][x]);
            if (diff>T) continue;
            if (!way) { // 등산
                if (map_arr[ny][nx] <= map_arr[y][x]) n_dist++;
                else n_dist += diff * diff;
            }
            else { // 하산
                if (map_arr[ny][nx] >= map_arr[y][x]) n_dist++;
                else n_dist += diff * diff;
            }
            if (dists[ny][nx] > n_dist) {
                dists[ny][nx] = n_dist;
                pq.push({ n_dist, { ny,nx } });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> T >> D;
    char temp;

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            cin >> temp;
            if (temp >= 'A' && temp <= 'Z') map_arr[i][j] = temp - 'A';
            else map_arr[i][j] = temp - 'a' + 26;
        }
    }

    dijkstra(false);
    int mount_up[26][26] = {};
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            mount_up[i][j] = dists[i][j];

    dijkstra(true);
    int mount_down[26][26] = {};
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            mount_down[i][j] = dists[i][j];



    for (int i = 0;i < N;i++) {
        for (int j = 0;j < M;j++) {
            int total_dist = mount_up[i][j] + mount_down[i][j];
            if (total_dist <= D) ans = MAX(ans, map_arr[i][j]);
        }
    }

    cout << ans;
    return 0;
}