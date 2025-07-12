#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k;
    int ans{0};
    while(cin >> n >> k){
        int stamp{n};
        int coupon{0};
        while(stamp != 0){
            ans += stamp;   // 시켜먹기
            coupon += stamp;    // 쿠폰개수에 시켜먹은 개수만큼 더해짐
            stamp = coupon / k;    // 쿠폰을 stamp로 전환
            coupon = coupon % k;    // 남은 쿠폰 개수 저장
        }
        cout << ans << endl;
        ans = 0;
    }
}