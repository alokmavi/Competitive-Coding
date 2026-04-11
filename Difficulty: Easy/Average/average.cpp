// User function Template for C++

int posAverage(int arr[], int size) {

    // Write your code to find average of positive numbers in arr array
    // return the answer
    int sum = 0;
    int count = 0;
    
    for (int i = 0; i < size; i++){
        if (arr[i]>=0){
            sum = sum + arr[i];
            count++;
        }
    }
    if (count == 0) return 0;
    
    return double(sum)/count;
}