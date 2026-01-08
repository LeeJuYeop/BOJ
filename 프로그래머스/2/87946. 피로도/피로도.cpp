// 던전개수가 최대 8개라 모든 순서 경우의수가 8!개라 720 * 56 = 4만여개
// 각 경우의수마다 몇개 입장가능한지 게산.
// O(n! * n)..?

#include <string>
#include <vector>
using namespace std;

int p;
vector<vector<int>> dng;
int answer;

// 해당 경우의 수에서 입장가능한 던전 개수 반화
int calc(string& s){
    int cnt = 0;
    int k = p;
    for(int i = 0 ; i < s.size() ; i++){
        if(k >= dng[s[i] - '0'][0]){
            k -= dng[s[i] - '0'][1];
            cnt++;
        }
        else{break;}
    }
    return cnt;
}

// 순열함수
void permu(string s, int cur){
    if(cur == s.size()){
        answer = max(answer, calc(s));
        return;
    }
    
    for(int i = cur ; i < s.size() ; i++){
        swap(s[cur], s[i]);
        permu(s, cur+1);
        swap(s[cur], s[i]);
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    // init
    answer = -1;
    p = k;
    dng = dungeons;
    string s = "01234567";
    s.resize(dungeons.size());
    
    // logic
    permu(s, 0);
    
    return answer;
}