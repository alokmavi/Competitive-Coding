// User function Template for C++

void difference(int n1, int n2) {

    // Write your code here
    int diff = n1 - n2;
    
    // Loop from 1 to 10 to print the first 10 multiples of the difference
    for (int i = 1; i <= 10; ++i) {
        cout << i * diff;
        
        // Print a space after the number, but not after the last one
        if (i < 10) {
            cout << " ";
        }
    }
}