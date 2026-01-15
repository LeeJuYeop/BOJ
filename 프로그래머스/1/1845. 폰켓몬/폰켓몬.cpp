// 포켓몬 종류 = n
// 골라야할 포켓몬 수 = m
// n >= m 이면 m이고, n < m 이면 n이다.
// n구하는 건? set 혹은 map

#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums){
    // init
    int n = 0;
    int m = nums.size()/2;
    set<int> s;
    
    // logic
    for(int tmp : nums){
        s.insert(tmp);
    }
    
    n = s.size();
    
    if(n >= m) return m;
    else return n;
}