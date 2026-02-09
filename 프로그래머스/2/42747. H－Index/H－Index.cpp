#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    // init
    int cnt = 0;
    int idx = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    
    // logic
    for(int h = 1000 ; h >= 0 ; h--){
        while(citations[idx] >= h){
            cnt++;
            idx++;
        }
        
        if(cnt >= h) return h;
    }
}