#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int tmp;
    int ans{0};
    for(int i = 0 ; i < 5 ; i++){
        cin >> tmp;
        ans += pow(tmp, 2);
    }
    ans %= 10;
    cout << ans << endl;
    
}