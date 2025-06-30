#include <iostream>
#include <string.h>
using namespace std;

// 로직
// 이번 가로등 tmp의 위치가 정해지면, 이전 가로등인 pred까지의 구간에 대해서 밝기가 확정되므로 이를 배열에 기록한다.
// 아니근데 L 왜이리 수가 커. 십억보다 0이 9개많으면...
// imos법을 이용하기

long long L;
int N, K;
int arr[500001]; // 밝기는 최대 500000(K의 최댓값)까지 가능.
long long pred, tmp, interval;

void imos(){
    // imos 누적 : 1번째 가로등
    cin >> tmp;
    arr[0] += 1;
    arr[tmp+1] -= 1;
    pred = tmp;
    // imos 누적: 1 ~ N-1 번째 가로등
    for(int i = 1 ; i < N ; i++){
        cin >> tmp;
        interval = tmp - pred;
        pred = tmp;
        if(interval == 1){continue;} // 가로등끼리 붙어있으면 넘어간다

        arr[0] += 2;    // 시작지점인 0
        arr[(interval/2) + 1] -= 1;
        if((interval)%2==0){
            arr[(interval/2)] -= 1;
        }
        else{
            arr[(interval/2) + 1] -= 1;
        }
    }
    // imos 누적: 마지막 N번째 가로등 ~ 마지막 지점
    arr[0] += 1;
    arr[L - tmp + 1] -= 1;

    // imos 계산하기
    for(int i = 1 ; i < 500001 ; i++){
        arr[i] = arr[i-1] + arr[i];
    }
    arr[0] = N; // arr[0] 정상화(가로등 개수만큼)
    // cout << arr[0] << endl;  // 디버깅
    // cout << arr[1] << endl;
    // cout << arr[2] << endl;
    // cout << arr[3] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> L >> N >> K;
    imos();
    // 정답 출력
    int cnt{0};
    while(cnt != K){
        for(int i = 0 ; i < K ; i++){
            for(int j = 0 ; j < arr[i] ; j++){
                cout << i << endl;
                cnt++;
                if(cnt == K){return 0;}
            }
        }
    }

    

    // for(int i = 0 ; i < N ; i++){
    //     cin >> tmp;
    //     interval = tmp - pred;

    //     arr[0]++;   // 가로등이 늘었으니 그 자리는 밝기 0이 됨.
    //     arr[interval / 2] += 2; // 1 ~ (interval/2) 까지의 밝기가 2개씩 추가됨.
    //     // if((interval)%2==0){
    //     //     arr[tmp-pred/2] -=1;    // interval
    //     // }
    //     pred = tmp;
    // }
    // // 마지막조명~마지막거리까지의 밝기 업데이트.
    // interval = L - pred;
    // if(interval != 0){arr[interval] += 1;}

    // // 계산하기
    // int cur = 0;
    // while(1){
    //     cout << cur << endl;
    // }

}