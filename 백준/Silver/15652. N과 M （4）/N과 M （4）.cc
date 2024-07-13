#include <iostream>
#include <vector>
#include <queue>
#define INF 9999999
using namespace std;

int N, M;
vector<int> v;

void dfs(int n, int cnt) {
    if (cnt == M) {
        for (int i = 0;i < v.size();i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = n;i <= N;i++) {
        v.push_back(i);
        dfs(i, cnt + 1);
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1;i <= N;i++) {
        v.push_back(i);
        dfs(i, 1);
        v.pop_back();
    }
}