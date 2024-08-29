#include <iostream>
#include <vector>
using namespace std;


int T,N;

int main() {
	cin >> T;

	while (T--) {
		cin >> N;

		bool visited[10001] = { false, };
		int parents[10001] = { 0, };

		int A, B;
		for (int i = 0;i < N - 1;i++) {
			cin >> A >> B;
			parents[B] = A;
		}
		cin >> A >> B;

		int node = A;
		visited[node] = true;

		while (1) {
			visited[parents[node]] = true;
			node = parents[node];
			if (node == 0) break;
		}

		node = B;
		while (1) {
			if (visited[node] == true) break;
			node = parents[node];
		}

		cout << node << '\n';
	}

}