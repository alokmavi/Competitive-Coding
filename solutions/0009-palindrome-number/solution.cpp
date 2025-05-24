class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long reverse = 0;
        int p = x;
        while(p)
        {
            reverse = reverse*10 + p%10;
            p = p/10;
        }
        return (reverse==x);
    }
};
