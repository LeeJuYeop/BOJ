// 다리끼리 못겹친다 = Ni 다리가 Ni-1 다리보다 더 위의 Mj 사이트를 차지할 수 없다.
// 1 1 경우 1
// 1 2 경우 2
// 1 3 경우 3
// 1 4 경우 4
// 1 5 경우 5
// 2 1 경우 1
// 2 2 경우 1
// 2 3 경우 = 1 2 경우 + 1 1 경우 == 1 2 경우 + 2 2 경우
// 2 4 경우 = 1 3 경우 + 1 2 경우 + 1 1 경우 = 6 == 1 3 경우 + 2 3 경우
// 2 5 경우 = 1 4 경우 + 1 3 경우 + 1 2 경우 + 1 1 경우 == 1 4 경우 + 2 4 경우
// DP로 푸는법
// 0 1 2 3 4 5 <- j
// 0 1 2 3 4 5 <- i = 1
// 0 0 1 3 6 10
// 0 0 0 1 4 10
// 0 0 0 0 1 5
#include <iostream>
#include <string.h>
using namespace std;

int DP[51][51];

int main(){
    int T, N, M;
    cin >> T;
    for(int t = 0 ; t < T ; t++){
        cin >> N >> M;
        memset(DP, 0, sizeof(DP));

        for(int j = 0 ; j < M+1 ; j++){
            DP[1][j] = j;
        }

        for(int i = 2 ; i < N+1 ; i++){
            for(int j = i ; j < M+1 ; j++){
                DP[i][j] = DP[i-1][j-1] + DP[i][j-1];
            }
        }

        cout << DP[N][M] << endl;
        
    }
}