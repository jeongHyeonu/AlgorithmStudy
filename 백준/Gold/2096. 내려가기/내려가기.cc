#include <iostream>
#include <queue>
#define Fmax(a,b)(((a)>(b))?(a):(b))
#define Fmin(a,b)(((a)<(b))?(a):(b))

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int score_min[] = { 0,0,0 };
    int score_max[] = { 0,0,0 };
    int temp[3];

    cin >> N;

    for (int i = 0;i < 3;i++) {
        cin >> temp[i];
        score_max[i] = temp[i];
        score_min[i] = temp[i];
    }

    for (int i = 1;i < N;i++) {
        cin >> temp[0] >> temp[1] >> temp[2];

        int max_0 = score_max[0], max_2 = score_max[2];
        score_max[0] = Fmax(score_max[0],score_max[1]) + temp[0];
        score_max[2] = Fmax(score_max[1],score_max[2]) + temp[2];
        score_max[1] = Fmax(max_0, Fmax(score_max[1], max_2)) + temp[1];

        int min_0 = score_min[0], min_2 = score_min[2];
        score_min[0] = Fmin(score_min[0], score_min[1]) + temp[0];
        score_min[2] = Fmin(score_min[1], score_min[2]) + temp[2];
        score_min[1] = Fmin(min_0, Fmin(score_min[1], min_2)) + temp[1];
    }

    cout << Fmax(score_max[0], Fmax(score_max[1], score_max[2])) << ' ';
    cout << Fmin(score_min[0], Fmin(score_min[1], score_min[2]));

    return 0;
}