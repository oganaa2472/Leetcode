class Solution {
public:
    vector<int> dp;
    int n ;
    int solve(int i,vector<int>& nums){
        if(i>=n-1){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int mx=1e5;
        for(int k = 1;k<=nums[i];k++){
            mx = min(mx,1+solve(i+k,nums));
        }
        return dp[i] =mx;
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        dp.resize(nums.size(),-1);        
        return solve(0,nums);
    }
};