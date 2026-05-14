class Solution {
    vector<int> buildLpsArray(const vector<int>& pattern) {
        int patternLength = pattern.size();
        vector<int> lps(patternLength, 0);
        int prefixLength = 0;
        int currentIndex = 1;

        while (currentIndex < patternLength) {
            if (pattern[currentIndex] == pattern[prefixLength]) {
                prefixLength++;
                lps[currentIndex] = prefixLength;
                currentIndex++;
            } else {
                if (prefixLength != 0) {
                    prefixLength = lps[prefixLength - 1];
                } else {
                    lps[currentIndex] = 0;
                    currentIndex++;
                }
            }
        }
        
        return lps;
    }
  public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        vector<int> matchIndices;
        int textLength = a.size();
        int patternLength = b.size();

        if (patternLength == 0 || textLength < patternLength) {
            return matchIndices;
        }

        //utilizing KMP algorithm to guarantee O(N + M) time complexity and 
        //prevent worst-case performance degradation on repetitive sequences.
        vector<int> lps = buildLpsArray(b);
        
        int textIndex = 0;
        int patternIndex = 0;

        while (textIndex < textLength) {
            if (b[patternIndex] == a[textIndex]) {
                patternIndex++;
                textIndex++;
            }

            if (patternIndex == patternLength) {
                matchIndices.push_back(textIndex - patternIndex);
                patternIndex = lps[patternIndex - 1];
            } else if (textIndex < textLength && b[patternIndex] != a[textIndex]) {
                if (patternIndex != 0) {
                    patternIndex = lps[patternIndex - 1];
                } else {
                    textIndex++;
                }
            }
        }

        return matchIndices;
    }
};