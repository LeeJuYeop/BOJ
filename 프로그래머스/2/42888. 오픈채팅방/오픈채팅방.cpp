// uid:닉네임을 추적하는 해시 하나
// uid:[enter 혹은 leave] 를 시간순으로 관리하는 벡터 하나
// uid는 고유하며 바뀌지 않는 것을 이용한다.
// O(N)

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> um;
    vector<pair<string, string>> vec;
    
    // record의 명령어 파싱해서 um(uid:닉네임), vec(uid:행동) 채우기
    string word;
    for(string tmp : record){
        istringstream iss(tmp);
        vector<string> order;
        while(iss >> word){
            order.push_back(word);
        }
        
        // 명령(입장, 닉변, 퇴장)에 따라 분기 나누기
        if(order[0] == "Enter"){
            vec.push_back(make_pair(order[1], order[0])); // uid:Enter 로 벡터에 push_back
            um[order[1]] = order[2];                     // 첫 등장일 경우 고려하여 um에 uid:닉네임 등록
        }
        else if(order[0] == "Leave"){
            vec.push_back(make_pair(order[1], order[0])); // uid:Leave로 벡터에 push_back
        }
        else if(order[0] == "Change"){
            um[order[1]] = order[2];
        }
    }
    
    // 최종 닉네임에 따라 answer 구성하기
    for(pair<string, string> tmp : vec){
        if(tmp.second == "Enter"){
            answer.push_back(um[tmp.first] + "님이 들어왔습니다.");
        }
        else if(tmp.second == "Leave"){
            answer.push_back(um[tmp.first] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}