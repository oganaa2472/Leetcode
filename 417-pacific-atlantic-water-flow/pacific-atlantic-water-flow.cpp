class Solution {
private:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& reachable) {
        int numRows = heights.size();
        int numCols = heights[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int r = cell.first, c = cell.second;
            reachable[r][c] = true;
            
            for (const auto& dir : dirs) {
                int newRow = r + dir.first, newCol = c + dir.second;
                if (newRow < 0 || newRow >= numRows || newCol < 0 || newCol >= numCols) continue;
                if (reachable[newRow][newCol]) continue;
                if (heights[newRow][newCol] < heights[r][c]) continue;
                
                q.push({newRow, newCol});
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int numRows = heights.size();
        int numCols = heights[0].size();
        
        vector<vector<bool>> pacificReachable(numRows, vector<bool>(numCols, false));
        vector<vector<bool>> atlanticReachable(numRows, vector<bool>(numCols, false));
        
        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;
        
        for (int i = 0; i < numRows; i++) {
            pacificQueue.push({i, 0});
            atlanticQueue.push({i, numCols - 1});
        }
        
        for (int j = 0; j < numCols; j++) {
            pacificQueue.push({0, j});
            atlanticQueue.push({numRows - 1, j});
        }
        
        bfs(heights, pacificQueue, pacificReachable);
        bfs(heights, atlanticQueue, atlanticReachable);
        
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (pacificReachable[i][j] && atlanticReachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};