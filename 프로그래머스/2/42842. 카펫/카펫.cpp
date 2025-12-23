// 1. 갈색과 노란색 격자의 수를 합하면 전체 카펫의 넓이(size)가 나온다.
// 2. size를 w(가로) * h(세로) 로 분해한다. 이 떄 w >= h, w와 h는 자연수를 생각해서 h를 작은수부터 늘린다.
// 노랑을 갈색이 감싸는 구조려면 적어도 w, h >= 3. h 3부터 조사.
// h가 n일 때. w = size / h(n). 
// 노랑색의 개수 = (w - 2) * (n - 2) 가 맞다면 정답.

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    // init
    vector<int> answer;
    int total = brown + yellow;
    
    // logic
    for(int h = 3 ; h <= total ; h++){
        if(total % h != 0) continue;
        
        int w = total / h;
        int numOfYellow = (w-2) * (h-2);
        
        if(yellow == numOfYellow){
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }
    
    return answer;
}