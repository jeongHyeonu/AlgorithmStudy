#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

int N,K;
int lines[10002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> K >> N;

    long long l = 1;
    long long r = -1;
    for (int i = 0;i < K;i++) {
        cin >> lines[i];
        r = MAX(r, lines[i]);
    }

    long long mid = (l + r) / 2;
    int sum;
    while (l<=r) {
        sum = 0;
        for (int i = 0;i < K;i++) {
            sum += lines[i] / mid;
        }
        if (sum >= N) {
            l = mid + 1;
        }
        else if (sum < N) {
            r = mid - 1;
        }
        mid = (l + r) / 2;
    }
    cout << mid;
    return 0;
}
