#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, pair<int, int>>> v;
int parent[1002];

int find(int x) {
    if (parent[x] == x) return parent[x];
    else return find(parent[x]);
}

void unionNode(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b) parent[a] = b;
    else parent[b] = a;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N >> M;

    for (int i = 1;i <= N;i++) parent[i] = i;

    int a, b, c;
    for (int i = 0;i < M;i++) {
        cin >> a >> b >> c;
        v.push_back({ c,{a,b} });
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    int sum = 0;
    for (int i = 0;i < M;i++) {
        a = find(v[i].second.first);
        b = find(v[i].second.second);
        if (a != b) {
            unionNode(a, b);
            sum += v[i].first;
            cnt++;
            if (cnt == N - 1) break;
        }
    }

    cout << sum;
    return 0;
}