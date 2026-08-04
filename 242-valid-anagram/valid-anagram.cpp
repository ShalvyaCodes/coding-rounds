#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // Step 1: Base condition - lengths must match
        if (s.length() != t.length()) {
            return false;
        }

        // Step 2: Create a frequency array for 26 lowercase English letters
        std::vector<int> count(26, 0);

        // Step 3: Count frequencies
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        // Step 4: Verify all frequencies are zero
        for (int c : count) {
            if (c != 0) {
                return false;
            }
        }

        return true;
    }
};