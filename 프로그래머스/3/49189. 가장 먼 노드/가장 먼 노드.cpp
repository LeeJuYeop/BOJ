#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> visit;
vector<int> dist;

int solution(int n, vector<vector<int>> edge) {
    // init
    vector<vector<int>> G;
    G.assign(n+1, vector<int>(0, 0));
    dist.assign(n+1, 0);
    visit.assign(n+1, 0);
    int answer = 0;
    queue<int> q;
    q.push(1);
    visit[1] = 1;
    
    for(auto e : edge){
        int a = e[0]; int b = e[1];
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    // logic
    // 1. 모든 노드의 최단 경로 dist 구하기
    while(!q.empty()){
        int u = q.front(); q.pop();
        
        for(int v : G[u]){
            if(!visit[v]){
                q.push(v);
                visit[v] = 1;
                dist[v] = dist[u] + 1;
            }
        }
    }
    
    // 2. 최단경로 중 가장 멀리 떨어진 노드의 길이 구하기
    int max_dist{-1};
    for(int i = 1 ; i <= n ; i++){
        if(dist[i] > max_dist) max_dist = dist[i];
    }
    
    // 3. 갯수 세기
    for(int i = 1 ; i <= n ; i++){
        if(dist[i] == max_dist) answer++;
    }
    
    return answer;
}