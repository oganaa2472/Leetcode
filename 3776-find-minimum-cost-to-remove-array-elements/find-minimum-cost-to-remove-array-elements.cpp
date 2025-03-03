class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
        if(i == nums.size()) return nums[j];
        if(i == nums.size()-1) return max(nums[i], nums[j]);
        if(dp[i][j]!=-1) return dp[i][j];
        
        

        
        int op1 = max(nums[i],nums[i+1]) + solve(i+2,j,nums,dp);
        int op2 = max(nums[j],nums[i+1])+ solve(i+2,i,nums,dp);
        int op3 = max(nums[j],nums[i])+solve(i+2,i+1,nums,dp);
        return dp[i][j] = min({op1,op2,op3});
    }
    int minCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return solve(1,0,nums,dp);
    }
};