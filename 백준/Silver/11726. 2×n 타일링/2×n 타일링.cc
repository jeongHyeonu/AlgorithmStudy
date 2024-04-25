#include <iostream>
using namespace std;

int N, results[1002];

int main() {
	cin >> N;

	results[0] = 1;
	results[1] = 2;

	for (int i = 2;i <= N;i++) {
		results[i] = (results[i - 2] + results[i - 1]) % 10007;
	}

	cout << results[N-1];
}
