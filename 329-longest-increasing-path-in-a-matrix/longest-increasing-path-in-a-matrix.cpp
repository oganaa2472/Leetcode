class Solution {
public:
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    int n,m;
    bool isValid(int i,int j){
        if(i>=0&&j>=0&&i<n&&j<m){
            return true;
        }
        return false;
    }
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){

        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1;
        for(auto& dir:directions){
            int newX = i+dir[0];
            int newY = j+dir[1];
            if(isValid(newX,newY)){
                if(matrix[i][j]<matrix[newX][newY]){
                    ans = max(ans,1+solve(newX,newY,matrix,dp));
                }
            }
        }
        return dp[i][j] = ans;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int result = 0;

       
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result = max(result, solve(i, j, matrix, dp));
            }
        }
        
        return result;

    }
};