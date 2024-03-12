#include <iostream>
#include <vector>
#include <algorithm>
#define MAX(a,b)(((a)>(b))?(a):(b))
#define MIN(a,b)(((a)<(b))?(a):(b))

using namespace std;
vector<int> budgets;
int n, maxBudget=0, m, num;

void binarySearch(int start, int end) {
	int mid, sum=0, result=0;
		
	while (start <= end) {
		mid = (start + end) / 2;
		sum = 0;
		for (int i = 0;i < n;i++) sum += MIN(budgets[i], mid);
		if (m >= sum) {
			result = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> num;
		budgets.push_back(num);
		maxBudget = MAX(num, maxBudget);
	}
	cin >> m;

	sort(budgets.begin(), budgets.end());
	binarySearch(0, maxBudget);
	return 0;
}