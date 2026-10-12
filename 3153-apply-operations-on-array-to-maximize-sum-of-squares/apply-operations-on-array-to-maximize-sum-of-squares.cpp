#include <vector>

class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        constexpr int MOD = 1e9 + 7;
        std::vector<int> bitCount(31, 0);

        // Step 1: Count the set bits at each position (0 to 30)
        for (int num : nums) {
            for (int i = 0; i <= 30; ++i) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }

        long long totalSumOfSquares = 0;

        // Step 2: Greedily build the k largest numbers
        for (int step = 0; step < k; ++step) {
            long long currentNum = 0;
            for (int i = 0; i <= 30; ++i) {
                if (bitCount[i] > 0) {
                    currentNum |= (1LL << i);
                    bitCount[i]--;
                }
            }
            totalSumOfSquares = (totalSumOfSquares + (currentNum * currentNum) % MOD) % MOD;
        }

        return totalSumOfSquares;
    }
};