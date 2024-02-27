#include <iostream>
#include <vector>
using namespace std;

int N;
char arr[6][6];

vector<pair<int, int>> emptySpace;
vector<pair<int, int>> teachers;

bool checkAnswer() { //  선생님이 학생을 감지할 수 있는지 검사
    int x,y, next_x, next_y;
    for (auto t : teachers) {
        x = t.second;
        y = t.first;
        next_x = t.second;
        while (next_x < N - 1) {
            next_x++;
            if (arr[y][next_x] == 'O') break;
            else if (arr[y][next_x] == 'S') return false;
        }
        next_x = t.second;
        while (next_x > 0) {
            next_x--;
            if (arr[y][next_x] == 'O') break;
            else if (arr[y][next_x] == 'S') return false;
        }
        next_y = t.first;
        while (next_y < N - 1) {
            next_y++;
            if (arr[next_y][x] == 'O') break;
            else if (arr[next_y][x] == 'S') return false;
        }
        next_y = t.first;
        while (next_y > 0) {
            next_y--;
            if (arr[next_y][x] == 'O') break;
            else if (arr[next_y][x] == 'S') return false;
        }
    }
    return true;
};

void dfs(int cnt) {
    if (cnt == 3) { // 장애물을 3개 놓았을때, 선생님이 학생을 감지할 수 있는지 검사
        int discoverCount = 0;
        if (checkAnswer()) { cout << "YES"; exit(0); }
        else return;
    }
    for (auto e : emptySpace) {
        if (arr[e.first][e.second] == 'O') continue;
        arr[e.first][e.second] = 'O';
        dfs(cnt + 1);
        arr[e.first][e.second] = 'X';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'X') emptySpace.push_back({ i,j });
            else if (arr[i][j] == 'T') teachers.push_back({ i,j });
        }
    }

    dfs(0);

    // dfs 했을때, 감지 가능하면 YES / 아니면 NO
    cout << "NO";

    return 0;
}