#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;	cin >> n;
	string base,comp; cin >> base;

	int alpha[26] = { 0, }; 
	int base_len = base.size();
	for (int i = 0; i < base_len; i++) { 
		alpha[base[i] - 'A'] += 1;
	}
	
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> comp;
		int comp_len = comp.size();
		int ccopy[26];
		copy(alpha, alpha + 26, ccopy); 

		int same = 0;
		for (int i = 0; i < comp_len; i++) {
			if (ccopy[comp[i] - 'A'] > 0) {
				ccopy[comp[i] - 'A']--;
				same++;
			}
		}

		if (base_len == comp_len) {
			if (same == base_len || same == base_len - 1) {
				count++;
			}
		}
		else if (base_len - 1 == comp_len && same == base_len - 1) count++;
		else if (base_len + 1 == comp_len && same == base_len) count++;
		else continue; 
	}

	cout << count << '\n';	
}