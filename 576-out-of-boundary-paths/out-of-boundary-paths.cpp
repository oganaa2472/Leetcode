class Solution {
public:
    int MOD = 1e9 + 7;
    int m, n;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int mo) {
        
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 1;

       
        if (mo == 0)
            return 0;

      
        if (dp[i][j][mo] != -1)
            return dp[i][j][mo];

        
        int ans = 0;
        ans = (ans + solve(i + 1, j, mo - 1)) % MOD;
        ans = (ans + solve(i - 1, j, mo - 1)) % MOD;
        ans = (ans + solve(i, j + 1, mo - 1)) % MOD;
        ans = (ans + solve(i, j - 1, mo - 1)) % MOD;

        return dp[i][j][mo] = ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        dp.assign(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return solve(startRow, startColumn, maxMove);
    }
};
