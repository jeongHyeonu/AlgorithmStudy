#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, temp;
int arr[9];
bool visited[9];
vector<int> selected;

void dfs(int idx, int cnt) {
    if (cnt == M) {
        for (int i = 0;i < M;i++)
            cout << selected[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0;i < N;i++) {
        if (!visited[i]) {
            visited[i] = true;
            selected.push_back(arr[i]);
            dfs(i, cnt + 1);
            selected.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0;i < N;i++) cin >> arr[i];
    sort(arr, arr+N);
    dfs(0, 0);

    return 0;
}