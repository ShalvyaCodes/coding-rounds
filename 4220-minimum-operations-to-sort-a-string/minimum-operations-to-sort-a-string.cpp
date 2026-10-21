#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.size();
        
        // Case 1: Already sorted
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        // Case 2: Length 2 and unsorted
        if (n == 2) {
            return -1;
        }
        
        char mn = *std::min_element(s.begin(), s.end());
        char mx = *std::max_element(s.begin(), s.end());
        
        // Find if min can be put at start or max at end in 1 operation
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        
        // Check if min/max are embedded in the interior
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
        
        // Otherwise 3 operations
        return 3;
    }
};