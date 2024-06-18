#include <iostream>
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;
int n, m, h;
int maxCnt = 0;
bool ladder[31][11];

bool check_ladder() {
    for (int i = 1;i <= n;i++) {
        int temp = i;
        for (int j = 1;j <= h;j++) {
            if (ladder[j][temp]) temp++;
            else if (ladder[j][temp - 1]) temp--;
        }
        if (temp != i) return false;
    }
    return true;
}

void dfs(int cnt,int y) {
    // 사다리 더 이을 수 없는 경우
    if (cnt == maxCnt) {
        if (check_ladder()) { cout << cnt; exit(0); }
        else return;
    }

    //사다리 잇기
    for (int i = y;i <= h;i++) {
        for (int j = 1;j <= n;j++) {
            // 자기자신 또는 옆에 사다리 있으면 dfs 하지 않음
            if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1]) continue;

            ladder[i][j] = true;
            dfs(cnt+1,i);
            ladder[i][j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> h;

    int a, b;
    for (int i = 0;i < m;i++) {
        cin >> a >> b;
        ladder[a][b] = true;
    }

    for (int i = 0;i < 4;i++) {
        dfs(0,1); maxCnt++;
    }

    cout << -1;
}