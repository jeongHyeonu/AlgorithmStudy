#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#define MAX(a,b)(((a)>(b))?(a):(b))

using namespace std;

char ch;
string str, temp;
int ans;
bool isMinus;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;

	for (int i = 0;i < str.size()+1;i++) {
		if (str[i] == '-' || str[i] == '+' || str[i] == '\0') {
			if (isMinus) ans -= stoi(temp);
			else ans += stoi(temp);
			temp = "";
		}
		else temp.push_back(str[i]);
		if (str[i] == '-') {
			isMinus = true;
		}
	}

	cout << ans;

	//cout << stoi(str);
}
