class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        vector<int> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push_back(res.length());
            } else if (s[i] == ')') {
                int start = st.back();
                st.pop_back();
                reverse(res.begin() + start, res.end());
            } else {
                res += s[i];
            }
        }

        return res;
    }
};