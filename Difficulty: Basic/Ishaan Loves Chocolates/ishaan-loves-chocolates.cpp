class Solution {
  public:
    int chocolates(int n, vector<int> &arr) {
        // code here
        int left = 0;
        int right = n - 1;
        while (left < right) {
            if (arr[left] >= arr[right]) {
                left++;        //eats left square
            } else {
                right--;       //eats right square
            }
        }

    return arr[left];  
    }
};
