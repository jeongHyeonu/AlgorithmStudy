#include <iostream>
#include <queue>
#define INF 999999
using namespace std;

int N, ans=INF;
bool separated[11];
int ingu[11];
vector<int> v[11];

bool isAble(int cnt, bool isSep) { // 구역 분리횟수 , 분리여부
    queue<int> q;
    int sepCnt = 0;
    bool visited[11] = { false, };

    // 분리된 임의의 구역 찾고 큐에 넣는다
    for (int i = 1;i <= N;i++) {
        if (separated[i]==isSep) {
            q.push(i);
            visited[i] = true;
            sepCnt++;
            break;
        }
    }
    // 분리된 구역 탐색
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0;i < v[cur].size();i++) {
            int nxt = v[cur][i];
            if (!visited[nxt] && separated[nxt]==isSep) {
                q.push(nxt);
                sepCnt++;
                visited[nxt] = true;
            }
        }
    }
    if (cnt == sepCnt) return true;
    else return false;
}

// 인구수 차이 계산
void calculate() {
    int sum = 0;
    for (int i = 1;i <= N;i++) {
        if (separated[i]) sum += ingu[i];
        else sum -= ingu[i];
    }
    ans = min(ans,abs(sum));
}

// 조합 생성 및 계산
void solve(int idx, int cnt) {
    if (cnt >= 1 && isAble(cnt, true) && isAble(N-cnt, false)) {
        calculate();
    }
    for (int i = idx+1;i <= N;i++) {
        if (separated[i]) continue;
        separated[i] = true;
        solve(idx, cnt + 1);
        separated[i] = false;
    }
}

void input() {
    cin >> N;

    for (int i = 1;i <= N;i++) cin >> ingu[i];

    int t1;
    int t2;
    for (int i = 1;i <= N;i++) {
        cin >> t1;
        while (t1--) {
            cin >> t2;
            v[i].push_back(t2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    solve(1,0);

    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}
