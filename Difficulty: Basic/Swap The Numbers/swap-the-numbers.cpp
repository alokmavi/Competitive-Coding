#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    // Write Code to Swap
    int c = a;
    a = b;
    b = c;

    cout << a << " " << b << endl;
    return 0;
}