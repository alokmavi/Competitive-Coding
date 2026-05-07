int findPattern(string &s, string &p) {
    // code here
    int n = s.length();
        int m = p.length();

        // If pattern is longer than the string, it cannot exist
        if (m > n) {
            return -1;
        }

        // Iterate through the string s up to the point where p can still fit
        for (int i = 0; i <= n - m; i++) {
            bool match = true;
            // Check if substring of s starting at i matches p
            for (int j = 0; j < m; j++) {
                if (s[i + j] != p[j]) {
                    match = false;
                    break;
                }
            }
            // If a match is found, return the starting index
            if (match) {
                return i;
            }
        }

        // If no match is found after checking all positions
        return -1;
}