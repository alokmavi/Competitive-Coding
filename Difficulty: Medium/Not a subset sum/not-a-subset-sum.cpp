class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        if (arr.empty()) {
            return 1;
        }

        sort(arr.begin(), arr.end());

        long long smallestUnreachableSum = 1;

        for (const int currentValue : arr) {
            if (currentValue > smallestUnreachableSum) {
                break;
            }
            smallestUnreachableSum += currentValue;
        }

        return static_cast<int>(smallestUnreachableSum);
    }
};