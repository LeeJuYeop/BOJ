// 제한
// 2 <= N <= 250,000
// 0 <= Ci <= 10^12 = 1,000,000,000,000 (십억)

// 그리디 vs 그래프
// 쪽방이 많다 = 본방에 없어야 쪽방수만큼 개미 가능하니 이득
// 1. 쪽방이 있는 방은 본방에 배치 안해서 무조건 쪽방수대로 개미 수 늘리기
// 2. 나머지 쪽방이 없는 방은 쪽방있는방이 나올 때 까지 1010...반복
// 3. 마지막에 N방과 1방 이어진거 고려하기

#include <iostream>
using namespace std;

int arr[250001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    long long ans{0};
    long long tmp;
    bool pred{false};
    cin >> N;
    cin >> tmp;
    int first = tmp;                // 1개 입력받기
    for(int i = 0 ; i < N-1 ; i++){ // N-1개 입력받기
        if(tmp > 0){
            ans += tmp;
            pred = false;
        }
        else{
            if(pred){
                pred = false;
            }
            else{
                ans++;
                pred = true;
            }
        }
        cin >> tmp;
    }

    // 마지막 N번째 입력을 1번째 입력과 비교해서 처리
    if(tmp>0){
        ans += tmp;
    }
    else if(!pred && first!=0){
        ans++;
    }

    cout << ans << endl;

}