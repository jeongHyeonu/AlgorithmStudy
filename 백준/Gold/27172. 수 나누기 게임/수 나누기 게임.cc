#include <iostream>
#define MAX(a,b)(((a)>(b))?(a):(b))
using namespace std;

int N, max_card=0;
int players[1000004];
int cnt[1000004];
bool card[1000004];

void calculate(int num) {
	for (int i = num*2;i <= max_card;i += num) {
		if (card[i]) {
			cnt[num]++;
			cnt[i]--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> players[i];
		card[players[i]] = true;
		max_card = MAX(max_card, players[i]);
	}
	
	for (int i = 0;i < N;i++) calculate(players[i]);

	for (int i = 0;i < N;i++) cout << cnt[players[i]] << ' ';
}