// 

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& s1, string& s2){
    return s1 + s2 < s2 + s1;
}

string solution(vector<int> numbers) {
    // init
    vector<string> s;
    string answer = "";
    
    // logic
    for(int i = 0; i < numbers.size() ; i++){
        s.push_back(to_string(numbers[i]));
    }
    
    sort(s.begin(), s.end(), cmp);
    
    for(int i = numbers.size() - 1 ; i >= 0 ; i--){
        answer += s[i];
    }
    
    // 00000 일시 0이 되도록
    if(answer[0] == '0') return "0";
    
    return answer;
}