#include <string>
#include <algorithm>

class Solution {
public:
    int minInsertions(std::string s) {
        int res = 0;
        int need = 0; // Number of closing parentheses ')' needed
        
        for (char c : s) {
            if (c == '(') {
                // Each '(' requires two ')'
                need += 2;
                
                // If need becomes odd, it means we had an unpaired ')' 
                // from before that we need to fix by inserting a ')'
                if (need % 2 != 0) {
                    res++;
                    need--; // We balance out that odd requirement
                }
            } else { // c == ')'
                need--;
                
                // If need drops below 0, we have an extra ')' without a '('
                if (need < 0) {
                    res++;     // Insert a '('
                    need += 2; // That inserted '(' now requires two ')'
                }
            }
        }
        
        // Add any remaining required ')'
        return res + need;
    }
};