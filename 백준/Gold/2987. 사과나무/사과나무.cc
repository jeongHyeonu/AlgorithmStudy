#include <iostream>
using namespace std;

int N;

int point_x[3];
int point_y[3];

long double get_ccw(int x1, int x2, int x3, int y1, int y2, int y3) {
	return (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0;i < 3;i++)
		cin >> point_x[i] >> point_y[i];

	long double size = get_ccw(point_x[0], point_x[1], point_x[2], point_y[0], point_y[1], point_y[2]) / 2.0;
	
	cin >> N;
	cout << fixed;
	cout.precision(1);
	int ans = 0;
	int x, y;
	for (int i = 0;i < N;i++) {
		cin >> x >> y;
		long double ccw;
		if (size > 0) {
			ccw = get_ccw(x, point_x[1], point_x[2], y, point_y[1], point_y[2]);
			if (ccw < 0) continue;
			ccw = get_ccw(point_x[0], x, point_x[2], point_y[0], y, point_y[2]);
			if (ccw < 0) continue;
			ccw = get_ccw(point_x[0], point_x[1], x, point_y[0], point_y[1], y);
			if (ccw < 0) continue;
		}
		if (size < 0) {
			ccw = get_ccw(x, point_x[1], point_x[2], y, point_y[1], point_y[2]);
			if (ccw > 0) continue;
			ccw = get_ccw(point_x[0], x, point_x[2], point_y[0], y, point_y[2]);
			if (ccw > 0) continue;
			ccw = get_ccw(point_x[0], point_x[1], x, point_y[0], point_y[1], y);
			if (ccw > 0) continue;
		}
		ans++;
	}


	cout << abs(size) << '\n' << ans;

}