// 오일러 경로. 백트래킹.

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> answer;
unordered_map<string, vector<pair<string,bool>>> graph;
int goal;

bool DFS(string tmp, int cnt){
    answer.push_back(tmp);   // 일단 answer에 추가.
    
    if(cnt == goal){        // 모든 티켓을 다 사용했으면 성공
        return true;
    }
    // 백트래킹
    for(int i = 0 ; i < graph[tmp].size() ; i++){
        if(graph[tmp][i].second) continue;        // 이미 사용한 티켓이면 넘어가기
        string nxt = graph[tmp][i].first;
        
        // visit
        graph[tmp][i].second = true;
        
        // DFS재귀
        if(DFS(nxt, cnt+1)){
            return true;
        }
        
        // visit undo
        graph[tmp][i].second = false;
    }
    
    
    
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    // init
    goal = tickets.size();
    
    // 그래프 구성 및 알파벳순 정렬
    for(auto& ticket : tickets){
        graph[ticket[0]].push_back({ticket[1], false});
    }
    for(auto& entry : graph){
        sort(entry.second.begin(), entry.second.end());
    }
    
    // logic
    DFS("ICN", 0);
    return answer;
}