class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int total;
    bool solve(int i,int sum,vector<int>&nums){
        if(sum == 0) return true;
        if(i==n-1||sum<0) return false;

       
        if(dp[i][sum]!=-1) return dp[i][sum];

        int include = solve(i+1,sum-nums[i],nums);
        int exclude = solve(i+1,sum,nums);

        return dp[i][sum] = include|exclude;
    }
    bool canPartition(vector<int>& nums) {
        total = accumulate(nums.begin(),nums.end(),0);
        if(total%2==1) return false;
        n = nums.size();
        dp.resize(n,vector<int>(total,-1));
        return solve(0,total/2,nums);
    }
};