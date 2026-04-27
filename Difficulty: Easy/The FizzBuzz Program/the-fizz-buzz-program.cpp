class Solution {
  public:
    void fizzBuzz(int number) {
        // code here.
        // Check if divisible by both 3 and 5 first
        if (number % 3 == 0 && number % 5 == 0) {
            cout << "FizzBuzz" << endl;
        }
        // Check if divisible by 3
        else if (number % 3 == 0) {
            cout << "Fizz" << endl;
        }
        // Check if divisible by 5
        else if (number % 5 == 0) {
            cout << "Buzz" << endl;
        }
        // If not divisible by either, print the number itself
        else {
            cout << number << endl;
        }
    }
};