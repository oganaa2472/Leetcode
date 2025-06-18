class Solution {
public:
    long long solve(int i,int flip,vector<int>& nums, vector<vector<long long>>& dp){
        if(i==nums.size()) return 0;
        if(dp[i][flip]!=-1) return dp[i][flip];
       
        if(flip==0){
           long long choose = nums[i] + solve(i+1,1,nums,dp);
           long long notChoose = nums[i] +  solve(i+1,0,nums,dp);
           return dp[i][flip] = max(choose,notChoose);
        }else{
           long long choose = -nums[i] + solve(i+1,0,nums,dp);
           return dp[i][flip] = choose;
        }
    }
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1,vector<long long>(2,-1));
        return solve(0,0,nums,dp); 
    }
};