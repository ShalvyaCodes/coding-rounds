#include <vector>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Calculate the sum of the first window (first k elements)
        double currentSum = 0;
        for (int i = 0; i < k; ++i) {
            currentSum = currentSum + nums[i];
        }

        // Step 2: Initialize maxSum to the first window's sum
        double maxSum = currentSum;

        // Step 3: Slide the window across the rest of the array
        for (int i = k; i < n; ++i) {
            // Add the new element entering on the right (nums[i])
            // Subtract the old element leaving on the left (nums[i - k])
            currentSum = currentSum + nums[i] - nums[i - k];

            // Update maxSum if current window has a larger sum
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }

        // Step 4: Return the maximum average
        return maxSum / k;
    }
};