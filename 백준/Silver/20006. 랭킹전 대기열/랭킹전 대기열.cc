#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define MAX(a,b)(((a)>(b))?(a):(b))
#define ABS(a)(((a)<0)?-(a):(a))
using namespace std;

int p, m,l,idx=0;
string n;
bool isAdded;
map<int, vector<pair<int, string>>> room;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> p >> m;

	for (int i = 0;i < p;i++) {
		cin >> l >> n;
		isAdded = false;

		if (i == 0) {
			room[idx++].push_back({ l,n }); 
			continue;
		}

		for (auto r = room.begin();r != room.end();r++) {
			if (r->second.size() >= m) continue;
			if (r->second[0].first >= l - 10 && r->second[0].first <= l + 10) {
				r->second.push_back({ l,n });
				isAdded = true;
				break;
			}
		}
		if (isAdded) continue;
		room[idx++].push_back({ l,n });
	}

	for (int i = 0;i < idx;i++) sort(room[i].begin(), room[i].end(), cmp);

	for (auto r = room.begin();r != room.end();r++) {
		if (r->second.size() == m) {
			cout << "Started!" << '\n';
			for (int i = 0;i < r->second.size();i++) cout << r->second[i].first << ' ' << r->second[i].second << '\n';
		}
		if (r->second.size() < m) {
			cout << "Waiting!" << '\n';
			for (int i = 0;i < r->second.size();i++) cout << r->second[i].first << ' ' << r->second[i].second << '\n';
		}
	}
}
