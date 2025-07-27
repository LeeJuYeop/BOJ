// 

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> um;
int course_length;

void combi(string extra, string s){
    // couse에 명시된 길이면 um에 코스로 등록
    if(s.length() == course_length){
        um[s]++;
        return;
    }
    // 조합 재귀로직
    for(int i = 0 ; i < extra.size() ; i++){
        combi(extra.substr(i+1), s + extra[i]);
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    // 문제 테케3번처럼 order가 알파벳순으로 정렬되어있지 않은 경우가 있다.
    // 이러면 WX와 XW를 다른 코스로 보는 상황이 발생하므로 정렬해준다.
    for(int i = 0 ; i < orders.size() ; i++){
        sort(orders[i].begin(), orders[i].end());
    }
    
    // 로직은 각 코스길이에 대하여 각각 조합을 구하고, 조합중에서 최대 등장빈도를 구해서 그 조합들을 answer에 추가한다.
    for(int tmp_len : course){
        course_length = tmp_len;
        // 1. 이번 코스길이에 대하여 가능한 모든 경우 um에 등록.
        for(string menu : orders){
            combi(menu, "");
        }
        // 2. 이번 코스길이에서 가장 많이 등장한 코스의 등장횟수 확인
        int max_course{0};
        for(auto &tmp : um){
            max_course = max(max_course, tmp.second);
        }
        // 3. 최대등장횟수에 해당하는 메뉴들 answrer에 추가
        for(auto &tmp : um){
            if(tmp.second == max_course && tmp.second > 1){
                answer.push_back(tmp.first);
            }
        }
        
        um.clear();
        
        
    }
   
    // 마지막에 문제의 조건대로 answer 정렬하기
    sort(answer.begin(), answer.end());
    return answer;
}