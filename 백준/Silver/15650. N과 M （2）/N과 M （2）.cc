#include <iostream>

using namespace std;
int N, M;
bool visited[9];

void dfs(int num, int cnt) {
    if (cnt == M) {
        for (int i = 1;i <= N;i++) if (visited[i]) cout << i << ' ';
        cout << '\n';
        return;
    }
    for (int i = num;i <= N;i++) {
        if (visited[i]) continue;

        visited[i] = true;
        dfs(i, cnt + 1);
        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    dfs(1,0);

    return 0;
}