#include <vector>
#include <string>

class Solution {
    int memo[100][100][101]; // memo[r][c][balance]

    bool dfs(int r, int c, int balance, const std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Update current balance
        balance += (grid[r][c] == '(' ? 1 : -1);

        // Invalid state: negative balance
        if (balance < 0) return false;

        // Balance cannot exceed half the total path length
        int totalPathLen = m + n - 1;
        if (balance > totalPathLen / 2) return false;

        // Base case: Reached the bottom-right cell
        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }

        // Return cached result if already visited
        if (memo[r][c][balance] != -1) {
            return memo[r][c][balance];
        }

        bool result = false;

        // Move Down
        if (r + 1 < m) {
            result = result || dfs(r + 1, c, balance, grid);
        }

        // Move Right
        if (!result && c + 1 < n) {
            result = result || dfs(r, c + 1, balance, grid);
        }

        return memo[r][c][balance] = result;
    }

public:
    bool hasValidPath(std::vector<std::vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Path length is odd -> impossible to balance
        if ((m + n - 1) % 2 != 0) return false;

        // First cell cannot be ')'
        if (grid[0][0] == ')') return false;

        // Initialize memoization array with -1
        std::memset(memo, -1, sizeof(memo));

        return dfs(0, 0, 0, grid);
    }
};