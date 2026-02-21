class Solution {
public:
    int strStr(string haystack, string needle) {
        int hayLen = haystack.length();
        int needleLen = needle.length();

        if (needleLen == 0) return 0;
        if (needleLen > hayLen) return -1;

        for (int i = 0; i <= hayLen - needleLen; i++) {
            // Check if the substring starting at index 'i' matches needle
            if (haystack.substr(i, needleLen) == needle) {
                return i;
            }
        }

        return -1;
    }
};
