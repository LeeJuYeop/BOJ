#include <iostream>
using namespace std;

int main(){
    int N, t, p;
    cin >> N;
    pair<int, int> arr[N+1];            // 입력받기
    for(int i = 1 ; i < N+1 ; i++){
        cin >> t >> p;
        arr[i] = make_pair(t, p);
    }

    // DP초기화.
    // N의 최댓값은 15이며, t의 최댓값은 20이다.
    // 만일 퇴사일 이후로 상담이 넘어가는 경우 배열 index 에러가 날 수 있다. 대신
    // DP의 초기값을 -16000(p의 최댓값은 1000)으로하면, 퇴사일 이후로 배열 접근시
    // 아주 큰 음수를 가져온다.
    int DP[21];
    fill(DP, DP+21, -16000);
    int tmp;

    // DP의 첫번째 값으로 DP[N]을 초기화 해준다.
    // 상담시간이 1 이상일 시 사실상 못하는 상담이므로 0을 주고
    // 1일일 시 p(N)만큼 초기화
    if(arr[N].first > 1){DP[N]=0;}
    else{DP[N]=arr[N].second;}

    // DP 로직
    // tmp = 해당 날의 상담 수행 + 해당 날의 상담건의 상담일 이후의 DP 최댓값
    // DP[i+1] = 해당 날의 상담을 수행하지 않을 때에는 i+1날과 동일한 값 가짐.
    for(int i = N-1 ; i > 0 ; i--){
        t = arr[i].first;
        p = arr[i].second;

        if(i+t == N+1){tmp = p;}
        else{
            tmp = p + DP[i+t];
        }

        DP[i] = max(tmp, DP[i+1]);
    }
    cout << DP[1];
}