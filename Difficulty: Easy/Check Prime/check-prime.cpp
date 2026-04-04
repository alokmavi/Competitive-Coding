#include <iostream>
using namespace std;

int main() {
    // code here
    int n;
    cin >> n;
    if (n == 0 || n == 1){
        cout << "Neither prime nor composite";
        return 0;
    }
    
    for (int i = 2; i*i <= n; i++){
        if (n%i == 0){
            cout << "False";
            return 0;
        }
    }
    cout << "True";

    return 0;
}
