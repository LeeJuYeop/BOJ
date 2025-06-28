#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    string tar, s;
    cin >> tar;

    for(int i = 0 ; i < N-1 ; i++){
        cin >> s;
        for(int j = 0 ; j < tar.length() ; j++){
            if(tar[j] != s[j]){
                tar[j] = '?';
            }
        }
    }

    cout << tar << endl;
}