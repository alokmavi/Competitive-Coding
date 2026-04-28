class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int n = s.length();
        if (n == 0) return 0;
        
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;
        vector<int> freq(26, 0);
        
        for (int right = 0; right < n; ++right) {
            //add current character to the window
            int charIndex = s[right] - 'A';
            freq[charIndex]++;
            
            //update the maximum frequency of any single character in the current window
            maxFreq = max(maxFreq, freq[charIndex]);
            
            //check if the window is valid
            //no. of replacements needed = window_size - maxFreq
            //if replacements needed > k, shrink the window from the left
            while ((right - left + 1) - maxFreq > k) {
                int leftCharIndex = s[left] - 'A';
                freq[leftCharIndex]--;
                left++;
            }
            
            //update the maximum length
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};