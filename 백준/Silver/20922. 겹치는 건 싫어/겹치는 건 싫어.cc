#include <iostream>
#include <vector>
using namespace std;
#define MAX(a,b)(((a)>(b))?(a):(b))

int N, K, answer=0, st=0,en=0;
int arr[200001] = { 0, };
int cnt[100001] = { 0, };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0;i < N;i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
        while (cnt[arr[i]] > K) {
            cnt[arr[st++]]--;;
        }
        answer = max(answer, i - st + 1);
    }
    cout << answer;
    return 0;
}