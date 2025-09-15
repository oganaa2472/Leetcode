class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    // Directions for moving in Up, Down, Left, Right
    vector<pair<int, int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int rows = grid.size();
    int cols = grid[0].size();
    
    queue<pair<int, int>> rottenQueue; // Queue to hold indices of rotten oranges
    int freshCount = 0; // Counter to track fresh oranges
    
    // Initialize the queue with all starting rotten oranges and count fresh oranges
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 2) {
                // Add rotten orange's position to queue
                rottenQueue.push({r, c});
            } else if (grid[r][c] == 1) {
                // Count fresh oranges
                freshCount++;
            }
        }
    }
    
    // If there are no fresh oranges, return 0 as no time is needed
    if (freshCount == 0) {
        return 0;
    }
    
    int minutes = 0; // To track the time in minutes
    
    // Perform BFS
    while (!rottenQueue.empty()) {
        int size = rottenQueue.size();
        bool rotted = false; // To track if any rotting happened in this iteration
        
        for (int i = 0; i < size; ++i) {
            auto [row, col] = rottenQueue.front();
            rottenQueue.pop();
            
            for (auto [dr, dc] : directions) {
                int newRow = row + dr, newCol = col + dc;

                // Check boundaries and that the orange is fresh
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                    // Rot the fresh orange and add its position to the queue
                    grid[newRow][newCol] = 2;
                    rottenQueue.push({newRow, newCol});
                    freshCount--;
                    rotted = true; // We have rotted at least one orange
                }
            }
        }

        // Increment minutes only if any oranges rotted in this iteration
        if (rotted) {
            minutes++;
        }
    }
    
    // If freshCount > 0, some fresh oranges could not be reached
    return (freshCount == 0) ? minutes : -1;
}
};