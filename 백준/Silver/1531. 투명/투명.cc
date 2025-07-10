// 단순히 2차원 배열과 반복문으로 풀기?
// N은 50보다 작다.
// 최악의 경우 2차원 배열 전체를 50번 돌며 연산
// 10000 * 50 = 500,000. 시간제한은 2초
// C++은 1초에 10억번 연산 가능하다고 하니 껌일듯

#include <iostream>
using namespace std;

int arr[101][101];

int main(){
    int N, M, x1, x2, y1, y2;
    cin >> N >> M;
    for(int n = 0 ; n < N ; n++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1 ; i <= y2 ; i++){
            for(int j = x1 ; j <= x2 ; j++){
                arr[i][j]++;
            }
        }
    }

    int ans{0};
    for(int i = 1 ; i < 101 ; i++){
        for(int j = 1 ; j < 101 ; j++){
            if(arr[i][j] > M){
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}