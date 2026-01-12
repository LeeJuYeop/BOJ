// 앞자리부터 큰수로 가야한다.
// "4177252841"
// 테케3에서 k=4이므로 앞자리 후보는 4 1 7 7 
// 77252841
// 두번쨰자리 찾기위해 두번째7부터 남은 k=2로 시작. 7 2. 그대로 감
// 2 5 2 <- 앞 2빼기
// 7752841
// 2 8 <- 2제거
// 775841

// 119876
// k = 5
// 9876 / k = 3
 

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    // init
    int cur = 0;
    int p = 0; int pnum = -1;
    string answer = "";
    
    // logic
    while(k > 0 && number.size() - cur > k){
        for(int i = cur ; i <= cur + k ; i++){   // k개의 수 중 최댓값 찾기
            if(number[i] - '0' > pnum){
                p = i;
                pnum = number[i] - '0';
            }
        }
        
        answer += number[p];
        k -= (p-cur);
        cur = p + 1;
        pnum = -1;
    }
    
    if(k == 0){
        answer += number.substr(cur, number.size());   
    }
    
    return answer;
}