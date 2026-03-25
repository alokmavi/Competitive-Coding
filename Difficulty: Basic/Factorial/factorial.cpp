class Solution {
  public:
    int factorial(int n) {
        // code here
        int value = 1;
        if (n<0){
            return 0;
        }
        if (n==0){
            return 1;
        }
        int i = 1;
        while (i <= n){
            value *= i;
            ++i;
        }
        return value;
    }
};