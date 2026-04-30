class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        //the last non-leaf node is at index (n/2) - 1
        for (int i = 0; i <= (n / 2) - 1; ++i) {
            int leftChildIndex = 2 * i + 1;
            int rightChildIndex = 2 * i + 2;
            
            //check left child
            if (leftChildIndex < n && arr[i] < arr[leftChildIndex]) {
                return false;
            }
            
            //right child
            if (rightChildIndex < n && arr[i] < arr[rightChildIndex]) {
                return false;
            }
        }
        
        return true;
    }
};
