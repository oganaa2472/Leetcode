class Solution {
public:
    int solve(vector<int>& prices, int index, bool isBuy,vector<vector<int>>& dp) {
        
        if (index >= prices.size()) return 0;
        // I have saved already from store
        if (dp[index][isBuy] != -1) return dp[index][isBuy];

        if (isBuy) {
            // when I buy something so I can sell now
            int buy = -prices[index] + solve(prices, index + 1, 0,dp);

            // or I saved I still not buy anything
            int skip = solve(prices, index + 1, 1,dp);

            return dp[index][isBuy] = max(buy, skip);
        } else {
            // otherwhise I sell my current index
            int sell = prices[index] + solve(prices, index + 1, 1,dp);

            // or still not sell anything
            int skip = solve(prices, index + 1, 0,dp);

           
            return dp[index][isBuy] = max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, 1, dp);
    }
};
