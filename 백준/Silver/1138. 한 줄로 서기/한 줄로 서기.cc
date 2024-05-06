#include <iostream>
using namespace std;

int N;
int num, temp;

int arr[11];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> N;

    for (int i = 1;i <= N;i++) {
        cin >> temp;
        num = 0;
        for (int j = 1; j <= N; j++) {
            if (num == temp && arr[j] == 0) {
                arr[j] = i;
                break;
            }
            else if (arr[j] == 0) num++;
        }
    }

	for (int i = 1;i <= N;i++) cout << arr[i] << ' ';
}
