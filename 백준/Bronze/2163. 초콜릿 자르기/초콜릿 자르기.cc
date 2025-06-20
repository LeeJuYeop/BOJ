#include <iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int ans = (N-1) + (M-1) * N;

    cout << ans << endl;
}