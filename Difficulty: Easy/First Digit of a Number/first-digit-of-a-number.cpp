int firstDigit(int n) {
    n = abs (n);
    // code here
    while (n >= 10){
        n /= 10;
    }
    return n;
}