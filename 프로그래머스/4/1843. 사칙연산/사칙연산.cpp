// 통나무 문제랑 비슷하다. 지역최대를 다 구하기.
// 1 - 3 + 5 - 8
// 두개의 괄호로 나누는 경우는 1, -3+5-8 // 1-3, + 5-8 // 1-3+5, -8
// 이런식...
// dp[i][j] : i에서 j까지 범위 연산에서 최댓값
// 구하려는 수 = dp[0][3] = max(dp[0][0] - dp[1][3], dp[0][1] + dp[2][3], dp[0][2] - dp[3][3]);
// 부호도 고려해야함. => 숫자벡터와 부호벡터 나누기

// 지역최댓값으로 해버리면 (지역최대) - (지역최대) 가 나와버린다...
// 만약 앞 부호가 "-" 라면 지역최소 구하기?

#include <vector>
#include <string>
using namespace std;

int solution(vector<string> arr){
    // init
    int tmp = 0;
    // arr을 숫자벡터와 부호벡터로 나누기.
    vector<int> nums;
    vector<string> signs;
    for(int i = 0 ; i < arr.size() ; i++){
        if(i % 2 == 0) nums.push_back(stoi(arr[i]));
        else signs.push_back(arr[i]);
    }
    // dp값 초기화. diag 0 = 자기자신값.
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
    for(int i = 0 ; i < nums.size() ; i++) dp[i][i] = nums[i];
                           
    // logic
    for(int diag = 1 ; diag < nums.size() ; diag++){
        for(int i = 0 ; i < nums.size() - diag ; i++){
            int j = i + diag;
            dp[i][j] = -1000000;
            
            if(i > 0 && signs[i-1] == "-"){ // 지역최소 구해야함.
                dp[i][j] *= -1;
            }
            
            for(int k = i ; k < j ; k++){
                if(signs[k] == "+") tmp = dp[i][k] + dp[k+1][j];
                else if(signs[k] == "-") tmp = dp[i][k] - dp[k+1][j];
                
                if(i > 0 && signs[i-1] == "-"){ // 지역최소 구해야함.
                    dp[i][j] = min(dp[i][j], tmp);
                }
                else{                           // 지역최대
                    dp[i][j] = max(dp[i][j], tmp);
                }
                
            }
        }
    }
    
    return dp[0][nums.size()-1];
} 