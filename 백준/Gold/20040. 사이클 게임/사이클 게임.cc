#include <iostream>
#include <cstring>
using namespace std;

int T, N, M;
int arr[500001];

int find(int x) {
	if (arr[x] == x) return x;
	return find(arr[x]);
}

void unionNode(int a, int b) {
	int par_a = find(a);
	int par_b = find(b);
	arr[par_b] = par_a;
	//arr[par_a] = par_b;
}

bool isCycle(int a, int b) {
	if (find(a) == find(b)) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0;i < N;i++) arr[i] = i; // 각 노드 부모노드는 자기자신으로 초기화 

	int n1, n2;
	for (int i = 0;i < M;i++) {
		cin >> n1 >> n2;
		if (isCycle(n1, n2)) {
			cout << i + 1;
			exit(0);
		}
		unionNode(n1, n2);
	}

	cout << 0;
	return 0;
}

