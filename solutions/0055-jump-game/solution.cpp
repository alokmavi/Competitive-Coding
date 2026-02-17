#include <vector>
#include <algorithm> // Required for std::max

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int max_reach = 0; // Tracks the maximum index we can reach so far
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (i > max_reach) {
                return false;
            }

            max_reach = std::max(max_reach, i + nums[i]);

            if (max_reach >= n - 1) {
                return true;
            }
        }
        return true;
    }
};

