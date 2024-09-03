#include <iostream>
int arrows[1000001] = { 0 };  // 풍선 높이의 최대값이 1,000,000이므로 그 크기로 배열을 선언
int balloons[1000001];
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0;i < N;i++) cin >> balloons[i];
    int arrowCount = 0;

    for (int i = 0;i < N;i++) {
        int height = balloons[i];

        if (arrows[height] > 0) {
            // 이미 이 높이에 있는 화살이 있다면, 그 화살을 사용
            arrows[height]--;
            arrows[height - 1]++;
        }
        else {
            // 이 높이에 화살이 없으면 새로운 화살을 쏜다
            arrowCount++;
            arrows[height - 1]++;
        }
    }

    cout << arrowCount << endl;
}