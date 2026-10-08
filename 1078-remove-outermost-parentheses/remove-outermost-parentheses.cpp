#include <string>

class Solution {
public:
    std::string removeOuterParentheses(std::string s) {
        std::string result = "";
        int opened = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (opened > 0) {
                    result += c;
                }
                opened++;
            } else {
                opened--;
                if (opened > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};