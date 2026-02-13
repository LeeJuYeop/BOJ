// 단순히 BFS로 하면 시간초과가 난다. 당연히도 경우의수가 1,000,000,007개 이상이란 것을 문제 조건에서 알 수 있다.
// (1)백트래킹 방법도 있을 법하다. 정해진 개수의 오른쪽/아래 만 쓰면된다. 테케에서는 오른쪽3/아래2개.
// (2)대신에 2차원 DP를 활용한다.
// 모든 칸은 자신의 위칸/왼쪽칸의 경우의수를 더한 값을 경우의수로 가진다.
// 따라서 (1,1)부터 (n,m)까지 2차원 DP로 갱신한다.

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    // init
    int answer = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][1] = 1;   // 집의 경우의수가 1이 되도록 임의조작.
    for(auto pud : puddles){    // 물웅덩이는 피해가도록 미리 선점
        dp[pud[1]][pud[0]] = -1;
    }
    
    // logic
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(dp[i][j] == -1){ // 물웅덩이 만날 시 0으로 바꾸고 continue;
                dp[i][j] = 0;
                continue;
            }
            
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
        }
    }
    return dp[n][m];
}