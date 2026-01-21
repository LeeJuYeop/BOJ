// 1. 진출시점기준으로 정렬한다.
// 2. 맨앞에는 진출이 가장 빠른 차 a가 위치. 해당 차의 진출시점에 하나를 놓는다.
// ( (2)의 타이밍보다 늦으면 a가 포함되지 못하고, 빠른 것은 낭비임. )
// 3. (2)에서 놓은 카메라로 걸러지는 애들 빼고 다시 반복

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    // init
    sort(routes.begin(), routes.end(), cmp);
    int lastCam = -300000;      // 마지막에 설치한 카메라
    int answer = 0;
    
    // logic
    for(int i = 0 ; i < routes.size() ; i++){
        if(routes[i][0] <= lastCam && lastCam <= routes[i][1])continue;
        
        lastCam = routes[i][1];
        answer += 1;
    }
    
    return answer;
}