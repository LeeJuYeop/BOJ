// 제한
// 2 <= N <= 250,000
// 0 <= Ci <= 10^12 = 1,000,000,000,000 (십억)

// 그리디
// 쪽방이 많다 = 본방에 없어야 쪽방수만큼 개미 가능하니 이득
// 1. 쪽방이 있는 방은 본방에 배치 안해서 무조건 쪽방수대로 개미 수 늘리기
// 2. 나머지 쪽방이 없는 방은 쪽방있는방이 나올 때 까지 1010...반복
// 3. 마지막에 N방과 1방 이어진거 고려하기

// 반례 0 0 1 1 0
// 나는 입력들어온 대로 바로바로 처리해줬다. <- 여기서 문제 발생.
// 첫방과 마지막방은 이어져있다는 것에서 문제가 터짐
// 0 0 1 1 0 의 경우 처음 입력 0에서 쪽방이 없으니 개미투입
// 두번째 방에 못들어가고 3,4번째에는 쪽방에
// 마지막방에서는 첫번째방에 개미있으니 안들어가서 출력이 3이다.
// 그러나 답은 4로, 2번째방,마지막방,3과4쪽방 이렇게 4개다.
// 쪽방이 0인 방은 입력이 들어온 순간에 정해질 수 없다. 전체를 보고 결정난다.
// 1. 쪽방이 있는 방은 여전히 쪽방수대로 개미 수 늘리기
// 2. 나머지 쪽방이 없는 방에 대해서는 일다 입력을 다 받기
// 3. 나머지 모든 구간에 대해서는 쪽방이 없는 본방이 나오자마자
// 개미를 배치시키면 되는데, 첫번째방과 마지막방이 함께 속한 쪽방없는 구간만
// 잘 주무르면 된다.

#include <iostream>
using namespace std;

unsigned long long arr[250000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    unsigned long long ans{0};
    unsigned long long tmp;
    bool pred{false};
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> arr[i];
    }

    // 1. 쪽방이 있는 방은 쪽방수만큼 개미+하기
    // 2. 쪽방이 없는 방은 개미 배치 0 x 0 x 0 x.... 반복하기
    tmp = arr[0];
    int first = tmp;
    for(int i = 1 ; i < N ; i++){
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
        tmp = arr[i];
    }
    // 마지막 N번째 입력에 대해
    if(tmp > 0){ans+=tmp;}
    else if(!pred && first!=0){ans++;}

    // 3. 순환구간(첫번째방과 마지막방이 포함된 구간)이 있다면 재처리하기
    if(arr[0] == 0 && arr[N-1] == 0){
        int end = 0;
        int start = N-1;
        while(arr[start]==0 && start > 0){
            start--;
        }
        while(arr[end]==0 && end < N-1){
            end++;
        }

        if(start < end){
            cout << ans << endl;
            return 0;
        }   
        
        // 0 0 1 1 0 이면 end=2 start = 3
        // length = 1 + 2 = 3
        // length가 짝수면 상관없음
        // length가 홀수면 의심
        // 1~쪽이 홀, ~N쪽이 짝이면 문제없
        // 1~쪽이 짝, ~N쪽이 홀이면 문제있
        int length = (N-1-start) + end;
        if(length%2 == 1 && end%2 == 0){
            ans++;
        }
    }

    cout << ans << endl;

}