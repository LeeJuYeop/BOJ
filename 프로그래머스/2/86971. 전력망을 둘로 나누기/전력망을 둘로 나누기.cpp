// 단순히 하나제외하는경우의수를 다 검사하면 O(n^2)..?
// 1. 그래프를 구성한다.
// 2. 하나의 WIRE만 제외하고 연결요소 2개의 크기를 검사를 진행한다.
// 이 때, 연결요소 2개의 크기는 N-k, k개로 정해져있으므로 하나의 연결요소의 크기만 구하면 된다.

#include <string>
#include <vector>
#include <queue>

using namespace std;

int getSizeDiff(vector<vector<int>>& G, int n, int ux, int vx){
    // init
    queue<int> q;
    vector<int> visit(n+1, 0);
    q.push(1);
    visit[1] = 1;
    int k = 1;
    
    // logic
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : G[u]){
            if(u == ux && v == vx) continue;
            if(u == vx && v == ux) continue;
            
            if(visit[v] != 1){
                q.push(v);
                visit[v] = 1;
                k++;
            }
        }
    }
    
    // return k;
    return ((n-k) >= k) ? n - k - k : k - (n-k);
}

int solution(int n, vector<vector<int>> wires) {
    // init
    int answer = 200;
    vector<vector<int>> Graph(n+1, vector<int>(0, 0));
    // 그래프 구성
    for(auto wire : wires){
        Graph[wire[0]].push_back(wire[1]);
        Graph[wire[1]].push_back(wire[0]);
    }
    
    // logic
    for(auto wire : wires){
        answer = min(answer, getSizeDiff(Graph, n, wire[0], wire[1]));
    }
    
    return answer;
}