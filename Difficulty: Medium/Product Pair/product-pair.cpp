class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        if (arr.size() < 2) {
            return false;
        }

        unordered_set<long long> visitedElements;
        visitedElements.reserve(arr.size());

        for (const int currentFactor : arr) {
            if (currentFactor == 0) {
                if (target == 0 && !visitedElements.empty()) {
                    return true;
                }
            } else {
                if (target % currentFactor == 0) {
                    long long requiredComplement = target / currentFactor;
                    if (visitedElements.find(requiredComplement) != visitedElements.end()) {
                        return true;
                    }
                }
            }
            
            visitedElements.insert(currentFactor);
        }

        return false;
    }
};