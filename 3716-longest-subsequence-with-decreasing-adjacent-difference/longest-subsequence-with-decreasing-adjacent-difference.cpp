class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(301, vector<int>(301, 0));
        int maxLength = 1;

        for (int i = n - 1; i >= 0; i--) {
            int current = nums[i];
            for (int next = 1; next <= 300; next++) {
                int difference = abs(current - next);
                dp[current][difference] = max(dp[current][difference], dp[next][difference] + 1);
            }
            for (int diff = 1; diff <= 300; diff++) {
                dp[current][diff] = max(dp[current][diff], dp[current][diff - 1]);
            }
            maxLength = max(maxLength, dp[current][300]);
        }

        return maxLength;
    }
};