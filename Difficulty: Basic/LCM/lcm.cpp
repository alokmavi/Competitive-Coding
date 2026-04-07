// User function Template for C++

int LCM(int a, int b) {

    // write your code here
    int start = max(a, b);
    int end = a*b;
    
    for (int i = start; i <= end; i++){
        if (i%a==0 && i%b==0){
            return i;
        }
    }
    // return LCM of a and b
}