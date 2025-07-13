#include <iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int box[N];
    int books[M];
    for(int i = 0 ; i < N ; i++){
        cin >> box[i];
    }
    for(int i = 0 ; i < M ; i++){
        cin >> books[i];
    }

    int cnt{0};
    for(int i = 0 ; i < N ; i++){
        for(int j = cnt ; j < M ; j++){
            if(box[i] >= books[j]){
                box[i] -= books[j];
            }
            else{
                cnt = j;
                break;
            }
            if(j == M-1){i = N;}
        }
    }

    int ans{0};
    for(int i = 0 ; i < N ; i++){
        ans += box[i];
    }
    cout << ans << endl;

    return 0;
}