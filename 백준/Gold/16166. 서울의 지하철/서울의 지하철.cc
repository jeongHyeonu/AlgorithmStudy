#include <iostream>
#include <queue>
#include <vector>
using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K, dest;
    queue<pair<int, int>> q;
    vector<int> v[11];
    bool visited[11] = { 0, };

    // 입력 받기
    cin >> N;
    int a;
    for (int i = 0;i < N;i++) {
        cin >> K;
        for (int j = 0;j < K;j++) {
            cin >> a;
            v[i].push_back(a);
            if (a == 0) q.push({i,0});
        }
    }
    cin >> dest;


    // bfs
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        visited[cur] = true;

        for (int i = 0;i < v[cur].size();i++) { // 현재 호선의 역 수만큼 반복
            if (v[cur][i] == dest) { // 도착역인 경우
                cout << cnt;
                return 0;
            }
            for (int j = 0;j < N;j++) { // 다른 호선과 비교
                if (cur == j) continue;
                for (int k = 0;k < v[j].size();k++) {
                    // 다음 역이 해당 호선을 방문하지 않았고, 교차되면 queue에 넣고 탐색
                    if (!visited[j] && v[cur][i] == v[j][k]) q.push({ j,cnt + 1 });
                }
            }
        }
    }

    // 도착역에 도달 못하는경우
    cout << -1;

    return 0;
}