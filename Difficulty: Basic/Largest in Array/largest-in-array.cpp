class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int MaxVal = arr[0];
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] > MaxVal){
                MaxVal = arr[i];
            }
        }
        return MaxVal;
    }
};
