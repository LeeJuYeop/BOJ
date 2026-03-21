// 동전 분배
// 문제를 단순화하면, 총액수/2 인 금액을 만들 수 있냐없냐.

// try 1 탑다운재귀? <- 시간초과
// 모든 동전에 대해서 철수꺼(0)/영희꺼(1) 나눠가면서 따진다. O(N^2), 1원이 100,000개인 최악의 경우에 백억번연산

// try 2 SET이용 <- 시간초과
// DP[i][j] = i번째 코인까지 써서 j금액이 가능하면 true, 아니면, false;
// try 3 바텀업dp를 vector대신 set으로 쓰면 더 안정적인데?
// 최악의 경우인 1원 100,000개에서 이중루프시에 약 50000 * 50000 가 여러번 실행됨

// try 3 DP로 시간초과안나게 여러 작업


#include <iostream>
#include <vector>
using namespace std;

int main(){
    // init
    int n, value, num;
    int total;
    vector<vector<int>> coins;
    vector<bool> dp;

    int t{3};
    while(t--){
        total = 0;
        cin >> n;
        coins.assign(n+1, vector<int>(2,0));
        for(int i = 1 ; i <= n ; i++){
            cin >> value >> num;
            total += value * num;
            coins[i][0] = value;
            coins[i][1] = num;
        }
        if(total % 2 != 0){     // 애초에 금액이 홀수인 경우 일찍 종료
            cout << 0 << endl;
            continue;
        }

        int goal = total/2;
        dp.assign(goal+1, false);
        dp[0] = true;

        // logic
        for(int i = 1 ; i <= n ; i++){  // 최대 100
            value = coins[i][0]; num = coins[i][1];
            for(int j = goal ; j >= value ; j--){ // 최대 50000
                if(dp[j-value]){
                    for(int k = 1 ; k <= num ; k++){ 
                        if(j-value + value * k > goal) break;
                        dp[j-value + value * k] = true;
                    }
                }
            }
        }

        if(dp[goal]) cout << 1 << endl;
        else cout << 0 << endl;
        

    }
}