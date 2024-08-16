#include <iostream>
#include <cstring>
#include <vector>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int N,M;
vector<pair<int, int>> nodes[100001];
bool visited[100001];
int maxSum = -1;
int maxNode = -1;

void dfs(int n, int sum) {
    
    visited[n] = true;
    if (maxSum < sum) {
        maxSum = sum;
        maxNode = n;
    }

    for (int i = 0;i < nodes[n].size();i++) {
        int nxt = nodes[n][i].first;
        if (visited[nxt]) continue;
        dfs(nxt, sum + nodes[n][i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int s, e, w;
    for (int i = 0;i < N;i++) {
        cin >> s;
        while (true) {
            cin >> e;
            if (e == -1) break;

            cin >> w;
            nodes[s].push_back({ e,w });
            nodes[e].push_back({ s,w });
        }
    }

    dfs(1,0);
    memset(visited, false, sizeof(visited));
    dfs(maxNode, 0);
    cout << maxSum;
} 