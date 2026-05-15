class Solution {
  public:
    int optimalKeys(int n) {
        // code here
        if (n <= 0) {
            return 0;
        }

        if (n <= 6) {
            return n;
        }

        vector<long long> optimalCharacterCount(n + 1, 0);

        for (int keystrokeIndex = 1; keystrokeIndex <= 6; ++keystrokeIndex) {
            optimalCharacterCount[keystrokeIndex] = keystrokeIndex;
        }

        for (int totalKeystrokes = 7; totalKeystrokes <= n; ++totalKeystrokes) {
            // Evaluate all valid historical states where we could have executed Ctrl-A -> Ctrl-C.
            // We start iterating from totalKeystrokes - 3 to account for the buffer allocation keys.
            for (int bufferSourceIndex = totalKeystrokes - 3; bufferSourceIndex >= 1; --bufferSourceIndex) {
                
                long long pasteMultiplier = totalKeystrokes - bufferSourceIndex - 1;
                long long candidateMax = optimalCharacterCount[bufferSourceIndex] * pasteMultiplier;
                
                optimalCharacterCount[totalKeystrokes] = max(optimalCharacterCount[totalKeystrokes], candidateMax);
            }
        }

        return optimalCharacterCount[n];
    }
};