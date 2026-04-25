class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        vector<int> stack; // Using vector as a stack
        
        for (int x : arr) {
            bool pushed = false;
            
            while (!stack.empty()) {
                int top = stack.back();
                
                // Check if signs are opposite
                if ((top > 0 && x < 0) || (top < 0 && x > 0)) {
                    if (abs(top) == abs(x)) {
                        stack.pop_back();
                        pushed = true;
                        break;
                    } else if (abs(top) > abs(x)) {
                        pushed = true;
                        break;
                    } else {
                        stack.pop_back();
                    }
                } else {
                    break;
                }
            }
            
            if (!pushed) {
                stack.push_back(x);
            }
        }
        
        return stack;
    }
};