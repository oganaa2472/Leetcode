class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int totalSum = sum / 2;
        int n = nums.size();
        vector<bool> dp(totalSum+1, false);
        dp[0] = true; // base case

        for(int num : nums){
            for(int j = totalSum; j >= num; j--){
                dp[j] = dp[j] || dp[j-num];
            }
        }

        return dp[totalSum];
    }
};