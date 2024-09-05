#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int>> v;

// 날짜를 월/일 형식에서 일수로 변환하는 함수
int leftDays(int m, int d) {
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int totalDays = 0;
    for (int i = 0; i < m - 1; i++) {
        totalDays += days[i];
    }
    return totalDays + d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int a, b, c, d;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c >> d;
        int from = leftDays(a, b);
        int to = leftDays(c, d);
        v.push_back({ from, to });
    }

    // 시작 날짜를 기준으로 정렬
    sort(v.begin(), v.end());

    int startDay = leftDays(3, 1);  // 3월 1일
    int endDay = leftDays(11, 30);  // 11월 30일

    // 정원을 덮을 수 있는 기간 동안
    int ans = 0;
    int maxEndDay = 0;
    int i = 0;
    while (startDay <= endDay) {
        bool found = false;

        // 현재 startDay를 덮을 수 있는 꽃들 중 가장 긴 기간을 선택
        while (i < N && v[i].first <= startDay) {
            maxEndDay = max(maxEndDay, v[i].second);
            i++;
            found = true;
        }

        if (!found) {
            // 더 이상 덮을 수 있는 꽃이 없으면 실패
            cout << 0;
            return 0;
        }

        // 새로운 꽃을 추가하여 범위를 확장
        startDay = maxEndDay;
        ans++;

        // 모든 기간이 덮이면 종료
        if (startDay > endDay) break;
    }

    cout << ans;
}