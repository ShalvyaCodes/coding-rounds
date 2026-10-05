#include <string>

class Solution {
public:
    int scoreOfParentheses(std::string s) {
        int score = 0;
        int depth = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                // Check if this closing parenthesis forms a core "()"
                if (s[i - 1] == '(') {
                    score += (1 << depth); // Equivalent to 2^depth
                }
            }
        }
        
        return score;
    }
};