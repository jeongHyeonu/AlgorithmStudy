#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

bool isEqual(int a, int b, int c) {
    if (a == b && b == c) return true;
    else return false;
}

int solution(vector<string> board) {

    int answer = 1;

    int xCnt = 0, oCnt = 0;
    int xwin = 0, owin = 0;

    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (board[i][j] == 'O') oCnt++;
            else if(board[i][j]=='X') xCnt++;

    // 가로
    for (int i = 0;i < 3;i++) {
        if (board[i][0] != '.' && isEqual(board[i][0], board[i][1], board[i][2])) {
            if (board[i][0] == 'X') xwin++;
            else owin++;
        }
    }

    // 세로
    for (int i = 0;i < 3;i++) {
        if (board[0][i] != '.' && isEqual(board[0][i], board[1][i], board[2][i])) {
            if (board[0][i] == 'X') xwin++;
            else owin++;
        }
    }
    
    // 대각선
    if (board[1][1] != '.') {
        if (isEqual(board[0][0], board[1][1], board[2][2]))
            if (board[1][1] == 'X') xwin++;
            else owin++;
        if (isEqual(board[2][0], board[1][1], board[0][2]))
            if (board[1][1] == 'X') xwin++;
            else owin++;
    }

    if (owin > 0 && xwin > 0) answer = 0;

    if (abs(xCnt - oCnt) > 1) answer = 0;

    if (xCnt > oCnt) answer = 0;

    if (owin > 0 && oCnt != xCnt + 1) answer = 0;

    if (xwin > 0 && oCnt != xCnt) answer = 0;

    return answer;
}

