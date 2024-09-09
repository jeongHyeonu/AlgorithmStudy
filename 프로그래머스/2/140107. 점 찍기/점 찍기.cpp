#include <string>
#include <cmath>

using namespace std;


long long distPow;

long long solution(int k, int d) {
    long long answer = 0;

    distPow = (long long)d * d;
    for (int x = 0;x <= d; x += k) {
        int y = floor(sqrt(distPow - (long long)x * x));
        answer += y / k + 1;
    }

    return answer;
}
