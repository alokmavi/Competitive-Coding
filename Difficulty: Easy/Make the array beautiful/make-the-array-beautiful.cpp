class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        if (arr.empty()) {
            return {};
        }

        vector<int> beautifulSequence;
        beautifulSequence.reserve(arr.size()); 

        for (const int currentNumber : arr) {
            if (beautifulSequence.empty()) {
                beautifulSequence.push_back(currentNumber);
                continue;
            }

            bool isCurrentNegative = currentNumber < 0;
            bool isTopNegative = beautifulSequence.back() < 0;

            if (isCurrentNegative != isTopNegative) {
                beautifulSequence.pop_back(); 
            } else {
                beautifulSequence.push_back(currentNumber);
            }
        }

        return beautifulSequence;
    }
};