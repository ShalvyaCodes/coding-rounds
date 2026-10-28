class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[j][x] = whether XOR value x can reach
        // the current cell in column j.
        vector<bitset<1024>> dp(n);

        // Start with the first cell.
        dp[0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                bitset<1024> reachable;

                // From the cell above.
                if (i > 0) {
                    reachable |= dp[j];
                }

                // From the cell on the left.
                if (j > 0) {
                    reachable |= dp[j - 1];
                }

                // XOR the current cell's value.
                bitset<1024> next;

                for (int x = 0; x < 1024; x++) {
                    if (reachable[x]) {
                        next[x ^ grid[i][j]] = 1;
                    }
                }

                dp[j] = next;
            }
        }

        // Find the smallest XOR reachable at the destination.
        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x])
                return x;
        }

        return -1;
    }
};