#include <iostream>
#include <vector>
using namespace std;

int switchCnt,stuCnt,num1,num2;
bool switch_onoff[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> switchCnt;
    for (int i = 1;i <= switchCnt;i++) {
        cin >> switch_onoff[i];
    }
    
    cin >> stuCnt;
    for (int i = 0;i < stuCnt;i++) {
        cin >> num1 >> num2;
        if (num1 == 1) {
            switch_onoff[num2] = !switch_onoff[num2];
            int idx = num2;
            while (true) {
                idx += num2;
                if (idx <= switchCnt) switch_onoff[idx] = !switch_onoff[idx];
                else break;
            }
        }
        if (num1 == 2) {
            switch_onoff[num2] = !switch_onoff[num2];
            int left=num2, right=num2;
            while (true) {
                left--;
                right++;
                if (left >= 1 && right <= switchCnt) {
                    if (switch_onoff[left] == switch_onoff[right]) {
                        switch_onoff[left] = !switch_onoff[left];
                        switch_onoff[right] = !switch_onoff[right];
                    }
                    else break;
                }
                else break;
            }
        }
    }

    for (int i = 1;i <= switchCnt;i++) {
        cout << (switch_onoff[i] ? 1 : 0) << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }

    return 0;
}