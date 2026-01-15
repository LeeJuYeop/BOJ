// 경우의 수 문제로 풀 수 있다.
// 어떤카테고리의상이든 0개/1개/2개....를 입을 수 있다.
// 카테고리 4개가 2/1/1/1개의 의상이 있을 때
// 3 * 2 * 2 * 2 = 24개의 경우의 수가 있다.
// 여기서 코니는 최소 한 개의 의상을 입기때문에 모두 안입는 경우 1을 빼주면 23가지다.
// 테케1번도 모자2종류/안경1종류 니까 3 * 2 - 1 = 5.

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    // init
    int answer = 0;
    unordered_map<string, int> um;
    
    // logic
    for(auto cloth : clothes){
        um[cloth[1]]++;
    }
    
    // 경우의 수 계산
    for(pair<string,int> tmp : um){
        if(answer == 0) answer = tmp.second+1;
        else answer *= (tmp.second+1);
    } answer --;    // 모두안입는 경우 제외.
    
    return answer;
}