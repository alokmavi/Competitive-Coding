// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.

class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        // code here
        int n = arr.size();
        int i = 0;
        
        while (i < n) {
            if (arr[i] == x) {
                return i;
            }
            
            // Calculate the absolute difference
            int diff = abs(arr[i] - x);
            int jump = diff / k;
            if (jump == 0) jump = 1; // Ensure we move forward if diff < k
            
            i += jump;
        }
        
        return -1;
    }
};