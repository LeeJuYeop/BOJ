#include <iostream>
using namespace std;

int main(){
    int N, tmp;
    int ans{1};
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> tmp;
        if(tmp>1){ans += tmp-1;}
    }
    cout << ans << endl;
}
// 5 7 10 13