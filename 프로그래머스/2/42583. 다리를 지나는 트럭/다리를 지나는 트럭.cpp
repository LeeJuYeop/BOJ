#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // init
    int time = 0;
    int tmp = 0;            // 다리위를 건너는 중인 트럭의 총 무게
    queue<pair<int,int>> bridge;    // 다리를 건너는 트럭 <무게, 들어온시간>
    queue<int> wait;           // 대기트럭
    for(int truck : truck_weights){
        wait.push(truck);
    }
    
    // logic
    while(!bridge.empty() || !wait.empty()){
        time++;
        if(time-bridge.front().second == bridge_length){
            tmp -= bridge.front().first;
            bridge.pop();
        }
        
        if(!wait.empty()){
            if(wait.front() + tmp <= weight){
                tmp += wait.front();
                bridge.push({wait.front(), time}); wait.pop();
            }
        }
    }
    
    return time;
}