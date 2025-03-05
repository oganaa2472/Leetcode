class Solution {
public:
    vector<vector<int>> dp;
    vector<int> nums;
    int n;
    int solve(int i, int sum,vector<int>&nums){
        if(i==n) return sum;

        if(dp[i][sum]!=-1)
            return dp[i][sum];
        int exc = solve(i+1,sum,nums);
        int inc = sum;
        if(sum<nums[i]){
            inc =solve(i+1,sum+nums[i],nums);
        }
       return dp[i][sum] = max(inc,exc);
    }
    int maxTotalReward(vector<int>& nums) {
        n = nums.size();
        dp.assign(2001,vector<int>(4001,-1));
        sort(nums.begin(),nums.end());
        return solve(0,0,nums);
    }
};