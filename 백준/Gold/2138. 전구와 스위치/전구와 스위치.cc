#include <iostream>
#define CHANGE(a)(((a)=='0') ? '1' : '0' )
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

int N, ans=100000;
string s1, s2,backup;

void greedy_solve(string &target, int idx, int cnt) {
    if (idx == N) {
        if (target[N-1] == s2[N-1]) ans = MIN(cnt, ans);
        return;
    }
    if (target[idx - 1] == s2[idx - 1]) {
        greedy_solve(target, idx+1, cnt);
    }
    else {
        target[idx - 1] = CHANGE(target[idx - 1]);
        target[idx] = CHANGE(target[idx]);
        if(target[idx+1]!=N) target[idx + 1] = CHANGE(target[idx + 1]);
        greedy_solve(target, idx + 1, cnt + 1);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> s1 >> s2;

    backup = s1;    
    greedy_solve(s1, 1,0);

    
    if (ans == 100000) {
        s1 = backup;
        s1[0] = CHANGE(s1[0]);
        s1[1] = CHANGE(s1[1]);
        greedy_solve(s1, 1, 1);
    }

    if (ans == 100000) cout << -1;
    else cout << ans;

    return 0;
}