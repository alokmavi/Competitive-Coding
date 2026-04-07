#include <iostream>
using namespace std;

int main() {
    // code here
    int a, b, x;
    cin >> a >> b;
    x = min(a, b);
    for (int i = x; i >= 1; i--){
        if(a%i==0 && b%i==0){
            cout << i;
            break;
        }
    }

    return 0;
}