#include <iostream>
#include <stack>
using namespace std;

string s;
stack<char> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for (int i = 0;i < s.length();i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') cout << s[i];
        else {
            if (s[i] == '(') {
                st.push(s[i]);
            }
            if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
            if (s[i] == '*' || s[i] == '/') {
                while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                    cout << st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            if (s[i] == '+' || s[i] == '-') {
                while (!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}