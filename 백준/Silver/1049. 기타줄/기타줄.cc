#include <iostream>
using namespace std;

int main(){
    int n, M;
    cin >> n >> M;
    int tmp6, tmp2;
    int min6{10000};
    int min2{10000};
    for(int i = 0 ; i < M ; i++){
        cin >> tmp6 >> tmp2;
        if(min6 > tmp6){min6 = tmp6;}
        if(min2 > tmp2){min2 = tmp2;}
    }

    // 낱개효율이 비정상적으로 좋다면?
    if(min6 >= 6*min2){
        cout << n * min2 << endl;
        return 0;
    }

    // 일반적인 경우.
    // 6개로 일단 다 사고, 6개 미만으로 남을 때 6개세트 vs 낱개 가격 비교하기
    int ans{0};
    while(n - 6 >= 0){
        n -= 6;
        ans += min6;
    }

    if(min6 < min2 * n){
        ans += min6;
    }
    else{
        ans += min2 * n;
    }

    cout << ans << endl;
    return 0;
}