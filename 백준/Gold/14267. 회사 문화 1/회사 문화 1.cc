#include <iostream>
#include <vector>
using namespace std;


vector<int> v[100002];
int praise[100002] = { 0 };

void dfs(int cur) {
    for (int i = 0;i < v[cur].size();i++) {
        int nxt = v[cur][i];
        praise[nxt] += praise[cur];
        dfs(nxt);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    int temp;
    for (int i = 1;i <= N;i++) {
        cin >> temp;
        if (temp != -1) v[temp].push_back(i);
    }

    int idx, weight;
    for (int j = 0;j < M;j++) {
        cin >> idx >> weight;
        praise[idx] += weight;
    }

    dfs(1);

    for (int i = 1;i <= N;i++) cout << praise[i] << ' ';

    return 0;
}