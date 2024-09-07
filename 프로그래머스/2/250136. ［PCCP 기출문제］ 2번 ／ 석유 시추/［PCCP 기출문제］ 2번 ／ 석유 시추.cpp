#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

vector<vector<int>> maps;
map<int, int> cntMap;
int visited[501][501];
int n, m;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int depth = 1;

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[y][x] = true;
    int cnt = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        maps[cy][cx] = depth;
        cnt++;
        q.pop();

        for (int i = 0;i < 4;i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (visited[ny][nx] || maps[ny][nx]==0) continue;

            visited[ny][nx] = true;
            q.push({ nx,ny });
        }
    }

    cntMap[depth] = cnt;
    depth++;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size(); // 열의 길이
    m = land[0].size(); // 행의 길이

    maps = land;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && maps[i][j] > 0)
                BFS(i, j);
        }
    }

    for (int i = 0; i < m; i++) {
        int sum = 0;
        set<int> s;
        for (int j = 0; j < n; j++) {
            s.insert(maps[j][i]);
        }
        for (auto i : s) {
            sum += cntMap[i];
        }
        answer = max(answer, sum);
    }
    return answer;
}
