class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n = arr.size();
        long long totalSum = 0;

        //iterate through each bit position (0 to 31)
        for (int i = 0; i < 32; ++i) {
            int cnt = 0; //count of numbers with i-th bit set
            
            // Count set bits at position i
            for (int num : arr) {
                if ((num >> i) & 1) {
                    cnt++;
                }
            }
            
            //no. of pairs with different bits at position i
            long long pairs = (long long)cnt * (n - cnt);
            
            // Contribution = pairs * 2^i
            totalSum += pairs * (1LL << i);
        }

        return totalSum;
    }
};