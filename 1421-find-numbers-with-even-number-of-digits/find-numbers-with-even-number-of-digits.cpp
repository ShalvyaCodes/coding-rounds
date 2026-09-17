#include <vector>
#include <string>

class Solution {
public:
    int findNumbers(std::vector<int>& nums) {
        int evenDigitCount = 0;

        for (int num : nums) {
            // Convert number to string to easily check its length (number of digits)
            int digitCount = std::to_string(num).length();
            
            // Check if the number of digits is even
            if (digitCount % 2 == 0) {
                evenDigitCount++;
            }
        }

        return evenDigitCount;
    }
};