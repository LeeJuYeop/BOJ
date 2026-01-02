// 이진탐색 응용
// 0 - 30 - 60 ... 30분에 7명 가능
// 0 - 15 - 30 ... 15분에 3명 가능
// 15 - 22 - 30 ... 22분에 5명 가능
// 22 - 26 - 30 ... 26분에 5명 가능
// 26 - 28 - 30 ... 28분에 6명 가능
// 26 - 27 - 28 ... 27분에 5명 가능.
// 27 - 27 - 28 ... 27분에 5명가능

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    // init
    sort(times.begin(), times.end());
    long long answer = 0;
    long long str = 0;
    long long end = (long long) times[times.size() - 1] * n;
    long long mid, tmp;
    
    // logic
    while(str + 1 < end){
        mid = (str + end)/2;
        tmp = 0;
        for(int i = 0 ; i < times.size() ; i++){
            tmp += mid / (long long) times[i];
        }
        
        if(tmp >= n){
            end = mid;
        }
        else if(tmp < n){
            str = mid;
        }
    }
    
    for(int i = 0 ; i < times.size() ; i++){
        tmp += str / times[i];
    }
    
    if(tmp == n) return str;
    return end;
}