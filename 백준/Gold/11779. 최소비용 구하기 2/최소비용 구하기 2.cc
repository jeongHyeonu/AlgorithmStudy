#include <iostream>
#include <vector>
#include <queue>
#define MIN(a,b)(((a)<(b))?(a):(b))
#define INF 999999999
using namespace std;

int dist[1001];
int routes[1001];
vector<pair<int, int>> v[1001];

void dijkstra (int start) {
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({ 0,start });

    while (!pq.empty()) {
        int c_cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < c_cost) continue;

        for (int i = 0;i < v[cur].size();i++) {
            int next = v[cur][i].first;
            int n_cost = c_cost + v[cur][i].second;

            if (dist[next] > n_cost) {  
                dist[next] = n_cost;
                routes[next] = cur;
                pq.push({ -n_cost,next });
            }
        }
    }
}


int main() {
    int n,m;


    cin >> n >> m;
    for (int i = 1;i <= n;i++) dist[i] = INF;

    int n1, n2, cost;
    for (int i = 0; i < m; i++) {
        cin >> n1 >> n2 >> cost;
        v[n1].push_back({ n2,cost });
        //v[n2].push_back({ n1,cost });
    }

    int start, dest;
    cin >> start >> dest;

    // 최단거리 구하기
    dijkstra(start);
    cout << dist[dest] << '\n';


    // 경로 출력
    vector<int> ans;
    int idx = dest;

    while (idx != start) {
        ans.push_back(idx);
        idx = routes[idx];
    }
    cout << ans.size()+1 << '\n';
    cout << start << ' ';
    for (int i = ans.size()-1;i >= 0;i--) cout << ans[i] << ' ';
} 