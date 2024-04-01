#include <iostream>
#include <algorithm>
using namespace std;

string S,T;

void dfs(string s, string t) {
	//cout << "[debugging] : " << t << '\n';
	
	//if (s.size() == t.size()) {
	//	if (s == t) { cout << "1"; exit(0); }
	//	else return;
	//}

	//s.append("A");
	//dfs(s,t);
	//s.erase(s.size()-1);

	//s.append("B");
	//reverse(s.begin(), s.end());
	//dfs(s, t);

	if (s == t) {
		cout << "1"; exit(0);
	}
	if (s.size() >= t.size()) return;

	if (t[t.size() - 1] == 'A') {
		string temp = t;
		temp.erase(temp.size() - 1);
		dfs(s, temp);
	}
	if (t[0] == 'B') {
		string temp = t;
		reverse(temp.begin(), temp.end());
		temp.erase(temp.size()-1);
		dfs(s, temp);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> S;
	cin >> T;

	dfs(S, T);
	cout << "0";

	return 0;
}
