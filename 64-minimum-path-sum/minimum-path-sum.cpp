class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i>=n||j>=m) return INT_MAX;
        if(i==n-1&&j==m-1){
            return grid[i][j];
        }   
      
        if(dp[i][j]!=-1) return dp[i][j];
      
        return dp[i][j] =grid[i][j] + min(solve(i + 1, j, grid),solve(i, j + 1, grid));
        
        
    }
    int minPathSum(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(0,0,grid);
    }
};