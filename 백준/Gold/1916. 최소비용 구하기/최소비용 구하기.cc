#include <iostream>
#include <queue>
#define INF 99999999
#define MAX 1002
using namespace std;

vector<pair<int, int>> arr[MAX];
int dists[MAX];
int N, M;
int start, dest;

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    dists[start] = 0;
    pq.push({ 0, start });


    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        if (dists[cur_node] < cur_dist) continue;

        for (int i = 0;i < arr[cur_node].size();i++) {
            int next_node = arr[cur_node][i].first;
            int next_dist = cur_dist + arr[cur_node][i].second;

            if (dists[next_node] > next_dist) {
                dists[next_node] = next_dist;
                pq.push({ -next_dist,next_node });
            }
        }
    }

    cout << dists[dest];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0;i < MAX;i++) dists[i] = INF;

    int from, to, dist;
    for (int i = 0;i < M;i++) {
        cin >> from >> to >> dist;
        arr[from].push_back({ to, dist });
    }

    cin >> start >> dest;
    dijkstra();

    return 0;
}