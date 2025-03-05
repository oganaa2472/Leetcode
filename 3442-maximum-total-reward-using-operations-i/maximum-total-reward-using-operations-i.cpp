class Solution {
public:
    // unordered_map<string,int> dp;
    vector<int> nums;
    int n;
    int solve(int i, int sum,vector<int>&nums,vector<vector<int>>& dp){
        if(i==n) return sum;

        if(dp[i][sum]!=-1)
            return dp[i][sum];
        int exc = solve(i+1,sum,nums,dp);
        int inc = sum;
        if(sum<nums[i]){
            inc =solve(i+1,sum+nums[i],nums,dp);
        }
       return dp[i][sum] = max(inc,exc);
    }
    int maxTotalReward(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(2001,vector<int>(4001,-1));
        sort(nums.begin(),nums.end());
        return solve(0,0,nums,dp);
    }
};