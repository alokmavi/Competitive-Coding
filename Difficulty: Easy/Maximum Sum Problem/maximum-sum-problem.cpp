class Solution {
    unordered_map<int, int> memoizationCache;
  public:
    int maxSum(int n) {
        // code here.
        if (n <= 0) {
            return 0;
        }

        if (memoizationCache.count(n)) {
            return memoizationCache[n];
        }

        int fractionalSum = maxSum(n / 2) + maxSum(n / 3) + maxSum(n / 4);
        int optimalResult = max(n, fractionalSum);

        memoizationCache[n] = optimalResult;
        return optimalResult;
    }
};