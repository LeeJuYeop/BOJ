#include <vector>
#include <iostream>
#include <deque>

using namespace std;

vector<int> solution(vector<int> arr){
    // init
    deque<int> dq;
    dq.push_back(arr[0]);

    // logic
    for(int i = 1 ; i < arr.size() ; i++){
        if(dq.back() == arr[i]) continue;
        
        dq.push_back(arr[i]);
    }
    
    vector<int> answer(dq.begin(), dq.end());
    
    return answer;
}