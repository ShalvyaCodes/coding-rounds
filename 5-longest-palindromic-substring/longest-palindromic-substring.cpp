class Solution {
private:
    int expandAroundCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Odd length palindrome (center is i)
            int len1 = expandAroundCenter(s, i, i);
            // Even length palindrome (center is between i and i + 1)
            int len2 = expandAroundCenter(s, i, i + 1);

            int currentLen = max(len1, len2);

            if (currentLen > maxLen) {
                maxLen = currentLen;
                // Update the starting index of the longest palindrome
                start = i - (currentLen - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};