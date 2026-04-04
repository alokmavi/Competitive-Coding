class Solution {
  public:
    int binary_to_decimal(int B) {
        // Code here
        int val = 0;
        int base = 1;
        while (B > 0){
            int digit = B % 10;
            val = val + (digit * base);
            B = B/10;
            base = base * 2;
        }
        return val;
    }
};