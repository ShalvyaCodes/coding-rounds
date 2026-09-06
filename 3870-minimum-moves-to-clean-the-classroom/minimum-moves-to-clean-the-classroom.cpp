#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = 0, startY = 0;
        int litterCount = 0;
        vector<vector<int>> litterId(m, vector<int>(n, 0));
        
        // 1. Locate start position 'S' and index all litter items 'L'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }
        
        if (litterCount == 0) return 0;
        
        int targetMask = (1 << litterCount) - 1;
        
        // 4D Visited array: vis[x][y][energy][mask]
        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << litterCount, false)
                )
            )
        );
        
        queue<tuple<int, int, int, int>> q;
        q.push({startX, startY, energy, targetMask});
        vis[startX][startY][energy][targetMask] = true;
        
        int moves = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        // 2. BFS traversal
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; ++k) {
                auto [x, y, curEnergy, mask] = q.front();
                q.pop();
                
                if (mask == 0) {
                    return moves;
                }
                
                // Cannot make any move if energy is 0 (need at least 1 energy to step)
                if (curEnergy == 0) continue;
                
                // Try moving in all 4 directions
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (classroom[nx][ny] == 'X') continue;
                    
                    // Energy transition: costs 1 to move, resets to max if landing on 'R'
                    int nxtEnergy = (classroom[nx][ny] == 'R') ? energy : curEnergy - 1;
                    
                    if (nxtEnergy < 0) continue;
                    
                    int nxtMask = mask;
                    if (classroom[nx][ny] == 'L') {
                        int id = litterId[nx][ny];
                        nxtMask &= ~(1 << id);
                    }
                    
                    if (!vis[nx][ny][nxtEnergy][nxtMask]) {
                        vis[nx][ny][nxtEnergy][nxtMask] = true;
                        q.push({nx, ny, nxtEnergy, nxtMask});
                    }
                }
            }
            moves++;
        }
        
        return -1;
    }
};