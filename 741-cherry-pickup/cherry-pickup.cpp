class Solution {
public:
    int solve(int r1,int c1,int r2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int c2 = r1+c1-r2;
        int n = grid.size();
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

       
        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

       
        int cherries = grid[r1][c1];
        if (r1 != r2) 
                cherries += grid[r2][c2];
        int maxCherries = max({
            solve(r1 + 1, c1, r2 + 1,grid,dp), 
            solve(r1 + 1, c1, r2,grid,dp),     
            solve(r1, c1 + 1, r2 + 1,grid,dp), 
            solve(r1, c1 + 1, r2,grid,dp)      
        });

        return dp[r1][c1][r2] = cherries + maxCherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));

        return max(0,solve(0,0,0,grid,dp));

    }
};