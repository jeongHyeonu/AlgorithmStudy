#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;

bool cmp(pair<int, int> v1, pair<int, int> v2) {
    if (v1.second == v2.second) {
        return v1.first < v2.first;
    }
    return v1.second < v2.second;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    int a, b;
    for (int i = 0;i < N;i++) {
        cin >> a >> b;
        v.push_back({ a,b });
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0;i < 10000000;i++) {
        int spendTime = i;
        for (int j = 0;j < N;j++) {
            spendTime += v[j].first;
            if (spendTime > v[j].second) {
                cout << i - 1;
                exit(0);
            }
        }
    }

    return 0;
}