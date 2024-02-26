#include <iostream>
#define COMPARE(a,b)(((a)<(b)) ? (a)-(b) : (b)-(a) )
using namespace std;

int H, W, X, Y;
int arr[601][601];

// 내 힘으로 시도해봤지만 풀지 못했다..
// 배열 한 4개 만들고 비교하고 if문 써서 해결할 줄 알았는데,
// 다른 블로그 보니깐 간단하게 풀 수 있더라..
// 쉬운 문제인데 어렵게 푸느라 삽질 열심히 했다... 반성해야겠다

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> H >> W >> X >> Y;

    for (int i = 0;i < H+X;i++) {
        for (int j = 0;j < W+Y;j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = X;i < H + X;i++) {
        for (int j = Y;j < W + Y;j++) {
            arr[i][j] -= arr[i-X][j-Y];
        }
    }


    for (int i = 0;i < H;i++) {
        for (int j = 0;j < W;j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}