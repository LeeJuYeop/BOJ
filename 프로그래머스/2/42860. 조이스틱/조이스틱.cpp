// https://jhzlo.tistory.com/71
// 알파벳에 따른 상하이동횟수 = 고정됨 = um으로 init해두기
// 이동에 따른 좌우이동횟수 = 경우의 수가 여럿임.
// 경우의 수가 여럿인 좌우이동횟수의 경우 특정 A블럭(연속된A구간)의 바로앞과 바로뒤의 idx를 i와 j라고할 때
// i를 찍고 j로유턴 / j를 먼저찍고 i로 유턴
// 하는 두 경우가 있다.

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(string name) {
    // init
    unordered_map<char, int> um;
    string s{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    um['A'] = 0;
    int cur = 0; int icur = 26;
    for(int i = 1 ; i <= 13 ; i++){
        um[s[cur+i]] = i;
        um[s[icur-i]] = i;
    }
    int answer = 0;
    int len = name.size();
    int move = len - 1;
    
    // logic
    for(int i = 0 ; i < name.size() ; i++){
        // 1. 알파벳에 따른 횟수 추가
        answer += um[name[i]];
        
        // 2. 이동에 따른 추가의 경우의 수 계산해보기
        int j = i+1;
        while(j < name.size() && name[j] == 'A'){ // i와 j는 A블럭(없을수도있음)을 사이에 둔 idx다.
            j++;
        }
        
        move = min(move, min(2*i + len - j, i + 2*(len-j)));
        
    }
    answer += move;
    
    return answer;
}