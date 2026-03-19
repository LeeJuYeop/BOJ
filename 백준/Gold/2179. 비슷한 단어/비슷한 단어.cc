// 비슷한 단어
// 단어를 여러개 던져주고, 겹치는 접두사가 제일 많은 두 단어를 출력한다. (단, 두 단어는 달라야한다)

// 정렬 => for문으로 모든쌍비교
// 함정은 입력순서다. 접두사 겹침길이가 같은 여러 case가 존재할 때 s와 t는 입력순서가 빠른 순으로 결정한다.
// 정렬을 해버리면 입력순서가 망가져버리므로 um으로 기억해놓는다.
// 두번째 함정은 같은 s에 여러 t가 존재할 수 있다.
// for문으로 붙어있는 쌍을 비교할 때 여러 가능성의 t를 찾을 수 있어야한다.
// 예시로 정렬전 입력순서가 noonb noon noona, 정렬 후에는 noon noona noonb가 되므로
// noonb noon이 순서대로 s와 t가 되어야한다. 이를위해 정렬후인 

// set에 넣기?
// set에 넣는다. 
// 자동정렬되므로 앞과 뒤와 비교해 접두사 겹침 tmp를 계산한다
// 만약 tmp가 global_max 보다 크다면 갱신한다. 이때 s를 정하는게 관건이다.
// 같은 경우에는 입려순서가 느리므로 고려하지 않는다.

// 세번째 풀이
// 1. set에 넣어 자동정렬한다. 이 때 입력순서는 기억한다.
// 2. s를 fix하기 위해서 기억한 입력순서대로 해당문자를 찾고(find), 앞뒤와비교해 global_max를 갱신해나간다.
// 3. 2번 과정에서 s는 fix된 상태. t를 정하기 위해 s의 위치 앞뒤로 반복자를 보내서 t를 찾아낸다

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

// 접두사 중복 비교함수
int jungbok(string a, string b){
    int ret = 0;
    int idx = min(a.size(), b.size());
    for(int i = 0 ; i < idx ; i++){
        if(a[i] == b[i]) ret++;
        else break;
    }
    return ret;
}

int main(){
    // init
    int N;
    cin >> N;
    set<string> ws;     // set
    unordered_map<string, int> um;  // 입력순서 기억용 um
    vector<string> words;   // 입력순서 기억용 vector for 나중에 s 정할때
    string word, s, t;

    // logic
    for(int i = 0 ; i < N ; i++){
        cin >> word;
        ws.insert(word);
        words.push_back(word);
        if(um.find(word)==um.end()) um[word] = i;   // 중복단어인 경우 입력순서는 먼저온 순으로 기억한다.
    }

    // 2. s를 fix하기 위해서 입력순서대로 찾아가며 global_max 갱신
    int tmp; int global_max = 0;
    for(int i = 0 ; i < N ; i++){
        auto it = ws.find(words[i]);
        tmp = 0;
        if(it != ws.begin()) tmp = jungbok(*it, *prev(it));
        if(next(it) != ws.end()) tmp = max(tmp, jungbok(*it, *next(it)));

        if(tmp > global_max){
            global_max = tmp;
            s = words[i];
        }
    }

    // 3. t를 fix하기 위해서 s의 양옆으로 반복자 보내 가장 입력순서 빠른 t 찾기
    auto it = ws.find(s);
    int faster = 20001;
    for(auto rit = next(it) ; rit != ws.end() ; rit++){
        if(jungbok(*it, *rit) != global_max) break;
        
        if(um[*rit] < faster){
            t = *rit;
            faster = um[*rit];
        }
    }
    
    if(it != ws.begin()){
        auto lit = prev(it);
        while(true){
            if(jungbok(*it, *lit) != global_max) break;
            
            if(um[*lit] < faster){
                t = *lit;
                faster = um[*lit];
            }

            if(lit == ws.begin()) break;
            lit--;
        }
    }

    cout << s << endl;
    cout << t << endl;
}