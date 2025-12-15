#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(auto a : scoville) pq.push(a);
    
    if(pq.top() >= K) return 0;
    
    while(pq.size() > 1){
        long p1 = pq.top(); pq.pop();
        long p2 = pq.top(); pq.pop();
        pq.push(p1+(2*p2));
        answer++;
        
        if(pq.top() >= K) break;
    }
    
    if(pq.top() >= K) return answer;
    return -1;
}