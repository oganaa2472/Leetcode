class Solution {
    int mod = 1e9 + 7;

public:
    int totalSubsets(vector<int>& nums, int n, int target, vector<vector<int>>& dp) {
       
        if (target == 0) return 1; 
        if (n == 0) return 0; 
        if (dp[n][target] != -1) return dp[n][target];

      
        int skip = totalSubsets(nums, n - 1, target, dp);

        int take = 0;
        if (nums[n - 1] <= target) {
            take = totalSubsets(nums, n - 1, target - nums[n - 1], dp);
        }
        dp[n][target] = (take + skip) % mod;
        return dp[n][target];
    }

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum = (totalSum + nums[i]) % mod;
        }

        if (totalSum < 2 * k) return 0;

        int totalSubsetCount = 1;
        for (int i = 1; i <= n; i++) {
            totalSubsetCount = (totalSubsetCount * 2) % mod;
        }

        vector<vector<int>> dp(n + 1, vector<int>(k, -1));
        int invalidSubsetCount = 0;
        for (int i = 0; i < k; i++) {
            invalidSubsetCount = (invalidSubsetCount + totalSubsets(nums, n, i, dp)) % mod;
        }
        int greatPartition = (totalSubsetCount - 2 * invalidSubsetCount + mod) % mod;
        return greatPartition;
    }
};