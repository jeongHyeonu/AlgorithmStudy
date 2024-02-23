#include <iostream>
#include <queue>
using namespace std;

int n, w, L, T;
int weight, totalWeight;
queue<int> trucks;
deque<pair<int,int>> bridge;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> L;

    for (int i = 0;i < n;i++) {
        cin >> weight;
        trucks.push(weight);
    }

    // 첫 번째 트럭 출발
    T = 0;

    while (!trucks.empty() || !bridge.empty()) {
        T++;
        totalWeight = 0;

        // 다리 위 트럭 전진
        for (int i = 0; i < bridge.size(); i++) bridge[i].second++;

        // 다리 다 건넌 트럭은 큐에서 제거
        if (!bridge.empty() && bridge.front().second == w) bridge.pop_front();

        // 다리위 전체트럭 무게 증가
        for(auto t : bridge) totalWeight += t.first; 

        // 다리 위에 트럭이 올라갈 자리가 있고, 다리의 최대하중이 남은 경우  
        if (!trucks.empty() && trucks.front() + totalWeight <= L && bridge.size() < w) {              
            bridge.push_back({ trucks.front(), 0 });
            trucks.pop();        
        }
    }
    cout << T;
    return 0;
}