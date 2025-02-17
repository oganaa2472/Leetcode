class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp;
        dp.resize(n,1);
        for(int i = 1;i<n;i++){
            if(nums[i]>nums[i-1]){
                dp[i] = dp[i-1]+1;
            }
            // cout<<dp[i]<<" ";
        }
        int maxElement = *max_element(dp.begin(),dp.end());
        return maxElement;
    }
};