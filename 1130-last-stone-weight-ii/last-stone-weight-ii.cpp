class Solution {
public:
    int n ;
    int totalSum;
    int target;
    int solve(int i,int target,int sum,vector<int>&nums,vector<vector<int>>& dp){
        if (sum >= target or i == nums.size()-1)
            return abs(sum-(totalSum-sum));
        if (dp[i][sum] != -1){
            return dp[i][sum];
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int ans = INT_MAX;
        int include = solve(i+1,target,sum+nums[i],nums,dp);

        int exclude = solve(i+1,target,sum,nums,dp);

        return dp[i][sum] = min(include,exclude);

    }
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        totalSum = accumulate(stones.begin(),stones.end(),0);
        target = totalSum/2;
        vector<vector<int>> dp(n,vector<int>(totalSum,-1));
        return solve(0,target,0,stones,dp);
    }
};