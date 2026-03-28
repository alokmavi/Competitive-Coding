#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    // declare the variables here
    int a = 15;
    float b = 3.25;
    double c = 13.4856;
    long long d = 582039485;

    // variables declaration checking
    if ((typeid(a) == typeid(int)) and (typeid(b) == typeid(float)) and
        (typeid(c) == typeid(double)) and (typeid(d) == typeid(long long)))
        cout << "verified\n";

    return 0;
}