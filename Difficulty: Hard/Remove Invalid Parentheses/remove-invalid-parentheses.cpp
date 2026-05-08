#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
  public:
    // Helper to check if a string is valid
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

    vector<string> validParenthesis(string &s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;
        
        // Start BFS with the original string
        q.push(s);
        visited.insert(s);
        
        bool found = false; // Flag to stop adding more levels once valid strings are found

        while (!q.empty()) {
            int size = q.size();
            // Process all strings at the current level (same number of removals)
            for (int i = 0; i < size; ++i) {
                string current = q.front();
                q.pop();

                if (isValid(current)) {
                    result.push_back(current);
                    found = true;
                }

                // If we already found valid strings at this level, 
                // we don't need to generate the next level (more removals)
                if (found) continue;

                // Try removing one parenthesis at each position
                for (int j = 0; j < current.length(); ++j) {
                    // Only remove parentheses
                    if (current[j] != '(' && current[j] != ')') continue;

                    // Form the new string by removing the character at index j
                    string nextStr = current.substr(0, j) + current.substr(j + 1);

                    if (visited.find(nextStr) == visited.end()) {
                        visited.insert(nextStr);
                        q.push(nextStr);
                    }
                }
            }
            // If we found valid strings in this level, break to avoid processing deeper levels
            if (found) break;
        }

        // Sort the result lexicographically
        sort(result.begin(), result.end());
        return result;
    }
};