class Solution {
    public int longestSubsequence(int[] nums) {
        int n = nums.length;
        int max = 0;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            max = Math.max(max, nums[i]);
            min = Math.min(min, nums[i]);
        }
        int maxDiff = max - min;
        int[][] dp = new int[n][maxDiff + 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= maxDiff; j++) {
                dp[i][j] = 1;
            }
        }

        int result = 0;
        for (int i = 1; i < n; i++) {
            for (int j = maxDiff - 1; j >= 0; j--) {
                dp[i - 1][j] = Math.max(dp[i - 1][j], dp[i - 1][j + 1]);
            }
            for (int j = 0; j < i; j++) {
                int diff = Math.abs(nums[i] - nums[j]);
                dp[i][diff] = Math.max(dp[i][diff], 1 + dp[j][diff]);
                result = Math.max(result, dp[i][diff]);
            }
        }
        return result;
    }

}