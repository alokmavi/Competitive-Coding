// User function Template for C++

// Function to swap two objects **obj1 and **obj2
void swapper(Person **obj1, Person **obj2) {
    // Your code here
    Person* temp = *obj1;
    *obj1 = *obj2;
    *obj2 = temp;
}
