class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        if (arr.empty()) {
            return -1; 
        }

        int leftBoundary = 0;
        int rightBoundary = arr.size() - 1;

        while (leftBoundary < rightBoundary) {
            if (arr[leftBoundary] > arr[rightBoundary]) {
                leftBoundary++;
            } else {
                rightBoundary--;
            }
        }

        return arr[leftBoundary];
    }
};