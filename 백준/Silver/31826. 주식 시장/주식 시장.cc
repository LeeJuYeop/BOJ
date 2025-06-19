#include <iostream>
using namespace std;

int main(){
    int sellList[601]= {0,}; // 양수면 판매물량, 음수면 구매물량
    int price{10000};
    int N, p, x, f;
    cin >> N;
    for(int i = 0 ; i<N ; i++){
        cin >> p >> x >> f;
        if(f==1){       // 구매
            int s = sellList[(p-7000)/10];
            if(s>0){price = p;} // 구매가 이루어지면 price 변경
            sellList[(p-7000)/10] -= x; // order 적용(실제구매/판매 or 예약)
        }
        else{           // 판매
            int s = sellList[(p-7000)/10];
            if(s<0){price = p;} // 판매가 이루어지면 price 변경
            sellList[(p-7000)/10] += x; // order 적용(실제구매/판매 or 예약)
        }
    }
    cout << price << endl;
}