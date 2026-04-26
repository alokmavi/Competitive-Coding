class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        vector<int> res;
        int i = 0, j = 0, k = 0;
        int n1 = a.size(), n2 = b.size(), n3 = c.size();
        
        while (i < n1 && j < n2 && k < n3) {
            if (a[i] == b[j] && b[j] == c[k]) {
                if (res.empty() || res.back() != a[i]) {
                    res.push_back(a[i]);
                }
                i++;
                j++;
                k++;
            }
            else if (a[i] < b[j]) {
                // a[i] is smaller, move i
                i++;
            }
            else if (b[j] < c[k]) {
                // b[j] is smaller (and a[i] >= b[j]), move j
                j++;
            }
            else {
                // c[k] is smaller (or a[i] >= b[j] >= c[k] but not all equal), move k
                k++;
            }
        }
        return res;
        
    }
};