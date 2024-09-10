#include <iostream>
#include <vector>
#include <map>
using namespace std;

string arr[1001];
map<string,int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    string temp;
    for (int i = 0;i < N;i++) {
        cin >> temp;
        m[temp] = i;
    }

    vector<string> v;
    for (int i = 0;i < N;i++) {
        cin >> temp;
        v.push_back(temp);
    }

    int cnt = 0;
    for (int i = 0;i < N;i++) {
        for (int j = i+1;j < N;j++) {
            if (m[v[i]] > m[v[j]]) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt;
    return 0;
}
