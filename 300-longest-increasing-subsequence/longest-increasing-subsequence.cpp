class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
       vector<int> dp(n+1,0);
       int ansMax=0;
       for(int i = 0;i<n;i++){
            dp[i] = 1;
            for(int k=0;k<i;k++){
                if(nums[i]>nums[k]){
                    dp[i] = max(dp[i],dp[k]+1);
                }
            }

            ansMax = max(ansMax,dp[i]);
       } 
       return ansMax;
    }
};