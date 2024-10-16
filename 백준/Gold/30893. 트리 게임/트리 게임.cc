#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100002];
bool visited[100002];
int N, S, E;

// x : 노드 번호 , flag : 턴 플래그
bool dfs(int x, bool flag) {
    if (x == E) return true;
    visited[x] = true;

    int cnt = 0; // 간선 수
    bool isTarget = false;
    for (int i = 0;i < v[x].size();i++) {
        int nxt = v[x][i];
        if (visited[nxt]) continue;
        cnt++;
        isTarget |= dfs(nxt, !flag);
    }

    // 태호 턴에 다른 간선으로 이동하는 수가 2 이상이면 목표 노드에 도달할 수 없음
    if (!flag && cnt >= 2) return false;

    // 목표 노드에 도달했는지 여부 리턴
    return isTarget;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> S >> E; 

    int num1, num2;
    for (int i = 0;i < N - 1;i++) {
        cin >> num1 >> num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }

    if (dfs(S, true)) cout << "First";
    else cout << "Second";

    return 0;
}