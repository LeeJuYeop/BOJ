// 2차원 DP
//   0 1 2 3 4 5 6 7 8 9 10
// 1 1 1 1 1 1 1 1 1 1 1 1
// 2 1 1 2 2 3 3 4 4 ? 5 6
// 5 1 1 2 2 3 4 5 6 7 8 ?

// 1 2 로 8을 만드는 경우
// 2 없이 1 로만 8을 만드는 경우인 1
// 2가 하나 있어 1 로만 나머지 6을 만드는 경우인 1
// 2가 두개 있어 1 로만 나머지 4를 만드는 경우인 1
// 2가 3개 있어 1 로만 나머지 2를 만드는 경우인 1
// 2가 4개 있어 1 로만 나머지 0을 만드는 경우인 1
// 합치면 5가지

// 1 2 5 로 10을 만드는 경우
// 5가 없이 1 2 로만 10을 만드는 경우인 6
// 5가 하나 있어 1 2 로만 나머지 5를 만드는 경우인 3
// 5가 두개 있어 1 2 로만 나머지 0을 만드는 경우인 1

// 점화식 유도 
// i-1의 값들을 참조하며, j, j-coin[i], j-coin[2*i] ... 을 더한 뒤
// 만약 j가 i의 배수라면 1을 마지막에 추가해준다.
// 이 조건을 다르게 바꾸면, j=0을 모두 1로 바꿔주면 if문 없이 구현 가능하다.
// DP[i][j] = while(j- (x * coin[i] > 0) {dp[i-1][j- (x * coin[i])]}
// if(j%i==0){D[i][j]+=1;} 혹은 DP[i][0] = 1


// 메모리 초과!
// 문제에서는 4MB인데 GPT 물어보니 백만정도 크기 배열이 4MB에 근접한다고 한다.
// https://www.youtube.com/watch?v=LBOQikSpfNg
// 1. 2차원 DP의 점화식이 i-1까지만 쓴다면? 1차원으로 줄여 메모리를 줄일 수 있다.
// 2. 내가 세운 점화식(위)은 더 단순하게 수정 가능하다.
// 3. 2차원 DP에서, 코인이 5라면 j=5부터 연산이 필요하다. 즉 쓸데없는 연산을 줄일 수 있다
// 1 2 5로 10을 만드는 경우에서 5가 없이 만드는 DP[i-1][j] 6가지
// 5 가 있이 만드는 경우인 DP[i][j-coin[i]] (j-coin[i] >= 0) 4가지
// 11111+5 1112+5 122+5 5+5

#include <iostream>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int coin[N];
    for(int n = 0 ; n < N ; n++){
        cin >> coin[n];
    }

    // 1. 2차원 DP의 점화식이 i-1까지만 쓴다면? 1차원으로 줄여 메모리를 줄일 수 있다.
    // 방법은 간단하다. 점화식에서 i를 없애버린다.
    // 
    int DP[K+1] = {1,};
    for(int c = 0 ; c < N ; c++){
        for(int j = coin[c] ; j < K+1 ; j++){     // 3. j 시작을 현재 coin value로 설정하여 쓸데없는 연산을 줄인다.
            DP[j] = DP[j] + DP[j-coin[c]];        // 2. 바뀐 점화식 적용.
        }
    }
    cout << DP[K] << endl;
}