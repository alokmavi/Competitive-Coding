// User function template for C++

class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        // code here
        int count = 0;
        
        for(int x: arr){
            if (x == 0){
                count++;
            }
        }
        return count;
    }
};