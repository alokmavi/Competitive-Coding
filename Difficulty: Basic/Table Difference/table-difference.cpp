#include <iostream>
using namespace std;

int main() {
    // code here
    int n1, n2;
    cin >> n1 >> n2;
    
    for (int i = 1; i <= 10; i++){
        int t1 = n1 * i;
        int t2 = n2 * i;
        cout << t1 - t2 << " ";
    }

    return 0;
}
