// 초록겜창과 파랑겜창 서로 수직인거 안지켜도되니까 둘 다 테트리스느낌으로 초록으로 바꾼다.
// (3,0)(3,1) => 초록색 01, 파란색33
// (1,1) => 초록색1, 파란색1
// 즉 초록은 y값에, 파랑은 x값에 영향받게

#include <iostream>
#include <vector>
using namespace std;

int score;

// checkline : 해당 x행이 다 차있는지 확인
bool checkLine(int x, vector<vector<int>>& game){
    if(game[x][0] && game[x][1] && game[x][2] && game[x][3]) return true;
    return false;
}

// checkhigh : 연한칸이 차있는지 확인
int checkhigh(vector<vector<int>>& game){
    int cnt = 0;
    if(game[0][0] || game[0][1] || game[0][2] || game[0][3]) cnt++;
    if(game[1][0] || game[1][1] || game[1][2] || game[1][3]) cnt++;
    return cnt;
}

// 타일배치함수(타일 t,x,y를 줘서 초록이랑 파랑에 각각 배치)
void tile(int t, int k, vector<vector<int>>& game){
    int x = 0;
    while(x <= 4){
        if(!game[x+1][k]) x++;  // 
        else break;
        if(t==2 && game[x][k+1]){x--; break;}
    }

    game[x][k] = 1;
    if(t == 2) game[x][k+1] = 1;
    if(t == 3) game[x-1][k] = 1;
}

// 클리어함수(특정 칸을 비운다.
void clear(int x, vector<vector<int>>& game){
    game[x][0] = 0;
    game[x][1] = 0;
    game[x][2] = 0;
    game[x][3] = 0;
}

// 땡기기함수(x행에서 1칸 땡겨서 위 모든 타일이 1칸 내려오게)
void pull(int x, vector<vector<int>>& game){
    for(int i = x ; i >= 1 ; i--){
        game[i][0] = game[i-1][0];
        game[i][1] = game[i-1][1];
        game[i][2] = game[i-1][2];
        game[i][3] = game[i-1][3];
        clear(i-1, game);
    }
}


int main(){
    int n; cin >> n;
    int t,x,y;
    vector<vector<int>> green(6, vector<int>(4,0));
    vector<vector<int>> blue(6, vector<int>(4,0));

    // logic
    // 1. 블록을 놓는다.
    // 2. 꽉찬행을 위에서부터 찾는다.
    // 3. 연한칸 개수를 센다.
    while(n--){
        cin >> t >> x >> y;

        tile(t,y,green); // 1. 타일배치
        if(t==2) t = 3;
        else if(t==3) t = 2;
        tile(t,x,blue);

        for(int i = 2 ; i <= 5 ; i++){ // 2. 위에서부터 점수낼 수 있는지 확인
            if(checkLine(i, green)){
                clear(i, green);
                pull(i, green);
                score++;
            }
            if(checkLine(i, blue)){
                clear(i, blue);
                pull(i, blue);
                score++;
            }
        }

        // 3. 연한칸 로직
        for(int k = checkhigh(green) ; k > 0 ; k--){
            clear(5, green);
            pull(5, green);
        }
        for(int k = checkhigh(blue) ; k > 0 ; k--){
            clear(5, blue);
            pull(5, blue);
        }
    }

    // 남은 타일 개수세기
    int cnt = 0;
    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            if(blue[i][j]) cnt++;
            if(green[i][j]) cnt++;
        }
    }

    cout << score << endl;
    cout << cnt << endl;

    return 0;
}