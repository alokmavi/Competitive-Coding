class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n,0);
        for(int i=0; i<n; i++)
        {
            freq[nums[i]]++;
            if(freq[nums[i]]>1)
            return nums[i];
        }
        return -1;
    }
};
