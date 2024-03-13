#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define MAX(a,b)(((a)>(b))?(a):(b))
#define MIN(a,b)(((a)<(b))?(a):(b))

using namespace std;
map<string,bool> applicants;
string s;
char c;
int n, cnt=1, m, ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> c;
	
	switch (c) {
	case 'Y':
		m = 2;
		break;
	case 'F':
		m = 3;
		break;
	case 'O':
		m = 4;
		break;
	}

	for (int i = 0;i < n;i++) {
		cin >> s;
		if (applicants[s] == false) { 
			applicants[s] = true, cnt++; 
			if (cnt == m) {
				ans++;
				cnt = 1;
			}
		}
		else continue;
	}

	cout << ans;
	return 0;
}