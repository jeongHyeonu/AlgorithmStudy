#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MIN(a,b)((a)<(b))?(a):(b)
using namespace std;

int T,N;
vector<string> v;

void check_parse(string s) {
    int temp = 0;
    int sum = 0;
    char temp_char = '+';

    for (int i = 0;i < s.length()-1;i++) {
        if (s[i] >= '0' && s[i]<='9') {
            temp *= 10;
            temp += (s[i] - '0');
        }
        if (s[i] == '+' || s[i]=='-') {
            if (temp_char == '+') {
                sum += temp;
            }
            if (temp_char == '-') {
                sum -= temp;
            }
            temp = 0;
            temp_char = s[i];
        }
    }

    temp *= 10;
    temp += (s[s.length()-1] - '0');

    if (temp_char == '+') sum += temp;
    else sum -= temp;

    if (sum == 0) v.push_back(s);
}


void dfs(string s, int cnt) {
    if (cnt == N) {
        check_parse(s);
    }
    if (cnt < N) {
        dfs(s + '+' + to_string(cnt + 1), cnt + 1);
        dfs(s + '-' + to_string(cnt + 1), cnt + 1);
        dfs(s + ' ' + to_string(cnt + 1), cnt + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        dfs("1",1);
        sort(v.begin(), v.end());
        for (int i = 0;i < v.size();i++) cout << v[i] << '\n';
        v.clear();
        cout << '\n';
    }
}