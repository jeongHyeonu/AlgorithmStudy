#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999999999;
using namespace std;
int N, M, K;

vector<pair<int, int>> cities[100001];
vector<int> interview;
long long ansDist = 0;
long long dist[100001];
int ansCity;
priority_queue<pair<long long, int>> pq;

void dijkstra() {
    for (int i = 1;i <= N;i++) dist[i] = INF;

    for (auto i: interview) {
        pq.push({ 0,i });
        dist[i] = 0;
    }

    while (!pq.empty()) {
        long long cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;
        
        for (int i = 0;i < cities[cur].size();i++) {
            long long nCost = cost + cities[cur][i].second;
            int nxt = cities[cur][i].first;
            if (dist[nxt] > nCost) {
                dist[nxt] = nCost;
                pq.push({ -nCost,nxt });
            }
        }
    }

    // 면접장 최단거리 중 가장 비용이 큰 거리 찾기
    ansDist = -1;
    for (int i = 1;i <= N;i++) 
        if (ansDist < dist[i]) { ansDist = dist[i], ansCity = i; }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    int u,v,c;
    for (int i = 0;i < M;i++) {
        cin >> u >> v >> c;
        cities[v].push_back({ u,c });
    }

    int temp;
    for (int i = 0;i < K;i++) {
        cin >> temp;
        interview.push_back(temp);
    }

    dijkstra();
    cout << ansCity << '\n' << ansDist;

    return 0;
}