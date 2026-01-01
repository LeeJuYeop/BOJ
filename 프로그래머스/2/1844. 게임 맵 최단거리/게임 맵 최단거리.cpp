#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps){
    // init
    int dy[4] = {1,0,0,-1};
    int dx[4] = {0,1,-1,0};
    queue<vector<int>> q;
    int n = maps.size(); int m = maps[0].size();
    vector<vector<int>> visit(n, vector<int>(m, 0));
    q.push({0,0,1});
    visit[0][0] = 1;
    
    // logic
    while(!q.empty()){
        int py = q.front()[0]; int px = q.front()[1]; int dist = q.front()[2];
        q.pop();
        
        if(py == n-1 && px == m-1) return dist;
        
        for(int i = 0 ; i < 4 ; i++){
            int ny = py + dy[i];
            int nx = px + dx[i];
            
            if(ny >= 0 && ny < n && nx >=0 && nx < m && maps[ny][nx] == 1 && visit[ny][nx] != 1){
                q.push({ny,nx,dist+1});
                visit[ny][nx] = 1;
            }
        }
        
    }
    return -1;
}