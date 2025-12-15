// 1. jobs를 시작시작순으로 sort()한다.
// 2. 조건에 맞게 만들어진 pq에 time 안쪽인 job들을 넣는다.
//          만약 jobs가 남는데 pq가 빈다면? time jobs의 cur만큼 증가시킨다.
// 3. 우선순위가 높은 작업을 수행한다.
// 4. 2-3을 while문으로, cur이 jobs보다 커질 때 까지 한다.

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 0 : 작업번호
// 1 : 요청시각
// 2 : 소요시간
struct cmp1{
    bool operator() (vector<int>& a, vector<int>& b){
        if(a[2] != b[2]) return a[2] > b[2];
        if(a[1] != b[1]) return a[1] > b[1];
        return a[0] > b[0];
    }
};

bool cmp2(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    // init
    int answer = 0;
    int cur = 0;
    int time = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp1> pq;
    sort(jobs.begin(), jobs.end(), cmp2);
    
    // logic
    while(cur < jobs.size() || !pq.empty()){
        // insert job to pq
        while(cur < jobs.size() && time >= jobs[cur][0]){
            pq.push({cur, jobs[cur][0], jobs[cur][1]});
            cur++;
        }
        
        if(pq.empty() && cur < jobs.size()){
            time = jobs[cur][0];
            continue;
        }
        
        // processing job
        if(!pq.empty()){
            vector<int> job = pq.top(); pq.pop();
            time += job[2];
            answer += (time - job[1]);
        }
    }
    
    return answer / jobs.size(); 
}