// User function Template for C++

bool isPrime(int num) {

    // code here to find next prime number
    // return next prime number
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false; //even numbers greater than 2 are not prime
    
    // Check for odd divisors from 3 up to sqrt(num)
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int nextPrime(int n) {
    int candidate = n + 1;
    
    while (true) {
        if (isPrime(candidate)) {
            return candidate;
        }
        candidate++;
    }
}