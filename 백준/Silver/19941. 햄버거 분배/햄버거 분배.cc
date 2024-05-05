#include <iostream>
#include <vector>
using namespace std;

int N, K;
char arr1[20001];
bool ate[20001];
vector<int> v;
int cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		cin >> arr1[i];
		if (arr1[i] == 'P') v.push_back(i);
	}

	for (int i = 0;i < v.size();i++) {
		for (int j = v[i] - K;j <= v[i] + K;j++) {
			if (j >= 0 && j < N && !ate[j] && arr1[j] == 'H') {
				ate[j] = true;
				cnt++;
				break;
			}
		}
	}

	cout << cnt;
}
