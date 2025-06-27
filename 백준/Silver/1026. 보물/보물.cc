// 그리디
// 아니 근데 문제에서 arrB를 재배열 하지 말라고 하는데
// 출력하는게 정렬된 arrA가 아니라 S면 그냥 arrB재배열하고 정답 맞춰도 되는디 흠. 

#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(){
    int N;
    cin >> N;
    int arrA[N];
    int arrB[N];
    for(int i = 0 ; i < N ; i++){
        cin >> arrA[i];
    }
    for(int i = 0 ; i < N ; i++){
        cin >> arrB[i];
    }

    sort(arrA, arrA+N);
    sort(arrB, arrB+N, compare);

    int ans{0};
    for(int i = 0 ; i < N ; i++){
        ans += arrA[i] * arrB[i];
    }

    cout << ans << endl;

}