class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
       int n = nums.size();       
       vector<int> dp(n+1,1);

       for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) dp[i] = dp[i+1]+1; 
       }
       int answer = 0;
       for(int i =0;i<n-k;i++){
        if(dp[i]>=k&&dp[i+k]>=k) return true;
       }
      return false;
    }
};