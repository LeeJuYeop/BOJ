// # 단순히 브루트포스하면 N^2문제다
// # 백만개니까 N^2으로 안풀린다. 제한시간이 얼마인지 모르지만 NlogN이 최대

// # unordered_map에 집어넣으며, 집어넣을 때 접두사가 되는 모든 경우로 넣는다.
// # 예를들어 123이면 1, 12, 123을 넣는다.
// # 그러면 다음번에 12가 들어오면 중복인 것을 알 수 있다.
// # 문제는 번호길이가 최대 20이라 백만 * 20 = 2천만개 2천만개
// # 재미나이피셜 메모리256mb기준 9백만개정도라서 될라나?
// 그 후 다시 phone_book의 것들을 해쉬에서 찾아 있다면 false;

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> h;

bool solution(vector<string> phone_book) {
    bool answer = true;
    for(string s : phone_book){
        for(int i = 1 ; i < s.size() ; i++){
            h.insert({s.substr(0, i), 1});
        }
    }
    
    for(string s : phone_book){
        if(h.find(s) != h.end()){
            answer = false;
            break;
        }
    }
    
    return answer;
}