#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s1, s2, temp;
	string ans = "";

    cin >> s1 >> s2;

	for (int i = 0;i < s1.size();i++) {
		ans += s1[i];
		if (s1[i] == s2.back() && ans.size() >= s2.size()) {
			temp = "";

			int _len = ans.size() - s2.size();
			for (int j = ans.size() - 1;j >= _len;j--) {
				temp = ans[j] + temp;
			}
			
			if (temp == s2) ans.erase(ans.size()-s2.size(), s2.size());
		}
	}
	if (ans.empty()) ans = "FRULA";
	cout << ans;
}
