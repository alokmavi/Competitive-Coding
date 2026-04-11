class Solution {
  public:
    int nthTerm(int a, int d, int n) {
        // code here
        int nth = a + (n-1)*d;
        return nth;
    }
};
