// 처음 접근방법은 BFS를 이용한 방법. 방법 자체는 가능하나 조금 돌아가는 면이 있었다.
// 1. 서순문제. 55 / 5 와 5 / 55는 다르다. 이런 서순을 고려하지 못했다.
// 2. 이어붙인 수(5, 55, 555) 문제. BFS는 최단을 구하므로 큐에 사용횟수가 적은게 아래로 가야하는데
// 초기에 5, 55, 555를 다 넣고 시작하니 문제가 되었다.

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if(N == number) return 1;       // 9번 테스트케이스.
    
    // init
    int answer = 0;
    vector<unordered_set<int>> dp(9);   // dp[i] : i개의 N으로 만들 수 있는 수들의 집합.
    dp[0].insert({0});
    dp[1].insert({N});
    
    // logic
    for(int i = 2 ; i <= 8 ; i++){
        // 1. m개의 N 이어붙인 수 추가하기.
        int nm = N;
        for(int m = 2 ; m <= i ; m++){
            nm = nm * 10 + N;
        }
        dp[i].insert(nm);
        
        // 2. dp[j]와 dp[i-j]의 수들 사칙연산하여 dp[i]에 추가하기
        for(int j = 1 ; j < i ; j++){
            for(int a : dp[j]){
                for(int b : dp[i-j]){
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if(b != 0) dp[i].insert(a / b);
                }
            }
        }
        
        // 3. 이번 i 개의 N을 써서 만들 수 있는 수 중에 number가 존재한다면 i를 리턴
        if(dp[i].find(number) != dp[i].end()) return i;
    }
    
    return -1;
}