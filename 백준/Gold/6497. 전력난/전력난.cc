#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N;
int total;
int parents[200010];
vector<pair<int,pair<int, int>>> v;

int find(int a) {
    if (parents[a] == a) return a;
    return parents[a] = find(parents[a]);
}

void unionNode(int a, int b) {
    a = find(a);
    b = find(b);
    parents[b] = a;
}

void solve() {
    sort(v.begin(), v.end());

    int sum = 0;
    for (int i = 0;i < N;i++) {
        int a = v[i].second.first;
        int b = v[i].second.second;
        if (find(a) != find(b)) {
            unionNode(a, b);
            sum += v[i].first;
        }
    }

    cout << total - sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (1) {
        cin >> M >> N;
        if (M == 0 && N == 0) break;

        v.clear();
        int a, b, c;
        total = 0;
        for (int i = 0;i < N;i++) {
            cin >> a >> b >> c;
            total += c;
            v.push_back({ c,{a,b} });
        }

        for (int i = 0;i <= M;i++) parents[i] = i;
        solve();
    }


    return 0;
}