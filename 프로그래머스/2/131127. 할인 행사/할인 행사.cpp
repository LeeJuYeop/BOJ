// discount배열에서 열흘치를 unordered_map에 상품명:수량 으로 저장한다
// unoredred_map(열흘 동안의 할인상품들)이 want:number보다 풍족한지 보고 answer+=1;
// discount가 10만길이, wand가 최대 10개의 서로다른품목이니까 10만 * 10 = 100만번 연산. 충분
// 시간복잡도는 O(N*M)인데, M(최대10)은 N(최대십만)에 비해 작으므로 O(N)으로 봐도 무방

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool check(vector<string> &want, vector<int> &number, unordered_map<string, int> &h){
    for(int i = 0 ; i < want.size() ; i++){
        if(h[want[i]] < number[i]){
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    // 해시 초기화
    unordered_map<string, int> h;
    for(int i = 0 ; i < want.size() ; i++){
        h[want[i]] = 0;
    }
    for(int i = 0 ; i < 10 ; i++){
        h[discount[i]] += 1;
    }
    
    // 열흘치 검사 및 슬라이싱범위 바꾸기(+1일) 반복
    for(int i = 0 ; i < discount.size()-10 ; i++){
        if(check(want, number, h)){
            answer += 1;
        }
        
        h[discount[i]] -= 1;
        h[discount[i+10]] += 1;
    }
    
    if(check(want, number, h)){ // 마지막 슬라이싱(마지막 열흘)에 대해서 체크
            answer += 1;
    }
    
    
    
    
    return answer;
}