// 1562 / 2 = 781
// A로 시작하는게 781개.
// 4자리로 가능한게 781개(XXXX~UUUU)
// 4자리다 = 5 * 5 * 5 * 5 = 625
// 3자리만 = 5 * 5 * 5 = 125
// 2자리만 = 5 * 5 = 25
// 1자리만 = 5(AEIOU) = 5
// 0자리만 = XXXX = 1

// 테케4번 EIO
// 앞자리 A로시작하는 781개 재낌.
// 두번째자리 A/E 로시작하는 (125+25+5+1) * 2 = 312개 재낌
// 세번째자리 A/E/I로 시작하는 (25+5+1) * 3 = 93개 재낌
// 781 + 312 + 93 = 1093 + 93 = 1186
// 각 재낀거 후순위니까 자릿수마다 +1씩?
// 1189이어야 하는데...

// AAAE 
// 1+1+1+(6+1)

#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    // init
    int answer = 0;
    
    // logic
    vector<int> sc = {781, 156, 31, 6, 1};
    
    for(int i = 0 ; i < word.size() ; i++){
        if(word[i] == 'A'){
            answer += 1;
        }
        else if(word[i] == 'E'){
            answer += 1 + sc[i] * 1;
        }
        else if(word[i] == 'I'){
            answer += 1 + 2 * sc[i];
        }
        else if(word[i] == 'O'){
            answer += 1 + sc[i] * 3;
        }
        else if(word[i] == 'U'){
            answer += 1 + sc[i] * 4;
        }
    }
    return answer;
}