class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int n = s.length();
        int left = 0;
        int minLen = INT_MAX;
        int count = 0; //count of unique characters (0, 1, 2) present in the window
        
        vector<int> freq(3, 0);
        
        for (int right = 0; right < n; ++right) {
            int charIndex = s[right] - '0';
            
                // if character wasn't present in the current window, increment count
            if (freq[charIndex] == 0) {
               count++;
            }
            freq[charIndex]++;
            
            //window contains all three characters
            while (count == 3) {
                //update minimum length
                int currentLen = right - left + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                }
                
                //shrink the window from the left
                int leftCharIndex = s[left] - '0';
                freq[leftCharIndex]--;
            
                //if count of this character drops to 0, we no longer have all 3
                if (freq[leftCharIndex] == 0) {
                       count--;
                   }
                left++;
            }
        }
        
        return (minLen == INT_MAX) ? -1 : minLen;
    }
};
