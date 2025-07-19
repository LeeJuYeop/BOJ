#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> q1;
    queue<string> q2;
    queue<string> g;
    for(int i = 0 ; i < cards1.size() ; i++){
        q1.push(cards1[i]);
    }
    for(int i = 0 ; i < cards2.size() ; i++){
        q2.push(cards2[i]);
    }
    for(int i = 0 ; i < goal.size() ; i++){
        g.push(goal[i]);
    }
    
    while(!g.empty()){
        if(g.front() == q1.front()){
            q1.pop();
            g.pop();
        }
        else if(g.front() == q2.front()){
            q2.pop();
            g.pop();
        }
        else{
            break;
        }
    }
    if(g.empty()){answer = "Yes";}
    else{answer = "No";}
    
    return answer;
}