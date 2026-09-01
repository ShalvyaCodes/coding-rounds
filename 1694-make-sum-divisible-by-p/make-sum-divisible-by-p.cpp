#include <vector>
#include <numeric>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int minSubarray(std::vector<int>& nums, int p) {
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int rem = totalSum % p;
        // If the total sum is already divisible by p, no need to remove anything
        if (rem == 0) return 0;
        
        // Map to store {prefix_sum_mod_p : latest_index}
        std::unordered_map<int, int> prefixToIndex;
        prefixToIndex[0] = -1;
        
        int n = nums.size();
        int ans = n;
        long long currentPrefixSum = 0;
        
        for (int i = 0; i < n; ++i) {
            currentPrefixSum += nums[i];
            int prefixMod = currentPrefixSum % p;
            
            // Calculate the target remainder we need to find in our map
            int target = (prefixMod - rem + p) % p;
            
            // If the target exists, we found a valid subarray to remove
            if (prefixToIndex.find(target) != prefixToIndex.end()) {
                ans = std::min(ans, i - prefixToIndex[target]);
            }
            
            // Record or update the latest index for the current prefix mod
            prefixToIndex[prefixMod] = i;
        }
        
        // If ans equals n, it means we would have to remove the entire array, which is not allowed
        return ans == n ? -1 : ans;
    }
};