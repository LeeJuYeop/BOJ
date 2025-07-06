#include <iostream>
using namespace std;

int main(){
    string s;
    int idx;
    int ans{0};
    for(int i = 0 ; i < 8 ; i++){
        cin >> s;
        if(i%2==0){
            idx = 0;
        }
        else{
            idx = 1;
        }

        for(int j = 0 ; j < 4 ; j++){
            if(s[idx + 2*j] == 'F'){
                ans++;
            }
        }
    }
    cout << ans << endl;
}