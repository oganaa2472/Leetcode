class Solution {
public:
    int n ;
    bool solve(int i,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(target == 0) return true;
        if(i==n-1||target<0) return false;

        if(dp[i][target]!=-1) return dp[i][target];
        
        bool include = solve(i+1,target-nums[i],nums,dp);
        bool exclude = solve(i+1,target,nums,dp);

        return dp[i][target] = include|exclude;

    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);

        if(totalSum%2==1) return false;
        int target = totalSum/2;

        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));


        return solve(0,target,nums,dp);

    }
};