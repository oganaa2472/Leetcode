class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // DFS to mark guarded cells
    void dfs(vector<vector<int>>& grid, int r, int c, int dirX, int dirY) {
        // Check boundaries or stopping conditions (wall, another guard, or already guarded)
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || 
            grid[r][c] == 1 || grid[r][c] == 2 ) {
            return;
        }
        
        grid[r][c] = 3; // Mark as guarded
        
        // Continue in the same direction
        dfs(grid, r + dirX, c + dirY, dirX, dirY);
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> area(m, vector<int>(n, 0));
        
        // Mark walls
        for (auto& wall : walls) {
            area[wall[0]][wall[1]] = 1;
        }
        
        // Mark guards
        for (auto& guard : guards) {
            area[guard[0]][guard[1]] = 2;
        }
        
        // Perform DFS from each guard in all 4 directions
        for (auto& guard : guards) {
            int x = guard[0];
            int y = guard[1];
            for (int i = 0; i < 4; i++) {
                dfs(area, x + directions[i][0], y + directions[i][1], directions[i][0], directions[i][1]);
            }
        }
        
        // Count unguarded cells
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (area[i][j] == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
