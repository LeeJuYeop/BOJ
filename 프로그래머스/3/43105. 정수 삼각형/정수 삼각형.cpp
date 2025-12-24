// 탑다운, 바텀업 둘 다 논리적으로는 가능하다.
// 높이 500. 
// 1 + 2 + 3 + ... 500 = 등차수열의 합 = 501 * 500 /2 = 약25000개.
// 하나당 비교 2번하니까 연산 50000번.

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    // init
    int answer = 0;
    int floor = triangle.size();
    vector<vector<int>> dp(500, vector<int>(0, 0));
    dp[floor-1] = triangle[floor-1];
    
    // logic
    for(int i = floor - 1 ; i >= 1 ; i--){
        for(int j = 0 ; j < triangle[i].size()-1 ; j++){
            dp[i-1].push_back(triangle[i-1][j] + max(dp[i][j], dp[i][j+1]));
        }
    }
    
    return dp[0][0];
}