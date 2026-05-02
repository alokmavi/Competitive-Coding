int* greaterElement(int arr[], int n) {
    // Complete the function
    vector<int> sortedArr(arr, arr + n);
    
    sort(sortedArr.begin(), sortedArr.end());
    
    int* result = new int[n];
    
    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(sortedArr.begin(), sortedArr.end(), arr[i]);
        
        // Check if such an element exists
        if (it != sortedArr.end()) {
            result[i] = *it;
        } else {
            // No greater element found
            result[i] = -10000000;
        }
    }
    
    return result;
}
