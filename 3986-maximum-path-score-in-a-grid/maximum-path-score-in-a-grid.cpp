class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        r = grid.size(); c = grid[0].size();
        k = min(k, r + c);
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(k + 1, -2)));
        return f(grid, 0, 0, k, dp);
    }

private:
    int r, c;
    
    int f(vector<vector<int>>& grid, int i, int j, int k, vector<vector<vector<int>>>& dp) {
        k -= grid[i][j] ? 1 : 0;
        if (k < 0) return -1;
        if (i == r - 1 && j == c - 1) {
            return grid[i][j];
        }
        if (dp[i][j][k] != -2) return dp[i][j][k];
        int res = max(i + 1 < r ? f(grid, i + 1, j, k, dp) : -1, j + 1 < c ? f(grid, i, j + 1, k, dp) : -1);
        return dp[i][j][k] = (res == -1 ? -1 : res + grid[i][j]);
    }
};