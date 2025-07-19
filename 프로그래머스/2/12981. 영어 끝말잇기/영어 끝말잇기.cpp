#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    unordered_map<string, int> hash;
    
    for(int i = 0 ; i < words.size() ; i++){
        // 1. 끝말잇기 잘 됐는지 검사.
        if((i > 0) && (words[i-1][words[i-1].size()-1] != words[i][0])){
            answer[0] = (i+1) % n != 0 ? (i+1) % n : n;
            answer[1] = ceil( (double)(i+1) / n);
            break;
        }
        
        // 2. 중복인지 검사 
        if(hash.find(words[i]) == hash.end()){
            hash[words[i]] = 1;
        }
        else{
            answer[0] = (i+1) % n != 0 ? (i+1) % n : n;
            answer[1] = ceil( (double)(i+1) / n);
            break;
        }
    }
    

    return answer;
}