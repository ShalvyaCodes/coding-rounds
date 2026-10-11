#include <vector>

class Solution {
public:
    int sumOfSquares(std::vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        
        // Loop through the 0-indexed C++ vector
        for (int i = 0; i < n; ++i) {
            // The 1-based index is (i + 1)
            int oneBasedIndex = i + 1;
            
            // Check if it divides n evenly
            if (n % oneBasedIndex == 0) {
                totalSum += nums[i] * nums[i];
            }
        }
        
        return totalSum;
    }
};