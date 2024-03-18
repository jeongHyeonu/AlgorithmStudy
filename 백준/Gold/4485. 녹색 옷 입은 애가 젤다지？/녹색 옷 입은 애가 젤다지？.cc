#include <iostream>
#include <queue>

using namespace std;

int N;
int A[125][125];
int d[125][125];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dijstra() {
    priority_queue<pair<int, pair<int, int>>> pq;

    pq.push({ -A[0][0],{0,0} });
    d[0][0] = A[0][0];

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;

        pq.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (d[ny][nx] <= cost + A[ny][nx]) continue;

            d[ny][nx] = cost + A[ny][nx];
            pq.push({ -d[ny][nx],{ny,nx} });
        }
    }
}

void solution(int problem) {
    dijstra();
    cout << "Problem " << problem << ": " << d[N-1][N-1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int i = 1;
    while (1) {
        cin >> N;
        if (!N) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> A[i][j];
                d[i][j] = 987654321;
            }
        }

        solution(i++);
    }

    return 0;
}