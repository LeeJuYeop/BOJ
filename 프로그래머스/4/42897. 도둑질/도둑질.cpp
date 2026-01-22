// 1 -> (1)
// 1 2 (2)
// 1 2 3 (1 3)
// 1 2 3 1 (1 3) vs (2 1)   // 마지막1을 집을 시 맨앞1은 제외되어야함... <- 맨앞 집는경우. 안집는경우 2개 비교??
// dp[i] = max(dp[i-2] + money[i], dp[i-1]);

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    // init
    int answer = 0;
    vector<int> dp(money.size(), 0);
    
    // logic
    // 맨앞을 선택하는 경우(마지막집 불가능)
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);
    for(int i = 2 ; i < dp.size()-1 ; i++){
        dp[i] = max(dp[i-2] + money[i], dp[i-1]);
    }
    
    answer = dp[dp.size()-2];
    
    // 맨앞을 선택하지 않는 경우(마지막집 가능)
    dp[0] = 0;
    dp[1] = money[1];
    for(int i = 2 ; i < dp.size() ; i++){
        dp[i] = max(dp[i-2] + money[i], dp[i-1]);
    }
    
    answer = max(answer, dp[dp.size()-1]);
    
    return answer;
}