#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int X, A;
    long long sum = 0;
    for (int i = 0;i < N;i++) {
        cin >> X >> A;
        v.push_back({ X,A });
        sum += A;
    }

    sort(v.begin(), v.end());

    long long temp = 0;
    for (int i = 0;i < v.size();i++) {
        temp += v[i].second;
        if (temp >= (sum + 1) / 2) {
            cout << v[i].first;
            break;
        }
    }
} 