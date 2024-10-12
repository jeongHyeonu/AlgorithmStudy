#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

unordered_map<string, bool> files;
unordered_map<string, vector<pair<bool,string>>> graph;

int types = 0;
int total = 0;

void dfs(string node) {
    for (auto it : graph[node]) {
        if (it.first) { // 폴더인 경우
            dfs(it.second);
        }
        else { // 파일인 경우
            if (!files[it.second]) { // 아직 찾지 않은 파일인 경우
                files[it.second] = true;
                types++;
            }
            total++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, Q;
    cin >> N >> M;

    string s1, s2;
    bool isFolder;
    int folderIdx = 0;
    for (int i = 0;i < N + M;i++) {
        cin >> s1 >> s2 >> isFolder;
        vector<pair<bool, string>> v = graph[s1];
        v.push_back({ isFolder,s2 });
        graph[s1] = v;
    }

    cin >> Q;
    string query;
    for (int i = 0;i < Q;i++) {
        cin >> query;
        vector<string> parse;
        istringstream ss(query);
        string str_buf;
        while (getline(ss, str_buf, '/')) {
            parse.push_back(str_buf);
        }
        dfs(parse.back());
        cout << types << ' ' << total << '\n';
        files.clear();
        types = total = 0;
    }

    return 0;
}