// 대소문자를 하나로 해야함.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

int main(){
    // init
    int n;
    string opt, word, ret;
    bool chk;    // 이번 옵션에 대해서 단축키 지정이 되었는지 확인하는 변수.
    unordered_map<char, int> cum;
    
    // logic
    cin >> n;
    cin.ignore();     // 버퍼의 줄바꿈 문자를 제거
    while(n--){
        getline(cin, opt);
        chk = false;
        ret = "";
        istringstream iss(opt);
        // 1. 단어 앞글자로 단축키 찾기
        while(iss >> word){
            if(!chk && cum.find(word[0]) == cum.end()){    // 해당 char로 등록된 단축키 없는 경우
                cum[word[0]] = 1;
                cum[word[0]+32] = 1;
                cum[word[0]-32] = 1;
                // [ ] 추가
                ret += '['; ret+= word[0]; ret+= ']'; ret += word.substr(1, word.size() - 1); ret += " ";
                chk = true;
            }
            else{
                ret += word; ret += " ";
            }
        }
        if(chk){
            cout << ret << endl;
            continue;
        } else {ret = "";}
        
        // 2. 모든 char에서 단축키 찾기
        for(int i = 0 ; i < opt.size() ; i++){
            if(opt[i] == ' ') continue;
            if(!chk && cum.find(opt[i]) == cum.end()){
                cum[opt[i]] = 1;
                cum[opt[i]+32] = 1;
                cum[opt[i]-32] = 1;
                // [ ] 추가해서 출력
                ret = opt.substr(0,i) + '[' + opt[i] + ']' + opt.substr(i+1, opt.size());
                cout << ret << endl;
                chk = true;
                break;
            }
        }
        if(chk) continue;
        // 3. 단축키 지정이 안된 경우 그냥 출력
        cout << opt << endl;
    }
}