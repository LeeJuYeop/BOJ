// 1. 전체(가로 및 세로)를 순회하면서 최댓값을 찾아 가로사이즈로 정한다.
// 2. 세로사이즈는 돌리는 경우를 상정해서 전체를 순회하면서 가로/세로 중 작은쪽의 사이즈 중 최댓값으로 정한다.

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    // init
    int answer = 0;
    int width = 0; int height = 0;
    
    // logic
    // 1. 가로값 정하기
    for(int i = 0 ; i < sizes.size() ; i++){
        if(width < max(sizes[i][0], sizes[i][1])) width = max(sizes[i][0], sizes[i][1]);
    }
    
    // 2. 세로값 정하기
    for(int i = 0 ; i < sizes.size() ; i++){
        if(height < min(sizes[i][0], sizes[i][1])) height = min(sizes[i][0], sizes[i][1]);
    }
    
    return width * height;
}