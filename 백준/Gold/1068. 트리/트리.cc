#include <iostream>
#include <vector>
int ans = 0;
int root, cutNode;

using namespace std;
vector<int> v[51];
bool visited[51];

void dfs(int x) {
    if (visited[x]) return;
    visited[x] = true;

    if (v[x].size() == 0 || (v[x].size() == 1 && v[x][0] == cutNode) ) ans++;

    for (int i = 0;i < v[x].size();i++) {
        int nxt = v[x][i];
        if (nxt != cutNode) dfs(nxt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, num;

    cin >> N;
    for (int i = 0;i < N;i++) {
        cin >> num;
        if (num == -1) {
            root = i;
        }
        else {
            v[num].push_back(i);
        }
    }

    cin >> cutNode;
    if (cutNode == root) {
        cout << 0; 
        exit(0);
    }

    dfs(root);

    cout << ans;

    return 0;
}