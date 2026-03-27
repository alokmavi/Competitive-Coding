class Solution {
  public:
    string booleanOperations(bool a, bool b) {
        // Code here
        ostringstream res;
        res << boolalpha;
        res << (a && b) << " " << (a || b) << " " << (!a);
        
        return res.str();
    }
};
