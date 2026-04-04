#include <iostream>
using namespace std;

int main() {
    // code here
    int n;
    cin >> n;
    long long bin = 0;
    long long placement = 1;
    
    while (n>0){
        int remainder = n%2;
        bin = bin + (remainder * placement);
        
        n = n/2;
        placement *= 10;
    }

    cout << bin;
    return 0;
}
