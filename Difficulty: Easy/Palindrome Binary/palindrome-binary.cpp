class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        if (n == 0) return true;

        vector<int> bits;
        while (n > 0) {
            bits.push_back(n & 1);
            n >>= 1;
        }

        int left = 0;
        int right = bits.size() - 1;
        while (left < right) {
            if (bits[left] != bits[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};