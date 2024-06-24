#include <iostream>
#include <vector>
#include <queue>
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;

int n, m, ans = 99999;
int arr1[8][8];
int arr2[8][8];
vector<pair<pair<int,int>, pair<int, int>>> v; //   { {CCTV 타입, 회전 수 } , { y, x } }

void input() {
    cin >> n >> m;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> arr1[i][j];
            if (arr1[i][j] >= 1 && arr1[i][j] <= 5) {
                v.push_back({ {arr1[i][j],0 },{ i,j } });
            }
        }
    }
}

// 0:오른쪽 , 1:왼쪽 , 2:위 , 3:아래
void find(int dir, int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= m) return;
    if (arr2[y][x]==6) return;
    if (arr2[y][x] == 0) arr2[y][x] = '#';

    if (dir == 0) find(dir, y, x + 1);
    else if (dir == 1) find(dir, y, x - 1);
    else if (dir == 2) find(dir, y - 1, x);
    else if (dir == 3) find(dir, y + 1, x);
}

void copy_arr() {
    for (int i = 0;i < n;i++) for (int j = 0;j < m;j++) arr2[i][j] = arr1[i][j];
}

int solve() {
    copy_arr();
    int sum = 0;

    for (int i = 0;i < v.size();i++) {
        int y = v[i].second.first;
        int x = v[i].second.second;
        switch (v[i].first.first) {
        case 1:
            if (v[i].first.second == 0) find(0, y, x);
            else if (v[i].first.second == 1) find(1, y, x);
            else if (v[i].first.second == 2) find(2, y, x);
            else if (v[i].first.second == 3) find(3, y, x);
            break;
        case 2:
            if (v[i].first.second == 0 || v[i].first.second == 1) {
                find(0, y, x), find(1, y, x);
            }
            if (v[i].first.second == 2 || v[i].first.second == 3) {
                find(2, y, x), find(3, y, x);
            }
            break;
        case 3:
            if (v[i].first.second == 0) {
                find(0, y, x), find(2, y, x);
            }
            if (v[i].first.second == 1) {
                find(0, y, x), find(3, y, x);
            }
            if (v[i].first.second == 2) {
                find(1, y, x), find(3, y, x);
            }
            if (v[i].first.second == 3) {
                find(1, y, x), find(2, y, x);
            }
            break;
        case 4:
            if (v[i].first.second == 0) {
                find(0, y, x), find(1, y, x), find(2, y, x);
            }
            if (v[i].first.second == 1) {
                find(0, y, x), find(2, y, x), find(3, y, x);
            }
            if (v[i].first.second == 2) {
                find(0, y, x), find(1, y, x), find(3, y, x);
            }
            if (v[i].first.second == 3) {
                find(1, y, x), find(2, y, x), find(3, y, x);
            }
            break;
        case 5:
            find(0, y, x), find(1, y, x), find(2, y, x), find(3, y, x);
            break;
        }
    }
    for (int i = 0;i < n;i++) for (int j = 0;j < m;j++) if (arr2[i][j] == 0) sum++;
    return sum;
}

void cctv_check(int cnt) {
    if (cnt == v.size()) {
        ans = MIN(ans, solve());
        return;
    }

    v[cnt].first.second = 0;
    cctv_check(cnt + 1);

    v[cnt].first.second = 1;
    cctv_check(cnt + 1);

    v[cnt].first.second = 2;
    cctv_check(cnt + 1);

    v[cnt].first.second = 3;
    cctv_check(cnt + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    cctv_check(0);

    cout << ans;
    return 0;
}
