#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(vector<int> people, int limit) {
    int answer = 0, idx=0, peopleCnt=0, target;
    sort(people.begin(), people.end());

    do {

        target = people.back();
        people.pop_back();
        if (target + people[idx] <= limit) {
            answer++;
            idx++;
        }
        else {
            answer++;
        }
                peopleCnt = people.size();
    } while (peopleCnt > idx);

    return answer;
}