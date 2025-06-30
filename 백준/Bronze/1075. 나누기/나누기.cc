#include <iostream>
using namespace std;

int main(){
    int n, f;
    cin >> n >> f;
    int n2 = n / 100;
    n2 = n2 * 100;
    int a = n2 % f;
    if(a == 0){
        cout << "00" << endl;
        return 0;
    }

    int b = f - a;
    if(b < 10){
        cout << '0';
    }
    cout << b << endl;

    return 0;
}