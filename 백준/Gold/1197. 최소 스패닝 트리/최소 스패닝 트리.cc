#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parents[10001];
int V, E;
int result = 0;
vector <pair<int, pair<int, int>>> v;

int find(int x) {
    if (parents[x] == x) return x;
    return parents[x] = find(parents[x]);
}

void union_node(int a, int b) {
    int n1 = find(a);
    int n2 = find(b);
    if (n1 != n2) parents[n2] = n1;
}

bool isCycle(int a, int b) {
    int n1 = find(a);
    int n2 = find(b);
    if (n1 == n2) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> V >> E;

    for (int i = 1;i <= V;i++) parents[i] = i;

    int n1, n2, cost;
    for (int i = 0;i < E;i++) {
        cin >> n1 >> n2 >> cost;
        v.push_back({ cost,{n1,n2} });
    }

    sort(v.begin(), v.end());

    for (int i = 0;i < E;i++) {
        int n1 = v[i].second.first;
        int n2 = v[i].second.second;
        if (!isCycle(n1,n2)) {
            result += v[i].first;
            union_node(n1, n2);
        }
    }

    cout << result;

    return 0;
}