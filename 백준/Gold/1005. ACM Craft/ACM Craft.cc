#include <iostream>
#include <vector>
#include <queue>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int t, n, k, w, num1,num2;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        int times[1003];
        int results[1003];
        vector<int> arr[1003];
        int require_cnt[1003] = { 0, };

        cin >> n >> k;
        for (int i = 1;i <= n;i++) cin >> times[i];
        for (int i = 1;i <= k;i++) {
            cin >> num1 >> num2;
            arr[num1].push_back(num2);
            require_cnt[num2]++;
        }
        cin >> w;
        for (int i = 1;i <= n;i++) {
            if (require_cnt[i] == 0) q.push(i);
            results[i] = times[i];
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0;i < arr[cur].size();i++) {
                int next = arr[cur][i];
                require_cnt[next]--;
                results[next] = MAX(results[next], results[cur] + times[next]);
                if (require_cnt[next] == 0) q.push(next);
            }
        }
        cout << results[w] << '\n';
    }

    return 0;
}