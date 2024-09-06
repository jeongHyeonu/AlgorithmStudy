#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char arr[16];
bool visited[16];

void dfs(int idx, int cnt) {
    if (cnt == L) {
        string s = "";
        int moum = 0;
        int jaum = 0;
        for (int i = 0;i < C;i++) if (visited[i]) {
            s.push_back(arr[i]);
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') moum++;
            else jaum++;
        }
        if(moum>=1 && jaum>=2) cout << s << '\n';
        return;
    }
    for (int i = idx;i < C;i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> L >> C;

    for (int i = 0;i < C;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + C);

    dfs(0, 0);
}