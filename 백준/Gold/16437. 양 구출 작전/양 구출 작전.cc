#include <iostream>
#include <vector>

using namespace std;

int N;
long long nodes[123457];
vector<int> edges[123457];

long long dfs(int node) {
    long long val = 0;

    for (int i = 0;i < edges[node].size();i++) {
        val += dfs(edges[node][i]);
    }
    val += nodes[node];
    if (val < 0) val = 0;
    return val;
}

void solve() {
    cin >> N;

    char t;
    long long cnt;
    int nxt;
    for (int i = 2;i <= N;i++) {
        cin >> t >> cnt >> nxt;
        if (t == 'W') nodes[i] = -cnt;
        else nodes[i] = cnt;
        edges[nxt].push_back(i);
    }

    long long ans = dfs(1);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();

    return 0;
}