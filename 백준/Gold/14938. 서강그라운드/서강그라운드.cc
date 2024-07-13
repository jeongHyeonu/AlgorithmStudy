#include <iostream>
#include <vector>
#include <queue>
#define INF 9999999
using namespace std;

int n, m, r;
int items[102], dists[102];
int ans = 0;
vector<pair<int, int>> graph[102];
priority_queue<pair<int, int>> q;

int dijkstra(int start) {
    for (int i = 1;i <= n;i++) dists[i] = INF;

    dists[start] = 0;
    q.push({0, start});

    while (!q.empty()) {
        int dist = -q.top().first;
        int cur = q.top().second;
        q.pop();

        for (int i = 0;i < graph[cur].size();i++) {
            int dist_next = dist + graph[cur][i].second;
            int next = graph[cur][i].first;

            if (dist_next < dists[next]) {
                dists[next] = dist_next;
                q.push({ -dist_next, next });
            }
        }
    }

    int result = 0;
    for (int i = 1;i <= n;i++) if(dists[i]<=m) result += items[i];

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> r;

    for (int i = 1;i <= n;i++) cin >> items[i];

    int num1, num2, num3;
    for (int i = 0;i < r;i++) {
        cin >> num1 >> num2 >> num3;
        graph[num1].push_back({ num2,num3 });
        graph[num2].push_back({ num1,num3 });
    }


    int result = 0;
    for (int i = 1;i <= n;i++) {
        result = dijkstra(i);
        if (ans < result) ans = result;
    }
    cout << ans;
}