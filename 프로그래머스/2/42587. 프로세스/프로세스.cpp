// 1. 로직대로 pop/push 반복하면서 알아내기.
// 2. 로직을 역산하여 계산하기
// 두 가지 방법이 있겠지만 큐 길이가 100 이하라 1번으로 해도 큰 시간초과는 없겠다.
// 다만 location, 즉 내가 계산한 프로세스를 잘 추적하는게 문제다.

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    // init
    int answer = 0;
    queue<int> q;
    unordered_map<int, int> um; // 우선순위넘버:프로세스개수
    vector<int> kind;   // 남아있는 우선순위의 종류들
    
    // 큐에 프로세스 넣으면서, 우선순위 개수 세기
    for(int p : priorities){
        q.push(p);
        if(um.find(p) == um.end()) kind.push_back(p);
        um[p]++;
    }
    
    // 우선순위 종류들 정렬
    sort(kind.begin(), kind.end(), greater<int>());
    int cur = 0;
    
    // logic
    while(!q.empty()){ 
        int p = q.front(); q.pop();
        if(p == kind[cur]){      // 프로세스를 실행하는 경우
            um[p]--;
            
            if(location == 0) return priorities.size() - q.size();  // 내가 추적하던 프로세스가 종료된 경우
            
            if(um[p] == 0){     // 한 우선순위가 모두 종료된 경우
                cur++;
            }
        }
        else{
            q.push(p);
        }
        
        // 프로세스추적
        location--; // 한번의 진행으로 추적하는 프로세스의 위치는 앞당겨짐
        if(location < 0) location = q.size() - 1;
    }
    return answer;
}