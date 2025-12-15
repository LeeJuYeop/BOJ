#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    // init
    vector<int> answer;
    int i, j, k;
    
    // logic
    for(vector<int> cmd : commands){
        vector<int> v = array;
        i = cmd[0]; j = cmd[1]; k = cmd[2];
        sort(v.begin()+i-1, v.begin()+j);
        answer.push_back(v[i-1 + k - 1]);
    }
    return answer;
}