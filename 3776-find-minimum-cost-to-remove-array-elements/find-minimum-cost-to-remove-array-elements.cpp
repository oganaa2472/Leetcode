class Solution {
public:
    int solve(int ext, int ind, vector<int>& nums, vector<vector<int>> &dp){
       
        if(ind == nums.size()) return nums[ext];

       
        if(ind == nums.size()-1) return max(nums[ext], nums[ind]);

        if(dp[ind][ext] != -1) return dp[ind][ext];

      
        int f = max(nums[ind], nums[ind+1]) + solve(ext, ind+2, nums, dp);
        int s = max(nums[ext], nums[ind+1]) + solve(ind, ind+2, nums, dp);
        int t = max(nums[ext], nums[ind]) + solve(ind+1, ind+2, nums, dp);

  
        return dp[ind][ext] = min({f, s, t});
    }

    int minCost(vector<int>& nums) {
        int n = nums.size();

      
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, 1, nums, dp);
    }
};