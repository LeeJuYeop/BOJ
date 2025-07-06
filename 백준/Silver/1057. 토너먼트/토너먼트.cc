// 12 34 56 78 910 1112 1314 1516
// 8->4, 9->5
// 12 34 56 78
// 4->2, 5->3
// 12 34
// 2->1, 3->2
// 12
// 16 = 16 8 4 2 1

// 나누기 2씩한다
// if() 더작은수가 홀수 && 더큰수가짝수 && 둘의 차이가 1)
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N;
    int a, b;
    cin >> N >> a >> b;
    if(a > b){
        int c = a;
        a = b;
        b = c;
    }
    
    for(int i = 0 ; i < log2(N)+1 ; i++){
        if(a%2 == 1 && b%2 == 0 && b-a == 1){
            cout << i+1 << endl;
            return 0;
        }
        if(a%2==0){a /= 2;}
        else{a = a/2 + 1;}
        if(b%2==0){b /= 2;}
        else{b = b/2 + 1;}
    }
}