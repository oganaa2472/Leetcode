class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int minX = n, maxX = -1, minY = m, maxY = -1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    minX = min(minX, i);
                    maxX = max(maxX, i);
                    minY = min(minY, j);
                    maxY = max(maxY, j);
                }
            }
        }

        // No 1s found
        if (maxX == -1) return 0;

        int height = maxX - minX + 1;
        int width = maxY - minY + 1;
        return height * width;
    }
};
