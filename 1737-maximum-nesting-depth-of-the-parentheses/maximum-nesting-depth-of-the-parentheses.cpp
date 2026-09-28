class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                count++;
                if (count > ans) {
                    ans = count;
                }
            } else if (s[i] == ')') {
                count--;
            }
        }
        
        return ans;
    }
};