// 도미노 (Small)

// DP[k] = 도미노 k까지 주어질 때 모든 도미노를 쓰러뜨리기 위해 넘어뜨려야하는 최소개수
// xlast = 마지막으로 쓰러진 도미노가 휩쓴 최대 x
// DP[k]는
// (1) x <= xlast 라면 DP[k-1], xlast 갱신
// (2) x > xlast 라면 DP[k-1] + 1, xlast갱신
// (3) 왼쪽으로 넘어뜨릴 때 쓰러뜨리기 가능한 가장왼쪽 도미노 ln을 구해서 dp[ln-1] + 1과 비교 
// 도미노가 300개 뿐이라 가능할듯?
// 문제점
// 중간에 왼쪽으로 결정한 놈을 다시 오른쪽으로 바꿀 수가 없다. - local minimum

// 2. 메모이제이션 DP
// 모든 도미노에 대해서 왼쪽/오른쪽으로 넘어뜨릴시 몇번째 도미노까지 쓰러뜨리는지 미리 메모이제이션해둔다.
// DP[k]에 대해서
// 1. 오른쪽넘어뜨림/왼쪽넘어뜨림 가정하고 최솟값 계산해보기 = min(dp[k-1] + 1, dp[left[k] - 1] + 1);
// 2. 앞선 도미노에의해 쓰러지는 경우 생각해서, 내앞의 모든 도미노를 보면서, 현재 도미노(k)를 쓰러뜨릴 수 있는 도미노들(l)에 대해서 dp[l-1] + 1 을 후보로 검사

// 정리
// 최소를 찾는 문제이므로 DP가 필요하다
// 문제의 핵심은 모든 도미노에 대해서 왼쪽넘어뜨리기/오른쪽넘어뜨리기/앞선도미노에의해휩쓸리기 라는 3가지 선택지에 대해서 모두 검사하는 것이다.
// DP[k] = 도미노 k까지 주어질 때 모든 도미노를 쓰러뜨리기 위해 넘어뜨려야하는 최소개수
// 여기에서 DP[k]를 정할 때, 왼쪽넘어뜨리기(dp[left[k] - 1] + 1), 오른쪽넘어뜨리기(DP[k-1] + 1)는 바로 구해지며
// 앞선도미노에 의해 휩쓸리는 경우는? 1 ~ k-1을 모두 확인하면서(l) 오른쪽으로 넘어뜨릴 시 k까지 닿는 경우 dp[l-1] + 1 (l이전까지는 알아서 넘어지고, l번째를 오른쪽으로 넘어뜨려 k까지 넘어뜨리기) 도 후보가 된다.
// 메모이제이션 DP를 떠올려야하는 어려운 문제


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;
vector<pair<int,int>> domino;
int N;

// n번째 도미노를 왼쪽으로 넘어뜨릴 시 마지막으로 넘어지는 가장왼쪽 도미노 ln 리턴
int left(int n){
    int xlast = domino[n].first - domino[n].second;
    while(n > 1 && domino[n-1].first >= xlast){
        n--;
        xlast = min(xlast, domino[n].first - domino[n].second);
    }
    return n;
}
int right(int n){
    long long xlast = (long long)domino[n].first + domino[n].second;   // x와 h가 합쳐서 int범위(20억) 넘어갈 수 있음
    while(n < N && domino[n+1].first <= xlast){
        n++;
        xlast = max(xlast, (long long)domino[n].first + domino[n].second);
    }
    return n;
}

int main(){
    // init
    cin >> N;
    dp.assign(N+1, 301);
    domino.assign(N+1, {0,0});
    for(int i = 1 ; i <= N ; i++){
        cin >> domino[i].first;
        cin >> domino[i].second;
    }

    sort(domino.begin(), domino.end());

    // memoization - 왼쪽/오른쪽으로 넘으뜨리면 어느 도미노까지 쓰러뜨릴 수 있는지.
    vector<int> do_left(N+1, 0);
    vector<int> do_right(N+1, 0);
    for(int i = 1 ; i <= N ; i++){
        do_left[i] = left(i); 
        do_right[i] = right(i);
    }

    // logic
    dp[0] = 0;
    dp[1] = 1;
    for(int k = 2 ; k <= N ; k++){
        // 1. 왼쪽넘어뜨리거나, 오른쪽넘어뜨리는 경우에서 계산
        dp[k] = min(dp[do_left[k] - 1] + 1, dp[k-1] + 1);

        // 2. k보다 앞선 도미노 l에 의해 넘어지는 경우에서 계산
        for(int l = 1 ; l < k ; l++){
            if(do_right[l] >= k){
                if(l==1) dp[k] = 1; // l이 첫번째 도미노인 경우 엣지케이스
                else dp[k] = min(dp[k], dp[l-1] + 1);
            }
        }
    }

    cout << dp[N] << endl;
}