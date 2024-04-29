#include <string>
#include <vector>
#include <algorithm>
#define MIN(a,b)(((a)<(b))?(a):(b))
using namespace std;
int e;

int solution(vector<vector<int>> targets) {
    int answer = 0, idx=0;

    sort(targets.begin(), targets.end());

    while (idx < targets.size()) {
        e = targets[idx][1];
        idx++;
        answer++;
        while (idx<targets.size() && e > targets[idx][0]) {
            e = MIN(targets[idx][1], e);
            idx++;
        }
    };
    return answer;
}
