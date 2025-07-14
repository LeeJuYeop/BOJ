#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int T;
    string n;
    cin >> T;
    for(int i = 0 ; i < T ; i++){
        cin >> n;
        int pow_n = pow(stoi(n), 2);
        int d = pow(10, n.length());
        if((pow_n - stoi(n)) % d == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}