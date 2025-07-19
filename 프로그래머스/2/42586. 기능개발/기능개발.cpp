#include <string>
#include <vector>
// 일단 맨앞대가리 애가 작업끝나기까지 며칠걸리는지 기록한다.
// 맨앞에 뺴내고 다음애로 포인터 이동.
// 그 애한테도 동일일수 지나야하니 speed * cnt 로 더함.
// 만약 100넘으면 그녀석도 뺴내기.... 100안넘는 애가 발생할 때까지 반복.
// 

using namespace std;
#include <cmath>
#include <queue>

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 0;
    int cnt = 0;
    queue<int> q;
    for(int i = 0 ; i < progresses.size() ; i++){
        q.push( ceil((double)(100-progresses[i]) / speeds[i]) );
    }
    
    while(!q.empty()){
        day = q.front();
        while(!q.empty() && day >= q.front()){
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
        cnt = 0;
        
    }
    
    return answer;
}