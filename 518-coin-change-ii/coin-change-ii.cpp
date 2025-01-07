class Solution {
public:
    int dfs(int sum, vector<int>& coins, int amount, int index, vector<vector<int>>& memo) {
        // Base cases
        if (sum == amount) return 1;
        if (sum > amount || index >= coins.size()) return 0;

        // Check if the result is already computed for (sum, index)
        if (memo[sum][index] != -1) {
            return memo[sum][index];
        }

        // Option 1: Include the current coin
        int include = dfs(sum + coins[index], coins, amount, index, memo);
        
        // Option 2: Exclude the current coin
        int exclude = dfs(sum, coins, amount, index + 1, memo);

        // Store result in memo table
        memo[sum][index] = include + exclude;
        return memo[sum][index];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // Initialize memo table with -1, dimensions (amount + 1) x n
        vector<vector<int>> memo(amount + 1, vector<int>(n, -1));
        return dfs(0, coins, amount, 0, memo);
    }
};
