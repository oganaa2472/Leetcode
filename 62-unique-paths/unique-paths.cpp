class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int solve(int i,int j){
        if(i>=n||j>=m) return 0;
        if(i==n-1&&j==m-1){
            return 1;
        }   
        if(dp[i][j]!=-1) return dp[i][j];
      
        return dp[i][j] =(solve(i + 1, j)+solve(i, j + 1));
    }
    int uniquePaths(int k, int k1) {
        n = k;
        m = k1;
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(0,0);
    }
};