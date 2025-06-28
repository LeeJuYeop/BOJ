// BFS, DFS 로도 풀 수 있나 싶지만 조금 변주를 줘야한다
// "최단 경로", "가능 여부" 를 따지는게 아니라 "모든 경우의 수"를 따져야한다.
// VISIT의 경우에는 필요없어진다. 더 낮은 칸으로 계속 움직이는 룰에 따라서,
// 한 탐색에서 지나쳐온 길은 되돌아가지 못하며, 문제 특성 상 같은 칸을 다른 경로로 도달시키는
// 경우도 포함해야 하므로.
// VISIT을 고려하지 않아도 되는 점 때문에 더욱 BFS나 DFS로 가능해보인다.
// BFS를 뿌린다.
// 1. 탐색이 맨오른쪽 아래에 도달하면 H(정답)을 +1, 도달 못한 탐색은 소멸.
// 2. 탐색 중 갈래길(칸이 더 낮은 칸이)이 한곳, 두곳, 세곳이 나올 수 있는데 이 때 탐색이 분화
// 3. DFS도 가능하다. queue에서 stack으로 바꾸면 깊이 우선이 될 것이고, 탐색이 분화되는 2번룰은
// 동일하게 적용 가능하므로

// DP로는 어떻게?
// 50 45 37 32 30
// 35 50 40 20 25
// 30 30 25 17 28
// 27 24 22 15 10
// 점화식 영향을 상하좌우가 다 끼칠 수 있어서(경로가 구불구불 할 수 있으므로)
// 어떤 부분부터 값을 정해나갸아하는지 난감하다.

// DFS로만 푸니 시간초과가 난다.
// 질문게시판 보면 DFS + DP 짬뽕문제같다.
// 그리고 방문한 곳 재방문 없애서 시간초과를 줄여아한다..

// https://www.youtube.com/watch?v=hL-fP-SxpFU
// 이전까지의 2차원 DP처럼 순서를 맨위왼쪽->맨아래오른쪽 으로 매기지 못하고
// DFS를 통해 재귀적으로 호출해야한다.

#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int DP[500][500];
int arr[500][500];

int M, N;

// dfs for DP
int dfs(int ty, int tx){
    if(DP[ty][tx] == -1){   // 첫방문 시에만 계산한다(메모이제이션)
        DP[ty][tx] = 0;
        for(int d = 0 ; d < 4 ; d++){
            int ny = ty + dy[d];
            int nx = tx + dx[d];

            if(ny >= 0 && ny < M && nx >=0 && nx < N 
            && arr[ty][tx] < arr[ny][nx]){
                DP[ty][tx] += dfs(ny, nx);
            }
        }
    }

    return DP[ty][tx];
}

int main(){
    memset(DP, -1, sizeof(DP)); // DP를 -1로 초기화
    DP[0][0] = 1;               // (0,0)좌표 1로 초기화
    cin >> M >> N;
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> arr[i][j];
        }
    }

    cout << dfs(M-1, N-1) << endl;
}