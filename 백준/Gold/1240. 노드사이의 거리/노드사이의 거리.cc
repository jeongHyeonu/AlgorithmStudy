#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> v[1001];

int findWay(int s, int e) {
    queue<pair<int, int>> q;
    bool visited[1001] = { 0 };
    q.push({ s,0 });

    while (!q.empty()) {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        visited[cur] = true;

        for (int i = 0;i < v[cur].size();i++) {
            int nxt = v[cur][i].first;
            int nDist = v[cur][i].second + dist;
            if (visited[nxt]) continue;
            if (nxt == e) return nDist;
            q.push({ nxt,nDist });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int s, e, d;
    for (int i = 0;i < N - 1;i++) {
        cin >> s >> e >> d;
        v[s].push_back({ e,d });
        v[e].push_back({ s,d });
    }

    for (int i = 0;i < M;i++) {
        cin >> s >> e;
        cout << findWay(s,e) << '\n';
    }

    return 0;
}