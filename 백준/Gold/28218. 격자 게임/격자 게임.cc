// BFS DFS 탐색문제.
// 같은 맵에서, 같은 도착점을 기준으로, 다른 시작지점으로 경우를 따지므로
// 도착점을 기준으로 맵의 모든 곳에대해서 걸리는 시간(횟수)을 기록해놓자.


#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int DP[301][301];
int arr[301][301];
int dy[301] = {0, -1};
int dx[301] = {-1, 0};
queue<pair<int,int>> q;

void DFS(){
    q.push(make_pair(N, M));
    DP[N][M] = 0;
    int ny, nx;
    while(!q.empty()){
        int ty = q.front().first;
        int tx = q.front().second;
        q.pop();
        for(int d = 0 ; d < 2 ; d++){   // 위한칸, 왼쪽한칸에 대해서 먼저
            ny = ty + dy[d];
            nx = tx + dx[d];
            if(ny > 0 && ny < N+1 && nx > 0 && nx < M+1 && !arr[ny][nx] && !DP[ny][nx]){
                DP[ny][nx] = DP[ty][tx] + 1;
                q.push(make_pair(ny, nx));
            }
        }

        for(int d = 2 ; d < 2+K ; d++){   // 대각선 이동
            ny = ty + dy[d];
            nx = tx + dx[d];
            if(arr[ny][nx]){    // 한번 벽에 막히면 더 이상 대각선으로 이동하지 않음
                break;
            }
            if(ny > 0 && ny < N+1 && nx > 0 && nx < M+1 && !DP[ny][nx]){
                DP[ny][nx] = DP[ty][tx] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main(){
    cin >> N >> M >> K;
    string input;
    for(int i = 1 ; i < N+1 ; i++){
        cin >> input;
        for(int j = 1 ; j < M+1 ; j++){
            if(input[j-1] == '.'){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = 1;
            }
        }
    }
    // dy dx 세팅
    for(int k = 1 ; k < K+1 ; k++){
        dy[1+k] = -k;
        dx[1+k] = -k;
    }

    // 로직시작
    DFS();
    
    int T, y, x;
    cin >> T;
    for(int t = 0 ; t < T ; t++){
        cin >> y >> x;
        if(DP[y][x]%2 == 0){
            cout << "Second" << endl;
        }
        else{
            cout << "First" << endl;
        }
    }
}