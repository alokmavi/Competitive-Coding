class Solution {
  public:
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) {
        int n = a.size();
        // Store {absolute difference, index}
        vector<pair<int, int>> diff(n);
        
        for (int i = 0; i < n; ++i) {
            diff[i] = {abs(a[i] - b[i]), i};
        }
        
        // Sort by absolute difference in descending order
        sort(diff.rbegin(), diff.rend());
        
        int totalProfit = 0;
        
        for (int i = 0; i < n; ++i) {
            int idx = diff[i].second;
            int valA = a[idx];
            int valB = b[idx];
            
            // Prefer the machine with higher profit for this task
            if (valA >= valB) {
                if (x > 0) {
                    totalProfit += valA;
                    x--;
                } else {
                    // Machine A is full, must use B
                    totalProfit += valB;
                    y--;
                }
            } else {
                if (y > 0) {
                    totalProfit += valB;
                    y--;
                } else {
                    // Machine B is full, must use A
                    totalProfit += valA;
                    x--;
                }
            }
        }
        
        return totalProfit;
    }
};