#pragma GCC optimize ("O2")

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        
        vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }
        
        for (int k : divisors) {
            bool valid = true;
            int prev_max = -1e9;
            
            for (int i = 0; i < n; i += k) {
                int L = i;
                int R = i + k - 1;
                
                int cyclic_drops = 0;
                int block_min = nums[L];
                int block_max = nums[L];
                
                for (int j = L; j <= R; ++j) {
                    block_min = min(block_min, nums[j]);
                    block_max = max(block_max, nums[j]);
                    if (j < R && nums[j] > nums[j + 1]) {
                        cyclic_drops++;
                    }
                }
                if (nums[R] > nums[L]) {
                    cyclic_drops++;
                }
                
                if (cyclic_drops > 1) {
                    valid = false;
                    break;
                }
                
                if (block_min < prev_max) {
                    valid = false;
                    break;
                }
                prev_max = block_max;
            }
            
            if (valid) {
                total_sum += k;
            }
        }
        
        return total_sum;
    }
};