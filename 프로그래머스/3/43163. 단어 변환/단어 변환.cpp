// 1. 단어 하나차이 = 그래프에서 서로 연결된 두 노드
// 2. BFS로 최단거리 탐색.
// 그래프 만드는게 살짝 까다롭다.

// 1. hit가지고 words돌면서 알파벳 하나다른애들 1로 기록. visit 기록
// 2. (1)에서 visit한 애들로 visit=false인 words돌면서 알파벳 하나차이 2 기록.
// 3. ...위를 반복하다가 target이 visit되면 true리턴.

#include <string>
#include <vector>
#include <queue>

using namespace std;

bool checksum(string& a, string& b){
    int sum = 0;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] == b[i]) sum++;
    }
    
    if(sum == a.size() - 1) return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    // init
    int answer = 0;
    vector<bool> visit(words.size(), false);
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    // logic
    while(!q.empty()){
        string tmp = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(tmp == target) return cnt;
        
        // words돌면서 알파벳 하나차이인 놈만 큐에넣기.
        for(int i = 0 ; i < words.size() ; i++){
            if(visit[i]) continue;
            
            if(checksum(tmp, words[i])){
                visit[i] = true;
                q.push({words[i], cnt+1});
            }
        }
    }
    
    return 0;
}