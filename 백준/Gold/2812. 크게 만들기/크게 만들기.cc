#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, K, cnt = 0;
string input;
stack<int> s;
vector<int> ans;

int main()
{
    cin >> N >> K;
    cin >> input;

    for (int i = 0;i < N;i++) {
        int num = input[i] - '0';
        while (!s.empty() && s.top() < num && cnt < K) {
            cnt++;
            s.pop();
        }
        s.push(num);
    }
    while (cnt < K) {
        cnt++; s.pop();
    }
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    for (int i = ans.size() - 1;i >= 0;i--) cout << ans[i];

}