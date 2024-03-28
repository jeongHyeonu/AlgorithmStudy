#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	char oper, ch;
	string s;

	cin >> s;
	cin >> N;
	list<char> char_list(s.begin(), s.end());
	auto cursur = char_list.end();

	for (int i = 0;i < N;i++) {
		cin >> oper;
		switch (oper) {
		case 'L' :
			if (cursur != char_list.begin()) {
				cursur--;
			}
			break;
		case 'D' :
			if (cursur != char_list.end()) {
				cursur++;
			}
			break;
		case 'B' :
			if (cursur != char_list.begin()) {
				cursur = char_list.erase(--cursur);
			}
			break;
		case 'P':
			cin >> ch;
			char_list.insert(cursur,ch);
			break;
		}
	}

	for (auto c : char_list) cout << c;

	return 0;
}
