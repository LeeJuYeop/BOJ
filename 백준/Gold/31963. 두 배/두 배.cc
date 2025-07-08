// 정보올림피아드 두 배
// 수열길이 250,000 이하.
// Ai 범위 1~1,000,000

// 뭔가 단순생각하기로는 배열 첫번째부터 돌면서 이전값기억 + 이전값이상으로 곱하기 반복
// 이지만 그렇게 쉬울까싶다.
// 낭비를 줄이는 방법으로는 실제 필요한 것은 연산 횟수니까
// 연산은 하지 않고 넘어가기
// 어차피 참고하는 것은 Ai-1 하나이니까 입력 전체 저장하지 않기.
// while문으로 *2 돌리니 역시나 제한조건 없음에서 시간초과

// 숫자 A B가 있고. B가 A보다 커지기 위해 X2씩 연산이 가능한데 이 횟수를 알아내기..
// 곱하기 2씩을 한다 = 2 4 8 16 32 64 128 256 512...을 곱한다
// A를 B로 나눈 몫을 확인한다.
// 몫이 1초과면 2, 2초과면 4, 4초과면 8, 8초과면 16...이런 식으로 필요하다!!
// 128/16 = 8 == 8(3번)
// 128/20 = 7.xx == 8
// 128/24 = 5.xx = 8
// 128/31 = 4.xx = 8
// 128/32 = 4 == 4
// 128/60 = 2.xx == 4(2번)
// 128/64 = 2 = 2(1번)
// 128/69 = 1.xx == 2
// 128/100 = 1.xx == 2(1번)
// 128/128 = 1 == 1(0번)
// 1024 4096 8192 
// 2의 10승 = k = 천
// 2의 20승 = m = 백만
// log2를 사용한 점회식으로 생각하면?
// tmp * 2^y >= pred
// 양변로그2
// log(tmp) + y >= log(pred)
// y >= log2(pred/tmp)
// int y = ceil(log2((double)pred/tmp))

// 틀렸습니다가 나온다. 점화식 문제는 아니고 오버플로우 문제였다.
// if(tmp < pred){
//     long long k = ceil(log2((double)pred / tmp));
//     ans += k;
//     pred = tmp << k;
// }
// 위의 문제는 무엇일까? pred를 새로 갱신하다보면 언젠가 값이 매우 커진다.
// 그냥 표현하기에는 long long으로 충분하지만? 점화식 계산에서
// (double)로 형변환을 할 때 표현가능한 범위 차이로 오버플로우가 나버린다.
// 즉 우리는 주어진 수열을 수정하면 안된다. 단지 k의 값만 구한다.
// N길이의 배열을 하나 만들고 여기에 각 i에서 k가 몇이었나를 기록한다.
// 그리고 점화식을 tmp * 2^y >= pred * 2*x (x는 배열에 저장 중인 값 불러오기)
// y >= log2(pred/tmp) + x
// y = ceil(log2(pred/tmp) + x
// 


#include <iostream>
#include <cmath>
using namespace std;

int arr[250001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long ans{0};
    int N;
    cin >> N;
    long long pred{0};
    long long tmp;

    for(int i = 1 ; i < N+1 ; i++){
        cin >> tmp;
        arr[i] = ceil(log2((double)pred / tmp)) + arr[i-1];
        if(arr[i] < 0){arr[i]=0;}
        ans += arr[i];
        pred = tmp;
    }

    cout << ans << endl;
}

