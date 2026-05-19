class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        if (start == end) {
            return 0;
        }
        
        if (arr.empty()) {
            return -1;
        }

        const int MOD_VALUE = 1000;
        
        // Defensive check: If the target is outside the modulo space, it's mathematically unreachable.
        if (end < 0 || end >= MOD_VALUE) {
            return -1;
        }

        vector<int> minimumSteps(MOD_VALUE, -1);
        queue<int> traversalQueue;

        int initialNode = start % MOD_VALUE;
        minimumSteps[initialNode] = 0;
        traversalQueue.push(initialNode);

        while (!traversalQueue.empty()) {
            int currentValue = traversalQueue.front();
            traversalQueue.pop();
            
            int currentSteps = minimumSteps[currentValue];

            for (const int multiplier : arr) {
                // Cast to long long prevents integer overflow if multiplier elements are arbitrarily large.
                int nextValue = (1LL * currentValue * multiplier) % MOD_VALUE;

                if (nextValue == end) {
                    return currentSteps + 1;
                }

                if (minimumSteps[nextValue] == -1) {
                    minimumSteps[nextValue] = currentSteps + 1;
                    traversalQueue.push(nextValue);
                }
            }
        }
        
        return -1;
    }
};