// 모든 경우의수를 um에 등록한다. target을 검색해서 답으로 출력.
// 경우의수 = O(2^N)(최대 2^20 = 1000000 백만)
// 분할정복 : 마지막부호가 +인경우와 -인경우로 분할 <--- 백만개 함수스택...시간초과

// 함수 스택없이 해보기
// BFS? DFS? DFS가 역류 없을 것 같다.
// 1. 정렬한번 때리기 : 1 1 2 4 <-----필요없을 듯?
// 2. 자료형 : {다음idx, 현재까지합, 다음idx부호?}
// 3. {0,0,0} 넣고 시작.
// 4-1. idx가 numbers.size()초과 시 정답검사
// 4-2. idx가 numbers.size()이하 시 다음idx부호에 맞게 현재합조정 후 다음idx++로 가기

#include <string>
#include <vector>
#include <stack>

struct st{
    int cur;
    int idx;
};

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    stack<st> stk;
    stk.push({0,0});
    
    while(!stk.empty()){
        st tmp = stk.top(); stk.pop();
        
        if(tmp.idx == numbers.size()){
            if(tmp.cur == target) answer++;
            continue;
        }
        
        stk.push({tmp.cur + numbers[tmp.idx], tmp.idx+1});
        stk.push({tmp.cur - numbers[tmp.idx], tmp.idx+1});
    }
    
    return answer;
}