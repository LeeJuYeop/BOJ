// 1. string 슬라이싱해서 조합만들기 = 조합

// 2. 소수인지 판별하기 : 에라토네스의 체
// 해당 2 ~ 해당 수의 제곱근까지 나누어 떨어지는 수 있으면 소수아님.

// 제곱근 + string 입력이 그냥 파이썬문제네;

#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

bool func(int n){
    if(n < 2) return false;
    if(n == 2) return true; // 2면 true 반환.
    
    int m = sqrt(n);
    for(int i = 2 ; i <= m ; i++){
        if(n % i == 0) return false;
    }
    return true;
}

void combi(unordered_set<string>& v, string s, int depth, int end){
    if(depth == end){
        if(s[0] == '0') return;   // 문자열 앞이 0이라면 무시(ex 011 은 11취급 )
        v.insert(s.substr(0,depth));
        return;
    }
    
    for(int i = depth ; i < s.size() ; i++){
        char tmp = s[depth]; s[depth] = s[i]; s[i] = tmp;
        combi(v, s, depth+1, end);
        tmp = s[depth]; s[depth] = s[i]; s[i] = tmp;
    }
}

int solution(string numbers) {
    // init
    int answer = 0;
    unordered_set<string> v;
    
    // logic
    for(int i = 1 ; i <= numbers.size() ; i++){
        // 1. 길이가 i인 숫자 집합 만들기
        v.clear();
        combi(v, numbers, 0, i);
    
        // 2. 길이가 i인 숫자 집합에서 소수 찾아 ans++;
        for(string s : v){
            if(func(stoi(s))) answer++;
        }
    }
    
    return answer;
}

// 0 1 10 11 101 110