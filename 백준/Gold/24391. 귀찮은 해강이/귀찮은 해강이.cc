#include <iostream>
using namespace std;
int N, M;
int buildings[100001], codes[100001];

int find(int x) {
    if (x == buildings[x]) return x;
    return buildings[x] = find(buildings[x]);
}

void union_node(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b) buildings[a] = b;
    else buildings[b] = a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    // 각 노드 부모는 자기 자신으로 초기화
    for (int i = 0;i <= N;i++) buildings[i] = i;

    int a, b;
    for (int i = 0;i < M;i++) {
        cin >> a >> b;
        union_node(a, b);
    }

    int ans=-1, // 맨 처음 들어오는 경우는 세지 않음
        temp, // 입력받는값
        current=-1; // 현재 건물

    for (int i = 0;i < N;i++) {
        cin >> temp;
        int node = find(temp);

        if (node != current) {
            current = node;
            ans++;
        }
    }

    cout << ans;
}