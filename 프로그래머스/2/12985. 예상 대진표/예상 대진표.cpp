// 라운드가 지날때마다 A와 B는 1/2 된 번호를 부여받는다.
// A 4 2 1
// B 7 4 2
// 짝수였다면 1/2, 홀수였다면 1/2 + 1 이다. (C++정수나눗셈때문에)
// 정답지에서는 더 쉽게, +1 * 1/2 을 한다. 이러면 홀수, 짝수마다 나눌 필요 없이 모두 적용 가능하다.
// 또 A와 B가 같아지는 순간까지의 누적 answer++을 정답으로 한다.

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while(true){
        if(a == b){break;}
        a = (a+1)/2;
        b = (b+1)/2;
        answer++;
    }

    return answer;
}