// User function Template for C++

class Solution {
  public:
    // Function to insert all elements of the array in deque.
    deque<int> insertInDq(vector<int>& arr) {
        // add your code here
        deque<int> dq;
        
        for (int x: arr){
            dq.push_back(x);
        }
        return dq;
    }
};