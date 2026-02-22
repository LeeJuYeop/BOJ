// 도형을 비트화한다.
// 1. 가장왼쪽위 좌표를 00으로 하여 나머지 칸도 10, 01 등으로 매기고 정렬해준다.
// 2. 회전 : 회전함수를 만들어 도형을 회전한다. (1)처럼 맞추기 위해 정규화를 해준다.
// 3. 게임보드와 퍼즐을 맞춘다. 같은 크기의 도형들을 비교하면서 찾는다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dy[4] = {1,0,0,-1};
int dx[4] = {0,1,-1,0};

// 도형추출 함수
void DFS(int y, int x, int v, vector<vector<int>>& table, vector<pair<int,int>>& tar){
    // v(게임보드 or 퍼즐 여부)에 따른 visit처리
    table[y][x] = v==1?0:1;
    tar.push_back({y,x}); 
    // 재귀 DFS
    for(int i = 0 ; i < 4 ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny>=0 && ny < table.size() && nx>=0 && nx<table[0].size() && table[ny][nx] == v){
            DFS(ny, nx, v, table, tar);
        }
    }
}

// (0,0) 을 기준으로 시계방향으로 "한번" 회전하는 함수
// 1. y와 x가 바뀐다.
// 2. x의 부호가 바뀐다.
// ex) (1,3) => (3,-1)
// (1,-1) => (-1,-1);
vector<pair<int,int>> spin(vector<pair<int,int>> puz){
    for(int i = 0 ; i < puz.size() ; i++){
        int tmp = puz[i].first;
        puz[i].first = puz[i].second;
        puz[i].second = -tmp;
    }
    
    return puz;
}

// 도형좌표 정렬 및 정규화 함수
vector<pair<int,int>> norm(vector<pair<int,int>> puz){
    // sort
    sort(puz.begin(), puz.end());
    // 맨앞좌표를 0,0으로 잡고 정규화
    int sumy = -puz[0].first;
    int sumx = -puz[0].second;
    for(int i = 0 ; i < puz.size() ; i++){
        puz[i].first += sumy;
        puz[i].second += sumx;
    }
    
    return puz;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    // init
    int answer = 0;
    vector<vector<pair<int,int>>> board;    // 게임보드 칸
    vector<vector<pair<int,int>>> puzzle;   // 퍼즐
    
    // logic
    // table, game_board에서 도형 추출
    for(int i = 0 ; i < game_board.size() ; i++){
        for(int j = 0 ; j < game_board[0].size() ; j++){
            if(game_board[i][j] == 0){
                board.push_back({});    // 빈 vector<pair> 추가.
                DFS(i,j,0,game_board,board.back());
            }
            if(table[i][j] == 1){
                puzzle.push_back({});   // 빈 vector<pair> 추가.
                DFS(i,j,1,table,puzzle.back());
            }
        }
    }
    
    // 도형 비교
    vector<bool> completed(puzzle.size(), false);   // 이미 쓰인 퍼즐 판별을 위함.
    
    for(int i = 0 ; i < board.size() ; i++){
        for(int j = 0 ; j < puzzle.size() ; j++){
            if(completed[j]) continue;      // 이미 쓰인 퍼즐은 스킵
            
            // 퍼즐을 4방향 돌려가며 비교
            vector<pair<int,int>> norm_board = norm(board[i]);
            vector<pair<int,int>> puz = puzzle[j];
            
            for(int r = 0 ; r < 4 ; r++){
                puz = norm(spin(puz));
                if(norm_board == puz){
                    completed[j] = true;
                    answer+=norm_board.size();
                    break;
                }
            }
            
            if(completed[j]) break; // fair찾았을 시 puzzle 더 안찾고 다음 빈칸으로.
        }
    }
    
    return answer;
}