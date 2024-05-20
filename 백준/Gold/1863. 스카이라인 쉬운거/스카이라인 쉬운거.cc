#include <iostream>
#include <stack>
using namespace std;

int N,num1,num2, temp,ans;
stack<int> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0;i < N;i++) {
        cin >> num1 >> num2;
        while (!s.empty() && s.top() > num2) {
            s.pop();
        }
        if (num2!=0 && (s.empty() || s.top() < num2)) {
            ans++;
            s.push(num2);
        }
    }

    cout << ans;
}