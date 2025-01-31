class Solution {
public:
    int solve(int left,int right,vector<int>&nums,vector<vector<int>>&dp){
        int n = nums.size();

        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1) return dp[left][right];

        int maxCoin = 0;
        for (int i = left; i <= right; i++) {
            int coins = nums[left-1]*nums[right+1] * nums[i];
      
            int leftCoins = solve(left,i-1, nums, dp);
            int rightCoins = solve(i+1,right, nums, dp);

            
            maxCoin = max(maxCoin, coins + leftCoins + rightCoins);
        }
        return dp[left][right] = maxCoin;

    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
         int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n-2,nums,dp);
    }
};