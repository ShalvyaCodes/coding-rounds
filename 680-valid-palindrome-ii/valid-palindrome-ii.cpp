#include <string>

class Solution {
private:
    // Helper function to check if a substring is a palindrome
    bool checkPalindrome(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                // Try skipping either the left or the right character
                return checkPalindrome(s, left + 1, right) || checkPalindrome(s, left, right - 1);
            }
        }

        return true;
    }
};