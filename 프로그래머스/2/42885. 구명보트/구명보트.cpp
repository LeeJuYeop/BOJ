// 인원제한 2명 조건을 잘 못봤다.
// 가장 무거운애 + 가능하면 가장 가벼운애 조합으로 가야 전체로 볼 때 limit에 가깝게 꽉꽉채울 수 있다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    // init
    int answer = 0;
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size() - 1;
    
    // logic
    while(left <= right){
        answer++;
        
        int tmp = limit - people[right];
        right--;
        
        if(left <= right && tmp >= people[left]){
            left++;
        }
    }
    return answer;
}