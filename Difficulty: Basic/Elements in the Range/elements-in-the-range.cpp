class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        if (start > end) {
            return false; 
        }

        int requiredCount = end - start + 1;
        int foundCount = 0;

        for (const int currentElement : arr) {
            if (currentElement >= start && currentElement <= end) {
                foundCount++;
            }
        }

        return foundCount == requiredCount;
    }
};
