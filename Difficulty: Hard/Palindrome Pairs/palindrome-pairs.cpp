class Solution {
public:
    bool isPalindrome(const string& s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
    
    bool palindromePair(vector<string>& arr) {
        unordered_map<string, int> strMap;
        for (int i = 0; i < arr.size(); i++) {
            strMap[arr[i]] = i;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            string s = arr[i];
            int len = s.length();
            
            for (int j = 0; j <= len; j++) {
                string left = s.substr(0, j);
                string right = s.substr(j);
                
                // Case 1
                if (isPalindrome(left)) {
                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());
                    if (strMap.count(revRight) && strMap[revRight] != i) {
                        return true;
                    }
                }
                
                // Case 2
                if (j < len && isPalindrome(right)) {
                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());
                    if (strMap.count(revLeft) && strMap[revLeft] != i) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};