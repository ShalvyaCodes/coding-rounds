#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        auto it = std::find(nums.begin(), nums.end(), 0);
        int zero = std::distance(nums.begin(), it);
        
        auto check = [&](int step) -> bool {
            for (int i = 1; i < n; i++) {
                int prev = (zero + (i - 1) * step + n) % n;
                int curr = (zero + i * step + n) % n;
                if (nums[prev] > nums[curr]) {
                    return false;
                }
            }
            return true;
        };
        
        int ans = INT_MAX;
        
        // Check for normal forward order
        if (check(1)) {
            ans = std::min(ans, zero);
            ans = std::min(ans, n - zero + 2);
        }
        
        // Check for reverse order
        if (check(-1)) {
            ans = std::min(ans, zero + 2);
            ans = std::min(ans, n - zero);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};