#include <iostream>
#include <queue>
using namespace std;

int N, M,temp;
int arr[201][201];
int p[201];

int find_parent(int x) {
    if (p[x] != x) return p[x] = find_parent(p[x]);
    return x;
}

void union_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    if (x < y) p[y] = x;
    else p[x] = y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 1;i <= N;i++) p[i] = i;

    for (int i = 1;i <= N;i++) {
        for (int j = 1  ;j <= N;j++) {
            cin >> temp;
            if (temp == 1) union_parent(i, j);
        }
    }

    cin >> temp;
    int root = find_parent(temp);

    for (int i = 1;i < M;i++) {
        cin >> temp;
        if (root != find_parent(temp)) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}