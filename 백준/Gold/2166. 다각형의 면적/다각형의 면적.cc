#include <iostream>
using namespace std;

int N;
long double x[100001];
long double y[100001];

long double calculate(int pos2, int pos3) {
	long double x1 = x[0], x2 = x[pos2], x3 = x[pos3];
	long double y1 = y[0], y2 = y[pos2], y3 = y[pos3];

	return (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++)
		cin >> x[i] >> y[i];

	long double ans = 0;
	for(int i=0;i<N-1;i++)
		ans += calculate(i,i+1);

	cout << fixed;
	cout.precision(1);
	cout << abs(ans);
}