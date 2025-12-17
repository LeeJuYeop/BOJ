// 플로이드-와샬 알고리즘(최단거리를 구하는 O(n^3) 알고리즘) 이용

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> G;

int solution(int n, vector<vector<int>> results) {
    // inint
    int answer = 0;
    int notFound = 2;
    G.assign(n+1, vector<int>(n+1, notFound));
    for(int i = 1 ; i <= n ; i++) G[i][i] = 0;
    for(auto e : results){
        G[e[0]][e[1]] = 1;
        G[e[1]][e[0]] = -1;
    }
    
    // logic
    for(int k = 1 ; k <= n ; k++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(G[i][k] == 1 && G[k][j] == 1){
                    G[i][j] = 1; G[j][i] = -1;
                }
            }
        }
    }
    
    int cnt=0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(G[i][j] == notFound) break;
            cnt++;
        }
        if(cnt == n) answer++;
        cnt = 0;
    }
    
    return answer;
}