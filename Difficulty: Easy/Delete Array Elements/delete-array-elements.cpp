class Solution {
  public:
    vector<int> deleteElement(vector<int>& arr, int k) {
        // complete the function
        vector<int> stack;
        
        for (int num : arr) {
            while (k > 0 && !stack.empty() && stack.back() < num) {
                stack.pop_back();
                k--;
            }
            stack.push_back(num);
        }
        
        return stack;
    }
};