#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalK = (long long)k1 + k2;
        
        // Frequency array for differences (max difference is 10^5)
        std::vector<long long> count(100001, 0);
        long long maxDiff = 0;
        long long initialDiffSum = 0;
        
        for (int i = 0; i < n; ++i) {
            int diff = std::abs(nums1[i] - nums2[i]);
            if (diff > 0) {
                count[diff]++;
                maxDiff = std::max(maxDiff, (long long)diff);
                initialDiffSum += diff;
            }
        }
        
        // If total operations can reduce everything to 0
        if (initialDiffSum <= totalK) {
            return 0;
        }
        
        // Greedily reduce differences starting from maxDiff down to 1
        for (long long i = maxDiff; i > 0 && totalK > 0; --i) {
            if (count[i] == 0) continue;
            
            // Operations needed to bring all elements at frequency count[i] down to i - 1
            long long opsNeeded = count[i];
            
            if (totalK >= opsNeeded) {
                totalK -= opsNeeded;
                count[i] = 0;
                count[i - 1] += opsNeeded;
            } else {
                // We can only partially reduce elements at level i
                count[i] -= totalK;
                count[i - 1] += totalK;
                totalK = 0;
            }
        }
        
        // Calculate the final sum of squared differences
        long long minSumSq = 0;
        for (int i = 1; i <= maxDiff; ++i) {
            if (count[i] > 0) {
                minSumSq += count[i] * (long long)i * i;
            }
        }
        
        return minSumSq;
    }
};