#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 99999
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

int N, M,temp;
int minBundle = INF;
int minOne = INF;
int case1, case2, case3;
int ans = INF;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0;i < M;i++) {
        cin >> temp;
        minBundle = MIN(minBundle, temp);
        cin >> temp;
        minOne = MIN(minOne, temp);
    }

    //case 1: 번들로만 구매
    case1 = ((N / 6) + 1) * minBundle;
    //case 2: 번들+낱개
    case2 = ((N / 6) * minBundle) + (N % 6) * minOne;
    //case 3: 낱개로만 구매
    case3 = N * minOne;

    ans = MIN(case1, case2);
    ans = MIN(ans, case3);

    cout << ans;
}