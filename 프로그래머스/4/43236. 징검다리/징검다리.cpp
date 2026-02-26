// 0 2 11 14 17 21 25
// 2 9 3 3 4 4

// 단순한 접근
// 1. 두 바위사이의 거리가 가장 가까운 경우를 찾는다. <- n
// 2. 왼쪽 혹은 오른쪽 중 작은 것과 합친다.
// 3. n번 1-2를 반복한다 = O(n).
// 4. 남은 거리 중 최소를 리턴한다.

// 이분탐색
// 거리최솟값을 1 - 13 - 25로 둘 때 처리해야할 돌 개수를 센다.
// 거리최솟값을 13으로 둘 때, 2/9/11/14/17 모두를 없애야하므로 5. 주어진 n보다 크므로 1-13으로
// 1 - 7 - 13 : 거리최솟값으로 7을 둘 때 2/14/17/21을 없애 11만 남겨야 가능하다.4개 제거해야하므로 4. n보다 크므로
// 1 - 4 - 7 : 거리최솟값으로 4를 둘 때 2/14를 없애서 11 17 21만 남겨야 가능. 2개 제거하므로 2. n과 같아졌으므로 좁혀보기
// 4 - 5 - 7 : 거리최솟값으로 5를 둘 때 2/14/21을 없애서 11 17만 남겨야 가능. 3개 제거하므로 n보다 커짐.
// 4 - 4 - 5 

// 1 - 13 - 25
// 1 - 6 - 12
// 1 - 3 - 5
// 4 - 4 - 5
// 5 - 5 - 5

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    // init
    int answer = 0;
    int left = 1;
    int right = distance;
    int mid, prev, tmp, cnt;
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    // logic
    while(left <= right){
        mid = (left+right)/2;
        prev = 0; cnt = 0;
        
        // 빼야될 돌 개수 세기
        for(int i = 1 ; i < rocks.size() ; i++){
            tmp = rocks[i];
            if(tmp - prev < mid) cnt++;
            else prev = tmp;
        }
        
        // cnt에 따라 left와 right 조정
        if(cnt > n){
            right = mid - 1;
        }
        else if(cnt <= n){
            answer = mid;
            left = mid + 1;
        }
    }
    
    return answer;
}