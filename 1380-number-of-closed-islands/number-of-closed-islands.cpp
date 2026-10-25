#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base case: check bounds and whether the cell is water (1)
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 1) {
            return;
        }
        
        // Mark the current land cell as visited by turning it into water (1)
        grid[r][c] = 1;
        
        // Traverse all 4 directions (up, down, left, right)
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Step 1: Sink all land cells (0s) connected to the boundaries
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j] == 0) {
                    dfs(grid, i, j);
                }
            }
        }
        
        // Step 2: Count the remaining closed islands in the interior
        int closedIslandsCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    closedIslandsCount++;
                    dfs(grid, i, j); // Sink the entire closed island
                }
            }
        }
        
        return closedIslandsCount;
    }
};