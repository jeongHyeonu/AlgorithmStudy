#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

//int N, M,temp;
//int arr[201][201];
//int p[201];
//
//int find_parent(int x) {
//    if (p[x] != x) return p[x] = find_parent(p[x]);
//    return x;
//}
//
//void union_parent(int x, int y) {
//    x = find_parent(x);
//    y = find_parent(y);
//    if (x < y) p[y] = x;
//    else p[x] = y;
//}

string temp;
int N, M;
map<string, int> m;
vector<pair<pair<int, int>, string>> v;

bool cmp(pair<pair<int,int>,string> a, pair<pair<int, int>, string> b) {
    if (a.first.first == b.first.first) {
        if (a.first.second == b.first.second) return a.second < b.second;
        else return a.first.second > b.first.second;
    }
    else return a.first.first > b.first.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0;i < N;i++) {
        cin >> temp;
        if (temp.size() >= M) {
            m[temp]++;
        }
    }
    for (auto i = m.begin();i != m.end();i++) {
        v.push_back({ { i->second, i->first.size() }, i->first });
    }
    sort(v.begin(), v.end(),cmp);
    for (int i = 0;i < v.size();i++) cout << v[i].second << '\n';
}