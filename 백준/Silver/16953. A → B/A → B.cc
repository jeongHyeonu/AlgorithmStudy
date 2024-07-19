#include <iostream>
#define MIN(a,b)(((a)<(b))?(a):(b))
#define INF 1000000001
using namespace std;

long A, B, ans=INF;

void dfs(long n, int cnt) {
    if (n > B) return;
    if (n == B) { ans = MIN(cnt, ans); return; }
    dfs(n * 2, cnt + 1);
    dfs((n * 10) + 1, cnt + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B;

    dfs(A, 1);

    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}