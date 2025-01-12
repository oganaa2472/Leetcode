class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp, int k) {
        int n = coins.size();
        int m = coins[0].size();

        if (i >= n || j >= m) return INT_MIN; // Out of bounds

        if (dp[i][j][k] != INT_MIN) return dp[i][j][k];

        if (i == n - 1 && j == m - 1) { // Base case: bottom-right corner
            if (coins[i][j] >= 0)
                return dp[i][j][k] = coins[i][j];
            else
                return dp[i][j][k] = (k > 0 ? 0 : coins[i][j]);
        }

        int right = solve(i, j + 1, coins, dp, k);
        int down = solve(i + 1, j, coins, dp, k);

        int best = max(right, down);
        int current = coins[i][j];

        if (current >= 0) {
            dp[i][j][k] = best + current;
        } else {
            int pay = best + current; // Robber steals coins
            int skip = INT_MIN;
            if(k>0){
                int down1 = solve(i,j+1,coins,dp,k-1);
                int right1 = solve(i+1,j,coins,dp,k-1);
                skip = max(down1,right1);
            }
            dp[i][j][k] = max(pay, skip);
        }

        return dp[i][j][k];
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        return solve(0, 0, coins, dp, 2);
    }
};
