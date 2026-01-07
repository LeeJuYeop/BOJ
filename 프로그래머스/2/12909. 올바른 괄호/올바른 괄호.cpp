#include<string>
#include <iostream>

using namespace std;

bool solution(string s){
    // init
    bool answer = true;
    int cnt = 0;

    // logic
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == '('){
            cnt++;
        }
        else{
            if(cnt>0){
                cnt--;
            }
            else{
                return false;
            }
        }
    }

    if(cnt == 0) return true;
    else return false;
}