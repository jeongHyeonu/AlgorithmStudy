#include <iostream>
#include <string>
using namespace std;

int arr[201][201] = { 0, };
bool boom[201][201] = { 0, };
int R, C, N;

void result_print() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] >= 0) cout << "O";
            else cout << ".";
        }
        cout << endl;
    }
}

int main() {
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        // 폭탄 설치: 1, 빈칸: -1
        for (int j = 0; j < C; j++) {
            if (s[j] == '.') arr[i][j] = -1;
            else arr[i][j] = 1;
        }
    }

    int tick = 1;
    while (tick < N) {
        // 2. 폭탄 없는 나머지 공간 폭탄 설치, 폭탄 있는 공간엔 시간 감소
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (arr[i][j] >= 0) arr[i][j]--;
                else arr[i][j] = 1;
            }
        }
        tick++;
        if (tick >= N) break;

        // 3. 폭탄 폭발 및 연쇄 작용
        // 3-1. 폭발할 위치를 boom[][]에 기록
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (arr[i][j] == 0) boom[i][j] = true;
                else boom[i][j] = false;
            }
        }
        // 3-2. boom[][]에 체크된 위치에서 폭발을 수행
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (!boom[i][j]) continue;
                arr[i][j] = -1;
                if (i > 0) arr[i - 1][j] = -1;
                if (i < R) arr[i + 1][j] = -1;
                if (j > 0) arr[i][j-1] = -1;
                if (j < C) arr[i][j+1] = -1;
            }
        }
        tick++;
    }
    result_print();

    return 0;
}