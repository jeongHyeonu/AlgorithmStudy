#include <iostream>

using namespace std;
int N, M;
int vip[41];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0;i < M;i++) {
        cin >> vip[i];
    }

    int diffRef[41];
    diffRef[0] = diffRef[1] = 1;

    for (int i = 2;i <= N;i++) {
        diffRef[i] = diffRef[i-1] + diffRef[i-2];
    }


    int ans = 1, tmp=0;
    for (int i = 0;i < M;i++) {
        int diff = (vip[i] - tmp - 1);
        ans *= diffRef[diff];
        tmp = vip[i];
    }
    ans *= diffRef[N - tmp];
    cout << ans;

    return 0;
}