#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[201][201][201];
int A, B, C,a,b,c;
vector<int> v;
queue<pair<pair<int, int>, int>> q;

void bfs() {
	while (!q.empty()) {
		a = q.front().first.first;
		b = q.front().first.second;
		c = q.front().second;
		q.pop();

		if (visited[a][b][c] == true) continue;
		if (a == 0) v.push_back(c);
		visited[a][b][c] = true;

		//cout << a << ' ' << b << ' ' << c << '\n';

		// C->A, C->B
		if (a + c > A) q.push({ {A, b}, a + c - A });
		else q.push({ {a + c, b}, 0 });
		if (b + c > B) q.push({ {a, B}, b + c - B });
		else q.push({ {a, b + c}, 0 });

		// B->A, B->C
		if (a + b > A) q.push({ {A, a + b - A}, c });
		else q.push({ {a + b, 0}, c });
		if (b + c > C) q.push({ {a, b + c - C}, C });
		else q.push({ {a, 0}, b + c });

		// A->B, A->C
		if (a + b > B) q.push({ {a + b - B, B}, c });
		else q.push({ {0, a + b}, c });
		if (a + c > C) q.push({ {a + c - C,b},C });
		else q.push({ {0, b}, a + c });
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B >> C;

	q.push({ { 0,0 }, C });
	bfs();
	
	sort(v.begin(), v.end());
	for (int i = 0;i < v.size();i++) cout << v[i] << ' ';

}
