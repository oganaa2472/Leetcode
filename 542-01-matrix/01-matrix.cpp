class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols));
        queue<pair<int, int>> q;
        
        // Initialize the distances and add all zero cells to the queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                } else {
                    dist[i][j] = INT_MAX;
                }
            }
        }
         // Define the directions for exploring adjacent cells (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int i = cell.first;
            int j = cell.second;
            for (const auto& dir : directions) {
                int r = i + dir.first;
                int c = j + dir.second;
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    if (dist[r][c] > dist[i][j] + 1) {
                        dist[r][c] = dist[i][j] + 1;
                        q.push({r, c});
                    }
                }
            }
           
        }
        return dist;
    }
};