class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int totalSum,vector<int>&nums,int i){
        if(i==nums.size()){
            return totalSum==0;
        }
        if(dp[i][totalSum]!=-1) return dp[i][totalSum];
       
        bool res = solve(totalSum,nums,i+1);
        if(totalSum-nums[i]>=0){
            res |= solve(totalSum - nums[i],nums,i+1);
        }
        return dp[i][totalSum] = res;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        int totalSum = sum/2;
        int n = nums.size();
         dp.resize(n,vector<int>(totalSum+1,-1));
        return solve(totalSum,nums,0);
    }
};