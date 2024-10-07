#include <iostream>
#include <vector>
#define MIN(a,b)(((a)<(b))?(a):(b))

using namespace std;
int N, M;
int arr[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0;i < N;i++) cin >> arr[i];
    cin >> M;

    int minPrice1 = 999, minPrice2 = 999;
    int idx1, idx2;
    for (int i = 1;i < N;i++) { // 첫째자리에 위치할 0이 아닌 숫자
        if (arr[i]<minPrice1) {
            minPrice1 = arr[i];
            idx1 = i;
        }
    }
    for (int i = 0;i < N;i++) { // 둘째자리부터 시작할 숫자 (0 포함)
        if (arr[i] < minPrice2) {
            minPrice2 = arr[i];
            idx2 = i;
        }
    }

    // 만약 첫째자리에 (0 제외) 값이 위치할 수 없는 경우
    if (M < minPrice1) {
        cout << '0';
        exit(0);
    }

    string str = "";

    // 만들 수 있는 방 번호의 최대 자리수 결정
    M -= minPrice1; // 첫째자리 들어갈 숫자
    str.push_back('0'+idx1);
    while (M >= minPrice2) { // 그 다음부터 들어갈 숫자
        M -= minPrice2; 
        str.push_back('0'+idx2);
    }

    // 최대 자리수 내의 숫자 변경해서 가장 큰 수를 만든다
    for (int i = 0;i < str.size();i++) {
        for (int j = N-1;j > str[i]-'0';j--) { // N-1 부터 str[i]까지, 해당 자리수 숫자 변경
            if (M+arr[str[i]-'0'] >= arr[j]) { // 해당 자리수가 다른 숫자로 변경 가능한 경우
                // 남은가격 갱신 및 자리수 숫자 변경
                M += arr[str[i] - '0'];
                M -= arr[j];
                str[i] = '0' + j;
                break;
            }
        }
    }

    cout << str;
    return 0;
}