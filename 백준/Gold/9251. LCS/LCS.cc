// https://www.youtube.com/watch?v=n9m0RaAbhg0&t=3s
// 2차원 DP + 2차원 DP에서 점화식유도

#include <iostream>
using namespace std;

int main(){
    string a, b;
    cin >> a;
    cin >> b;
    int DP[a.length()][b.length()];

    // DP에서 점화식 적용이 안되는 i=0, j=0 부분들을 미리 채워놓기
    bool init_a{false};
    bool init_b{false};
    for(int i = 0 ; i < a.length() ; i++){
        if(a[i] == b[0] || init_a){
            DP[i][0] = 1;
            init_a = true;
        }
    }
    for(int j = 0 ; j < b.length() ; j++){
        if(b[j] == a[0] || init_b){
            DP[0][j] = 1;
            init_b = true;
        }
    }

    // 점화식을 적용하여 나머지 부분 채우기
    for(int i = 1 ; i < a.length() ; i++){
        for(int j = 1 ; j < b.length(); j++){
            if(a[i] == b[j]){
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }

    cout << DP[a.length()-1][b.length()-1] << endl;
}