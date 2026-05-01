class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        vector<int> result;
        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int x : arr) {
            pq.push(x);
            
            // If heap size exceeds k, remove the smallest element
            if (pq.size() > k) {
                pq.pop();
            }
            
            // If we have fewer than k elements, the Kth largest doesn't exist
            if (pq.size() < k) {
                result.push_back(-1);
            } else {
                // The top of the min-heap is the Kth largest element
                result.push_back(pq.top());
            }
        }
        
        return result;
    }
};