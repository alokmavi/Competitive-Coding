// User function Template for C++

// functions should slice the given string
// i.e. remove the first and the last character
// of the given string and return the sliced
// string
string sliceString(string &s) {
    // code here
    return s.substr(1, s.length() - 2);
}