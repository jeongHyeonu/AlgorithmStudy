#include <iostream>
#include <vector>
#include <queue>
#define MIN(a,b)(((a)<(b))?(a):(b))
#define INF 999999999
using namespace std;

int N, E;
int v1, v2;
int dists[801];
vector<pair<int, int>> v[801];
priority_queue<pair<int,int>> q;


void dijkstra(int start) {
    for (int i = 0;i <= N;i++) dists[i] = INF;
    dists[start] = 0;
    q.push({0,start});

    while (!q.empty()) {
        int cur_cost = -q.top().first;
        int cur_node = q.top().second;
        q.pop();

        for (int i = 0;i < v[cur_node].size();i++) {
            int n_cost = cur_cost + v[cur_node][i].second;
            int n_node = v[cur_node][i].first;

            if (dists[n_node] > n_cost) {
                dists[n_node] = n_cost;
                q.push({ -n_cost,n_node });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> E;
    
    int  a, b, c;
    for (int i = 0;i < E;i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
    cin >> v1 >> v2;


    dijkstra(1);
    int res1 = dists[v1];
    int res2 = dists[v2];

    dijkstra(v1); // v1 -> v2 , v2 -> v1 가는 거리 같음
    res1 += dists[v2];
    res2 += dists[v2];

    dijkstra(N);
    res1 += dists[v2];
    res2 += dists[v1];

    int ans = MIN(res1, res2);
    if (ans >= INF || ans < 0) cout << -1;
    else cout << ans;

    return 0;
}