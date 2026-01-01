// 연결요소 문제.
// for문으로 돌면서 visit이 아닌애에서 탐색시작. 탐색에서 들린 애들은 visit으로 표기 => 네트워크 하나 파악

#include <string>
#include <vector>
using namespace std;

vector<vector<int>> Graph;
vector<int> visit;

void DFS(int u){
    visit[u] = 1;
    for(int v : Graph[u]){
        if(visit[v] == 0){
            DFS(v);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    // init
    int answer = 0;
    Graph.assign(n, vector<int>(0,0));
    visit.assign(n, 0);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j) continue;
            
            if(computers[i][j] == 1){
                Graph[i].push_back(j);
            }
        }
    }
    
    // logic : DFS_driver()
    for(int i = 0 ; i < n ; i++){
        if(visit[i] == 0){
            DFS(i);
            answer++;
        }
    }
    
    return answer;
}