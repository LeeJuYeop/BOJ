// (1) 보통의 2차원맵 탐색문제는 장애물(#)만 못지나가게 만들었다면(아무것도 없는 허공은 자유롭게 움직임)
// (2) 이 문제는 특정 장애물의 외곽만 가능하게한다.(아무것도 없는 허공도 못움직임)
// 주어진 입력을 이용해서 (1)번의 느낌으로 바꿔보면
// 0 = 아무것도 없는 허공 = 움직임불가
// 1 = 장애물(직사각형)테두리 = 움직임가능. // 단 이미 2번이 있는 자리는 1번으로 쓰여질 수 없음
// 2 = 장애물(직사각형)이 놓인 자리 = 움직임불가. 

// 해법 : 2배
// 위 풀이의 문제점은 직사각형 테두리를 따라 1번으로 만드는것 까지는 좋으나
// 1번이 겹치면 직사각형 테두리를 안따라가도 길이 된다는 것이다.
// 테케1번에서 (3,5) -> (3,6) 처럼.

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // init
    vector<vector<int>> board(103, vector<int>(103, 0));
    queue<vector<int>> q;
    vector<vector<int>> visit(103, vector<int>(103, 0));
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int answer = 0;
    // 2베
    characterX *= 2; characterY *= 2; itemX *= 2; itemY *= 2;
    
    
    // logic
    // 1. 맵구성
    for(auto rect : rectangle){
        // 2배
        for(int i = 0 ; i < 4 ; i++) rect[i] *= 2;
        
        for(int x = rect[0] ; x <= rect[2] ; x++){
            for(int y = rect[1] ; y <= rect[3] ; y++){
                if(x == rect[0] || x == rect[2] || y == rect[1] || y == rect[3]){
                    if(board[x][y] != 2){   // 이미 장애물이 있는 자리는 길로 활용 불가능
                        board[x][y] = 1;
                    }
                }
                else{
                    board[x][y] = 2;
                }
            }
        }
    }
    
    // 2. BFS탐색
    q.push({characterX, characterY, 0});
    visit[characterX][characterY] = 1;
    while(!q.empty()){
        vector<int> tmp = q.front(); q.pop();
        int px = tmp[0]; int py = tmp[1]; int dist = tmp[2];
        
        if(px == itemX && py == itemY) return dist / 2;
        
        for(int i = 0 ; i < 4 ; i++){
            int nx = px + dx[i];
            int ny = py + dy[i];
            
            if(nx >= 0 && nx <= 102 && ny >= 0 && ny <= 102 && visit[nx][ny] != 1){
                if(board[nx][ny] == 1){
                    q.push({nx,ny,dist+1});
                    visit[nx][ny] = 1;
                }
            }
        }
    }
    
    return answer;
}