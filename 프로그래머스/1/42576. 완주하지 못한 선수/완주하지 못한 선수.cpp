#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> hash;
    for(int i = 0 ; i < completion.size() ; i++){
        hash[completion[i]] += 1;
    }
    
    for(int i = 0 ; i < participant.size() ; i++){
        if(hash.find(participant[i]) == hash.end()){
            answer = participant[i];
        }
        else if(hash[participant[i]] > 1){
            hash[participant[i]] -= 1;
        }
        else{
            hash.erase(participant[i]);
        }
    }
    return answer;
}