#include <iostream>
#include <vector>


using namespace std;
int N, M;
int parents[300001];


int find(int x) {
    if (parents[x] == x) return x;
    else return find(parents[x]);
}

void union_node(int a, int b) {
    a = find(a);
    b = find(b);
    if (b > a) parents[b] = a;
    else parents[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int a, b;

    for (int i = 1;i <= N;i++) parents[i] = i;

    for (int i = 1;i <= N-2;i++) {
        cin >> a >> b;
        union_node(a, b);
    }

    for (int i = 1;i <= N;i++) {
        int island = find(i);
        if (island != 1) {
            cout << '1' << ' ' << island;
            exit(0);
        }
    }

    return 0;
}

