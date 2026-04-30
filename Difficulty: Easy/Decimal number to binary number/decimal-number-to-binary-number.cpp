// User function Template for C++

string toBinary(int n) {
    // Your code here
    // Handle the case for 0 explicitly
    if (n == 0) return "0";
        
    string binary = "";
        
    while (n > 0) {
        int remainder = n % 2;
        binary += to_string(remainder);
        n = n / 2;
    }
        
    // reverse the string to get the correct binary representation
    reverse(binary.begin(), binary.end());
        
    return binary;
}