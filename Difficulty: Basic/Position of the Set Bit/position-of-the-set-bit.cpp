class Solution {
  public:
    int findPosition(int n) {
        // code here
        if (n > 0 && (n & (n - 1)) == 0) {
            int position = 0;
            while ((n & 1) == 0) {
                n >>= 1;
                position++;
            }
            return position + 1;
        }
        return -1;
    }
};