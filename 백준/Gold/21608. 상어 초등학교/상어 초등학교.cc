// 단순무식하게 N^2 학생들을 N^2개 자리에 하나하나 적합도를 따지면 N^4 = 160,000... 가능하지 않나?
// 연산을 줄이려면?
// (1) - 배치 후에 배치 위치를 map으로 빠르게 찾을 수 있게 사전등록 => 후보지 찾기가 많이 빨라짐.
// 나머지 2번과 3번은 빈칸개수정렬, 행열번호정렬만 따로 해주면 되니까 큰 일이 아님.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef pair<int,int> pos;
int N;
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

// (1)에 의한 후보지 (r,c)에 점수 계산
int chk(int r, int c, vector<vector<int>>& board, vector<int>& friends){
    int score = 0;

    // 4방향 확인
    for(int i = 0 ; i < 4 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr > 0 && nr <= N && nc > 0 && nc <= N){
            if(board[nr][nc] == friends[1] || board[nr][nc] == friends[2] || board[nr][nc] == friends[3] || board[nr][nc] == friends[4]) score++;
        }
    }

    return score;
}

int chk_blank(int r, int c, vector<vector<int>>& board){
    int score = 0;

    // 4방향 확인
    for(int i = 0 ; i < 4 ; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr > 0 && nr <= N && nc > 0 && nc <= N){
            if(board[nr][nc] == 0) score++;
        }
    }

    return score;
}

int main(){
    // init
    cin >> N;
    vector<vector<int>> board(N+1, vector<int>(N+1,0));
    vector<vector<int>> students(N*N, vector<int>(5,0));   // students[i][0] = 학생번호, students[i][1] ~ students[i][4] = 좋아하는 학생 번호
    unordered_map<int, pos> um;

    for(int i = 0 ; i < N*N ; i++){
        cin >> students[i][0];
        cin >> students[i][1];
        cin >> students[i][2];
        cin >> students[i][3];
        cin >> students[i][4];
    }

    // logic
    // 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
    // 2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
    // 3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
    board[2][2] = students[0][0];   // 첫번째 학생은 무조건 (2,2) 고정임(N >= 3)
    um[students[0][0]] = {2,2};
    for(int i = 1 ; i < N*N ; i++){ // 두번째 학생부터 시작
        int sid = students[i][0];   // 이번 학생의 id

        // (1)에 의한 후보지(최대 16곳) 검색
        // 기존 기록보다 더 높은 장소가 나오면 list를 비우는 방식으로 가장 최선인 자리만 뽑기
        int maximum = 0;
        vector<pos> list;
        for(int j = 1 ; j <= 4 ; j ++){
            if(um.find(students[i][j]) == um.end()) continue;       // 해당 좋아하는 학생이 아직 배치안된 경우 넘어감

            int r = um[students[i][j]].first; int c = um[students[i][j]].second;    // 좋아하는 학생의 자리(r,c)
            for(int k = 0 ; k < 4 ; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr <= 0 || nr > N || nc <= 0 || nc > N || board[nr][nc]) continue;
                int val = chk(nr,nc,board,students[i]); // 후보 자리(nr,nc)의 점수가 기존최고 동일 혹은 갱신일 시 list에 삽입
                if(val > maximum){  // 최고점수 갱신 시 기존 후보자들 삭제
                    maximum = val;
                    list.clear();
                    list.push_back({nr,nc});
                }
                else if(val == maximum){
                    list.push_back({nr,nc});
                }
            }
        }

        if(list.size() == 1){   // (1) 에 의한 후보지가 하나일 시  바로 continue;
            board[list[0].first][list[0].second] = sid;
            um[sid] = {list[0].first, list[0].second};  // um등록
            continue;
        }
        else if(list.size() == 0){  // (1)에 의한 후보가 0개일 시? 모든 빈칸이 (2) 후보로
            for(int r = 1 ; r <= N ; r++){
                for(int c = 1 ; c <= N ; c++){
                    if(!board[r][c]) list.push_back({r,c});
                }
            }
        }

        // (2) 규칙 적용
        // 현재 리스트에는 최소 2개이상
        maximum = 0; // 새로운 점수는 빈칸개수
        vector<pos> blank_list; // 빈칸개수가 최대인 애들 담을 list
        for(pos p : list){
            int val = chk_blank(p.first, p.second, board);
            if(val > maximum){  // 최고점수 갱신 시 기존 후보자들 삭제
                maximum = val;
                blank_list.clear();
                blank_list.push_back({p.first, p.second});
            }
            else if(val == maximum){
                blank_list.push_back({p.first, p.second});
            }
        }

        if(blank_list.size() == 1){
            board[blank_list[0].first][blank_list[0].second] = sid;
            um[sid] = {blank_list[0].first, blank_list[0].second};  // um등록
        }
        else{   // (3) 규칙적용 - 2규칙에 의해 여러개라면, r,c가 가장 작은 위치로
            sort(blank_list.begin(), blank_list.end());
            board[blank_list[0].first][blank_list[0].second] = sid;
            um[sid] = {blank_list[0].first, blank_list[0].second};  // um등록
        }
    }

    // 만족도게산
    int answer = 0;
    for(int i = 0 ; i < N*N ; i++){
        int sid = students[i][0];
        int val = chk(um[sid].first, um[sid].second, board, students[i]);
        if(val == 0) answer += 0;
        else if(val == 1) answer += 1;
        else if(val == 2) answer += 10;
        else if(val == 3) answer += 100;
        else if(val == 4) answer += 1000;
    }

    cout << answer << endl;
}