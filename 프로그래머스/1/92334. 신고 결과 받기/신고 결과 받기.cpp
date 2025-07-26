// 마지막에 처리결과메일을 발송하려면, 어떤 유저가 누구에게 신고당했는지를 파악하고 있어야만 한다.
// um_reported(신고당한유저명:해당유저를신고한유저들 자료구조)을 선언한다.
// 이 떄 한 유저가 다른 유저에 대해서 여러번 신고해도
// 단 한 번만 신고가 적용되기 때문에 "해당유저를신고한유저들 자료구조"는 set으로 한다.
// 1. 주어지는 "report" 벡터에 대해 um_reported를 먼저 작성한다.
// 2. "id_list"를 통해 um_reported를 순회하고, set의 길이가 2 이상이면 set의 유저들의 um_answer을 +1한다.
// 3. 마지막에 um_answer을 순회하여 answer을 채운다.


#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size()); // 벡터는 크기만 주고 초기화 시 초기값 0.
    unordered_map<string, set<string>> um_reported;
    unordered_map<string, int> um_answer;
    
    // 1. 주어지는 report에 따라 어떤 유저가 어떤유저들에게 신고당했는지 기록
    string a, b;
    for(string s : report){
        istringstream iss(s);
        iss >> a >> b;
        um_reported[b].insert(a);
    }
    
    // 2. 어떤 유저가 2명 이상의 유저들에게 신고당할 시 그 유저를 신고한 유저들에게 메일 발송 +1
    for(string &id : id_list){
        if(um_reported.find(id) != um_reported.end()){  // 해당 유저가 신고를 당했는지 여부부터 확인
            if(um_reported[id].size() >= k){
                for(auto &user : um_reported[id]){
                    um_answer[user] += 1;
                }
            }
        }
    }
    
    // 3. um_answer 순회
    for(int i = 0 ; i < id_list.size() ; i++){
        answer[i] = um_answer[id_list[i]];
    }
    return answer;
}