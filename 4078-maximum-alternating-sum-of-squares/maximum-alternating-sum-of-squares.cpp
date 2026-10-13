#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        int n = nums.size();
        
        
        std::vector<long long> squares(n);
        for (int i = 0; i < n; ++i) {
            squares[i] = 1LL * nums[i] * nums[i];
        }
        
        
        std::sort(squares.begin(), squares.end());
        
        
        long long score = 0;
        int mid = n / 2;
        
        for (int i = 0; i < n; ++i) {
            if (i < mid) {
                score -= squares[i]; 
            } else {
                score += squares[i];
            }
        }
        
        return score;
    }
};