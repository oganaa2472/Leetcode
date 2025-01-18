class Solution {
public:
    int solve(int index, vector<int>& prices, int size, int buy, vector<vector<vector<int>>>& dp) {
       
        if (index >= prices.size() || size == 0) return 0;
        if (dp[index][buy][size] != -1) return dp[index][buy][size];

        if (buy) {
           
            int buyStock = -prices[index] + solve(index + 1, prices, size, 0, dp);
           
            int skip = solve(index + 1, prices, size, 1, dp);
            return dp[index][buy][size] = max(buyStock, skip);
        } else {
           
            int sellStock = prices[index] + solve(index + 1, prices, size - 1, 1, dp);
        
            int skip = solve(index + 1, prices, size, 0, dp);
            return dp[index][buy][size] = max(sellStock, skip);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        
        
        return solve(0, prices, k, 1, dp);
    }
};
