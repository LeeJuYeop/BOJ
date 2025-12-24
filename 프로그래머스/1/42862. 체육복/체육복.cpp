// OXOX가 교차될 때, 두번째 O가 앞에 빌려줘버리면 3명, 뒤에하면 4명이 된다.
// 빌릴 때 앞에서 빌리는게 최고다.
// XOXXO

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // init
    unordered_map<int, int> um;
    int answer = n;
    for(int i = 1 ; i <= n ; i++) um[i] = 1;
    for(int i = 0 ; i < reserve.size() ; i++) um[reserve[i]] += 1;
    for(int i = 0 ; i < lost.size() ; i++) um[lost[i]] -= 1;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    // logic
    for(int tar : lost){
        if(um[tar] >= 1) continue;
        if(tar-1 > 0 && um[tar-1] > 1){
            um[tar-1] -= 1;
            continue;
        }
        else if(tar +1 <= n && um[tar+1] > 1){
            um[tar+1] -= 1;
            continue;
        }
        else{
            answer--;
        }
    }
    
    
    return answer;
}