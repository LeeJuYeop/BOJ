// multiset 활용

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    // init
    vector<int> answer = {0,0};
    multiset<int, greater<int>> ms;
    
    // logic
    for(string op : operations){
        char code = op[0];
        int num = stoi(op.substr(2, op.size()));
        
        if(code == 'I'){
            ms.insert(num);
        }
        else if(code == 'D' && num == -1){
            if(ms.size() != 0){
                ms.erase(prev(ms.end()));
            }
        }
        else if(code == 'D' && num == 1){
            if(ms.size() != 0){
                ms.erase(ms.begin());
            }
        }   
    }
    
    if(ms.size() >= 1){
        answer[0] = *ms.begin();
        answer[1] = *(prev(ms.end()));
    }
    
    return answer;
}