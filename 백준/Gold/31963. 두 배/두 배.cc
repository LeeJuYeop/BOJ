// 정보올림피아드 두 배
// 수열길이 250,000 이하.
// Ai 범위 1~1,000,000

// 뭔가 단순생각하기로는 배열 첫번째부터 돌면서 이전값기억 + 이전값이상으로 곱하기 반복
// 이지만 그렇게 쉬울까싶다.
// 낭비를 줄이는 방법으로는 실제 필요한 것은 연산 횟수니까
// 연산은 하지 않고 넘어가기
// 어차피 참고하는 것은 Ai-1 하나이니까 입력 전체 저장하지 않기.

#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int pred{0};
    int cnt(0);
    int tmp;

    for(int i = 0 ; i < N ; i++){
        cin >> tmp;
        while(tmp < pred){
            tmp *= 2;
            cnt++;
        }
        pred = tmp;
    }

    cout << cnt << endl;
}