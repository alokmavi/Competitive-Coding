// User function Template for C++

int nextPrime(int n) {

    // code here to find next prime number
    // return next prime number
    n++;
    while (true){
        int i;
        for (i = 2; i < n; i++){
            if (n%i == 0) break;
        }
        if (n == i){
            return n;
        }
        n++;
    }
}