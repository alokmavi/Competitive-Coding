class Solution {
  public:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<pair<int, int>> bitCountWithIndex(n);
        
        for (int i = 0; i < n; ++i) {
            bitCountWithIndex[i] = {countSetBits(arr[i]), i};
        }
        stable_sort(bitCountWithIndex.begin(), bitCountWithIndex.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.first != b.first) {
                    return a.first > b.first; // More set bits first
                }
                return a.second < b.second; // Earlier index first for stability
            });

        // Reconstruct the sorted array
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = arr[bitCountWithIndex[i].second];
        }

        return result;
    }
};