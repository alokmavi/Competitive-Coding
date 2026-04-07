class Solution {
  public:
    void printDivisors(int n) {
        // code here
        for (int i = 1; i <= n; i++){
            if (n%i == 0){
                cout << i << " ";
            }
        }
    }
};