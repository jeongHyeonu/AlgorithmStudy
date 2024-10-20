#include <iostream>
#include <vector>
using namespace std;
int N, M, K;
int parents[1002];
vector<pair<int,pair<int,int>>> v;

int find(int x) {
    if (parents[x] == x) return x;
    else return parents[x] = find(parents[x]);
}

void unionNode(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b) parents[b] = a;
    else parents[a] = b;
}

int findMST() {
    for (int i = 1;i <= N;i++) parents[i] = i;
    int sum = 0;
    int cnt = 0;
    for (int i = 0;i < v.size();i++) {
        int n1 = find(v[i].second.first);
        int n2 = find(v[i].second.second);
        if (n1 != n2) {
            unionNode(n1, n2);
            sum += v[i].first;
            cnt++;
        }
    }
    if (cnt != N-1) return -1;
    return sum;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;


    int n1, n2;
    for (int i = 1;i <= M;i++) {
        cin >> n1 >> n2;
        v.push_back({ i,{n1,n2} });
    }

    int sum = 0;
    for (int i = 0;i < K;i++) {
        if (sum == -1) cout << '0' << ' ';
        else {
            sum = findMST();
            if (sum == -1) cout << '0' << ' ';
            else cout << sum << ' ';
            v.erase(v.begin());
        }
    }

    return 0;
}