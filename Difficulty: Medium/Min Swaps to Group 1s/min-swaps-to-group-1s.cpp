class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int n = arr.size();
        int totalOnes = 0;
        
        //count total number of 1s
        for (int x : arr) {
            if (x == 1) {
                totalOnes++;
            }
        }
        
        //if no 1s are present, return -1
        if (totalOnes == 0) {
            return -1;
        }
        
        //sliding window of size totalOnes
        int currentZeros = 0;
        
        //initialize the first window
        for (int i = 0; i < totalOnes; ++i) {
            if (arr[i] == 0) {
                currentZeros++;
            }
        }
        
        int minZeros = currentZeros;
        
        //slide the window
        for (int i = totalOnes; i < n; ++i) {
            //remove the element going out of the window
            if (arr[i - totalOnes] == 0) {
                currentZeros--;
            }
            //add the new element coming into the window
            if (arr[i] == 0) {
                currentZeros++;
            }
            
            //update the minimum zeros found
            minZeros = min(minZeros, currentZeros);
        }
        
        return minZeros;
    }
};