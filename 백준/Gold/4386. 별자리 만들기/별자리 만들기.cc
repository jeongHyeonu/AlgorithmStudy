#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int n;
int parents[101];
double input_x[101], input_y[101];
vector<pair<double, pair<int,int>>> v;

int find(int x) {
    if (parents[x] == x) return x;
    else return find(parents[x]);
}

void unionNode(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b) parents[b] = a;
    else parents[a] = b;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cout.precision(2);
    cout << fixed;

    // 입력 받기
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> input_x[i];
        cin >> input_y[i];
    }

    // 별의 부모는 자기자신으로
    for (int i = 1;i <= n;i++) parents[i] = i;

    // 중복x 조합
    for (int i = 0;i < n-1;i++) {
        for (int j = i+1;j < n;j++) {
            double dist = sqrt(pow(input_x[i] - input_x[j], 2) + pow(input_y[i] - input_y[j], 2));
            v.push_back({ dist,{i+1,j+1} });
        }
    }

    sort(v.begin(), v.end());

    double ans = 0;
    int cnt = 0;
    for (int i = 0;i < v.size();i++) {
        double dist = v[i].first;
        int s = v[i].second.first;
        int e = v[i].second.second;

        if (find(s) != find(e)) {
            unionNode(s, e);
            ans += dist;
            cnt++;
            if (cnt == n - 1) break; // 별자리 다 이은 경우 break
        }
    }

    cout << ans;

    return 0;
}