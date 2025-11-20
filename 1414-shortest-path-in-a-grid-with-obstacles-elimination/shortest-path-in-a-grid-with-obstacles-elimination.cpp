class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Queue to store the tuple (x, y, currentObstacleEliminationCount)
        queue<tuple<int, int, int>> q;
        // A visited array tracking if a specific state has been visited: (r, c, eliminations)
        vector<vector<vector<bool>>> visited(rows, vector<vector<bool>>(cols, vector<bool>(k + 1, false)));
        
        // Start BFS
        q.push({0, 0, 0});
        visited[0][0][0] = true;
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y, eliminations] = q.front();
                q.pop();
                
                // Check if we've reached the bottom-right corner
                if (x == rows - 1 && y == cols - 1) {
                    return steps;
                }
                
                // Explore neighbors
                for (const auto& [dx, dy] : directions) {
                    int newX = x + dx;
                    int newY = y + dy;
                    
                    // Continue if new position is out of bounds
                    if (newX < 0 || newX >= rows || newY < 0 || newY >= cols) {
                        continue;
                    }
                    
                    int newEliminations = eliminations + grid[newX][newY];
                    
                    // Continue if this state is not allowed
                    if (newEliminations > k || visited[newX][newY][newEliminations]) {
                        continue;
                    }
                    
                    // Mark this state as visited and add to the queue
                    visited[newX][newY][newEliminations] = true;
                    q.push({newX, newY, newEliminations});
                }
            }
            steps++;
        }
        return -1;
    }
};