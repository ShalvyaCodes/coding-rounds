#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findMaxLength(std::vector<int>& nums) {
        // Map to store the first occurrence of each running sum {sum: index}
        std::unordered_map<int, int> prefixSumMap;
        int maxLen = 0;
        int count = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Treat 0 as -1 and 1 as 1
            count += (nums[i] == 1) ? 1 : -1;
            
            // If the running sum is 0, the subarray from index 0 to i has equal 0s and 1s
            if (count == 0) {
                maxLen = i + 1;
            } 
            else {
                // If the sum has been seen before, update maxLen
                if (prefixSumMap.find(count) != prefixSumMap.end()) {
                    maxLen = std::max(maxLen, i - prefixSumMap[count]);
                } else {
                    // Otherwise, record the first time we see this sum
                    prefixSumMap[count] = i;
                }
            }
        }
        
        return maxLen;
    }
};