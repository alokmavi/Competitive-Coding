class Solution {
  public:
    int* decrementArrayElements(int arr[], int size) {
        // Code here
        for (int i = 0; i < size; i++){
            arr[i] = arr[i] - 1;
        }
        return arr;
    }
};